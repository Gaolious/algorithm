#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
int dy[] = {0, 1, 0, -1, 0};
int dx[] = {1, 0, -1, 0, 0};

vector<vector<ld>> dist(5, vector<ld>(5));
const ld INF = 20'000'000;
void init(){
    int i, j;
    for (i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 5 ; j ++ )
            dist[i][j] = sqrt( (dx[i]-dx[j])*(dx[i]-dx[j]) + (dy[i]-dy[j])*(dy[i]-dy[j]) );
}
int getP(char c){
    if ( c == 'R' ) return 0;
    else if ( c == 'U' ) return 1;
    else if ( c == 'L') return 2;
    else if ( c == 'D' ) return 3;
    else return 4;
}

ld D[2][5][5];
void process(int Case) {
    int i, n, p1, p2;
    int l, r, curr, prev;
    char c;
    int N;

    cin >> N;
    curr=0, prev=1-curr;
    for ( l = 0 ; l < 5 ; l ++ )
        for ( r = 0 ; r < 5 ; r ++ )
            D[prev][l][r] = INF;
    D[prev][4][4] = 0;

    for (i = 0 ; i < N ; i ++ ) {
        cin >> n;

        for ( l = 0 ; l < 5 ; l ++ )
            for ( r = 0 ; r < 5 ; r ++ )
                D[curr][l][r] = INF;

        if ( n == 1 ) {
            cin >> c;
            p1 = getP(c);
            for ( l = 0 ; l < 5 ; l ++ ) {
                for (r = 0; r < 5; r++) {
                    D[curr][p1][r] = min( D[curr][p1][r], D[prev][l][r] + dist[l][p1]);
                    D[curr][l][p1] = min( D[curr][l][p1], D[prev][l][r] + dist[r][p1]);
                }
            }
        }
        else {
            cin >> c;
            p1 = getP(c);
            cin >> c;
            p2 = getP(c);
            for ( l = 0 ; l < 5 ; l ++ ) {
                for (r = 0; r < 5; r++) {
                    D[curr][p1][p2] = min( D[curr][p1][p2], D[prev][l][r] + dist[l][p1] + dist[r][p2]);
                    D[curr][p2][p1] = min( D[curr][p2][p1], D[prev][l][r] + dist[l][p2] + dist[r][p1]);
                }
            }
        }
        if ( i != N-1)
            swap(prev, curr);
    }

    ld ans = INF ;
    for (l = 0 ;l < 5 ;l ++ )
        for (r = 0; r < 5; r++)
            ans = min(ans, D[curr][l][r]);
    cout << setprecision(18) << fixed << ans;
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
