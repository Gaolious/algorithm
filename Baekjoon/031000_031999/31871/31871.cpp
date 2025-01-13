#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){
}
void process(int Case) {
    int N, M, i, a, b, c;
    ll dist, ans;

    cin >> N >> M;
    vector C(N+1, vector<int>(N+1, -1));
    vector<int> perm(N+2, 0);
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b >> c;
        C[a][b] = max(C[a][b], c);
    }

    for ( i = 1 ; i <= N ; i ++ ) perm[ i ] = i ;

    ans = -1;
    do {
        for ( dist=0, i = 0 ; i <= N ; i ++ ) {
            auto t = C[ perm[i] ][ perm[i+1] ];
            if ( t >= 0 )
                dist += t;
            else {
                dist = -1;
                break;
            }
        }
        ans = max(ans, dist);
    } while (next_permutation(perm.begin()+1, perm.end()-1));

    cout << ans << '\n';
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
