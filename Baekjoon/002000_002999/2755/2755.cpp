#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int n, a;
    ll b, c, t;
    string s;
    cin >> n ;

    b = t = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> s >> a >> s ;
        c = ( s[0] <= 'D' ) ? ('E' - s[0])*10 : 0;
        if ( s.size() > 1 ) {
            if ( s[1] == '+' ) c += 3;
            if ( s[1] == '-' ) c -= 3;
        }
        b += c*a;
        t += a;
    }
    t*=10;
    cout << b / t << '.';
    b %= t;
    b = (b * 1000) / t;
    b += (b % 10 >= 5) ? 10 : 0;
    b/=10;
    cout << setw(2) << setfill('0') << b;
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
