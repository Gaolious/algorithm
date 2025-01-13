#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

void init(){
}
void process(int Case) {
    int nDay, K ;
    int i, price ;
    cin >> nDay >> K ;
    priority_queue<pii, vector<pii>, greater<>> Q;
    ll ans ;
    vector<int> Cnt(nDay, 0);
    ans = 0 ;

    for ( i = 0 ; i < nDay ; i ++ ) {
        cin >> price;
        Q.emplace(price, i);

        while ( Q.top().second + K <= i )
            Q.pop();
        ans += Q.top().first * 2;
        Cnt[ Q.top().second ]+=2;
    }

    cout << ans << '\n';
    for ( auto n:  Cnt) cout << n  << ' ';
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
