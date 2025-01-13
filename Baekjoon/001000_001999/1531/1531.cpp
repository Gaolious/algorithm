#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
int A[101][101];
void process(int Case) {
    int N, M, sx, sy, ex, ey;
    int i, j, cnt=0;
    cin >> N >> M ;
    while ( N -- ) {
        cin >> sx >> sy >> ex >> ey ;
        for ( i = sy ; i <= ey ; i ++ )
            for ( j = sx ; j <= ex ; j ++ )
                if ( A[i][j]++ == M ) cnt++;

    }
    cout << cnt << '\n';
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
