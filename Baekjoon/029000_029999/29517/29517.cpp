#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}

ll P2(ll N) {
    ll a, b, ans;
    ans = 0 ;
    for (a=2 ; a <= N ; a *= 2 ) {
        for ( b = 1 ; a*b <= N ; b *=3 ) ans ++;
    }
    return ans;
}
void process(int Case) {
    ll N;
    cin >> N ;
    cout << P2(N);
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
