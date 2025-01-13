#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

struct POS {
    int idx[2][2];
    void FlipX() {
        for ( int i = 0 ; i < 2 ; i ++ )
            swap(idx[i][0], idx[i][1]);
    }
    void FlipY() {
        for ( int i = 0 ; i < 2 ; i ++ )
            swap(idx[0][i], idx[1][i]);
    }
    void Rot(int d) {
        if ( d == 1 ) // CCW
            FlipX();
        else // CW
            FlipY();
        swap(idx[0][1], idx[1][0]);
    }
    void command(int k) {
        if ( k == 1 ) FlipY();
        else if ( k == 2 ) FlipX();
        else if ( k == 3 ) Rot(-1);
        else if ( k == 4 ) Rot(1);
    }
};
int N;
vector<vector<int>> mat;
vector<vector<int>> ans;
vector<POS> Pos;

void output(int idx, int len, int sy, int sx, int y, int x) {
    if ( idx >= 1 ) {
        int m = len / 2 ;
        int i, j;
        for ( i = 0 ; i < 2 ; i ++ ) {
            for ( j = 0 ; j < 2 ; j ++ ) {
                int yp = Pos[idx].idx[i][j]/2;
                int xp = Pos[idx].idx[i][j]%2;
                output(idx-1, m, sy+i*m, sx+j*m, y + yp*m, x+xp*m);
            }
        }
        return;
    }
    ans[sy][sx] = mat[y][x];
}
void process(int Case) {
    int M, K, L;
    int i, j, len;
    cin >> N >> M ;
    len = 1 << N;

    mat.resize(len, vector<int>(len));
    ans.resize(len, vector<int>(len));
    for ( i = 0 ; i < len ; i ++ )
        for ( j = 0 ; j < len ; j ++ )
            cin >> mat[i][j];

    Pos.resize(N+1, {0, 1, 2, 3});

    while ( M -- ) {
        cin >> K >> L ;
        if ( K <= 4 ) {
            for ( i = 1 ; i <= L ; i ++ )
                Pos[i].command(K);
        }
        else if ( K <= 8 ) {
            for ( i = N ; i > L ; i -- )
                Pos[i].command(K-4);
        }
        else continue;
    }
    output(N, len, 0, 0, 0, 0);

    for ( i = 0 ; i < len ; i ++ ){
        for ( j = 0 ; j < len ; j ++ ) {
            if ( j ) cout << ' ';
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
