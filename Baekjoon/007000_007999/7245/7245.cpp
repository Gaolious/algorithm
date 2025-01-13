#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, M, i, j, leadT, v, minT ;
    cin >> M >> N ;

    vector<int> ans(M);
    vector<int> t(M);
    vector<int> endTime(M, 0);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> leadT >> v ;
        for ( j = 0 ; j < M ; j ++ )
            cin >> t[j];

        minT = -1;
        for ( j = 0 ; j < M ; j ++ ) {
            if ( endTime[j] > leadT) continue;
            if ( minT < 0 || t[minT] > t[j] ) minT = j;
        }
        if ( minT >= 0 ) {
            ans[minT] += v;
            endTime[minT] = leadT + t[minT];
        }
    }
    for ( i = 0 ; i < M ; i ++ ) {
        cout << ans[ i ] << ' ';
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
