#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
bool is(string &s, int &sIdx, int N, int digit) {
    while ( digit >= 1 ) {
        if ( sIdx >= s.size() ) return false;
        if ( (N/digit) + '0' != s[sIdx]) return false;
        sIdx++;
        N %= digit;
        digit /= 10;
    }
    return true;
}
void process(int Case) {
    string s ;
    cin >> s ;

    int i, digit = 1, idx = 0 ;
    int ans = -1;

    for ( i = 1 ; ; i ++ ) {
        if ( i >= digit*10 ) digit*=10;
        ans = is(s, idx, i, digit ) ? i : -1;
        if ( ans < 0 ) break;
        if ( idx >= s.size() ) break;
    }
    cout << ans ;
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
