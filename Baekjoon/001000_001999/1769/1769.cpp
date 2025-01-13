#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int n, cnt = 0 , k;
    string s ;
    cin >> s ;
    if ( s.size() > 1 ) {
        cnt = 1;
        n = 0 ;
        for(auto c: s ) n += c-'0';
        while ( n >= 10 ) {
            for ( k = 0 ; n > 0 ; n /= 10 ) k += n % 10 ;
            cnt++;
            n = k;
        }
    }
    else {
        cnt = 0 ;
        n = s[0] - '0';
    }

    cout << cnt << '\n';
    if ( n % 3 == 0 ) cout << "YES";
    else cout << "NO";
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
