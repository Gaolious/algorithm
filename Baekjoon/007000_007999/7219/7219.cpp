#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, M ;
    int i ;
    int t, dest;
    cin >> N ;
    vector<int> D(N+1);
    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> D[ i ] ;
        D[i] += D[i-1];
    }
    cin >> M ;
    vector<int> Limit(N+1, -1);
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> dest >> t ;
        if ( Limit[ dest ] < 0 || Limit[ dest ] > t )
            Limit[ dest ] = t;
    }

    int lastCity = 0;
    for ( i = 1 ; i <= N ; i ++ ) {
        if ( Limit[i] < 0 ) continue;
        if ( Limit[i] < D[i]) {
            cout << "-1\n";
            return;
        }
        lastCity = i;
    }

    cout << D[lastCity] * 2 << '\n';
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
