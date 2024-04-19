#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[8][8];
int C[8][8];
int MaxDir[] = { 0, 4, 2, 4, 4, 1 };
struct Data {
    int y, x, t;
};
int Y, X;
vector<Data> CCTV;
int best;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
void spread(int idx, int d, int add) {
    int i, ty, tx;
    for ( i = 1 ; i < 8 ; i ++ ) {
        ty = CCTV[idx].y + dy[d]*i ;
        tx = CCTV[idx].x + dx[d]*i ;
        if ( ty < 0 || tx < 0 || ty >= Y || tx >= X ) return;
        if ( A[ty][tx] == 6) return;
        C[ty][tx] += add;
    }
}
void cctv(int idx, int d, int add ) {
    switch (CCTV[idx].t) {
        case 1 :
            spread(idx, d, add);
        break;
        case 2 :
            spread(idx, d, add);
            spread(idx, (d+2)%4, add);
        break;
        case 3 :
            spread(idx, d, add);
            spread(idx, (d+1)%4, add);
        break;
        case 4 :
            spread(idx, d, add);
            spread(idx, (d+1)%4, add);
            spread(idx, (d+2)%4, add);
        break;
        case 5 :
            spread(idx, d, add);
            spread(idx, (d+1)%4, add);
            spread(idx, (d+2)%4, add);
            spread(idx, (d+3)%4, add);
        break;
    }
}

void F(int idx) {
    if ( idx >= CCTV.size() ) {
        int i, j;
        int ret = 0 ;
        for ( i = 0 ; i < Y ; i ++ ) {
            for (j = 0 ; j < X ; j ++ ) {
                if ( A[i][j] == 0 && C[i][j] == 0 )
                    ret ++;
            }
        }
        best = min(best, ret);
        // cout << "Best = " << best << '\n';
        // for ( i = 0 ; i < Y ; i ++ ) {
        //     for (j = 0 ; j < X ; j ++ ) {
        //         cout << C[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        return ;
    }

    for ( int d = 0 ; d < MaxDir[CCTV[idx].t] ; d ++ ) {
        cctv(idx, d, 1);
        F(idx+1);
        cctv(idx, d, -1);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    cin >> Y >> X ;
    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> A[ i ][ j ] ;
            if ( A[ i ][ j ] > 0 && A[i][j] < 6 ) {
                CCTV.push_back({i, j, A[i][j]});
            }
        }
    best = Y*X;
    F(0);
    cout << best ;

    return 0;
}


