#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
const int MOD = 900'528 ;
void process(int Case) {
    ll M[256]={0,};
    ll i, b, base, ans, m;
    string s;
    cin >> s ;
    base = s.size();
    for ( i = 0 ; i < s.size() ; i ++ ) M[ s[i] ] = i+1;

    cin >> s ;
    reverse(s.begin(), s.end());
    for (i = 0, b=1, ans = 1 ; i < s.size() ; i ++, b = b*base % MOD ) {
        ans = (ans + M[s[i]] * b ) % MOD;
    }

    cout << ( ans + MOD - 1 ) % MOD << '\n';
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
