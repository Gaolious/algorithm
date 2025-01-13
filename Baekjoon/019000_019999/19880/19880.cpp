#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    string s ;
    int N, ans = 0, i, j ;
    cin >> s ;
    N = s.size() ;

    for ( i = 0 ; i*2+1 < N ; i ++ ) {
        if ( i+1 < N-i-1) {
            ans += s[0] != '0' && s[i+1] != '0' ? 1 : 0;
        }
        else {
            if ( s[0] != '0' && s[i+1] != '0' ) {
                int t = 0;
                for ( j = 0 ; j <= i ; j ++ ) {
                    if ( s[j] < s[i+1+j]) {t=-1; break;}
                    if ( s[j] > s[i+1+j]) {t=1; break;}
                }
                if (t<=0) ans ++;
            }
        }
    }
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
