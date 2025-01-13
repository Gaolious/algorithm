#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1};
void init(){
}
char A[1000][1001];
char B[1000][1001];
void process(int Case) {
    int N, i, j, d, ty, tx, cnt ;
    cin >> N ;
    for (auto &s: A) cin >> s ;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( A[i][j] != '.' ) B[i][j] = '*';
            else {
                cnt = 0 ;
                for (d = 0; d < 8; d++) {
                    ty = i + dy[d];
                    tx = j + dx[d];
                    if (ty < 0 || tx < 0 || ty >= N || tx >= N) continue;
                    if (A[ty][tx] != '.') cnt += A[ty][tx] - '0';
                }
                B[i][j] = ( cnt >= 10 ) ? 'M' : (char)('0' + cnt);
            }
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        cout << B[i] << '\n';
    }
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
