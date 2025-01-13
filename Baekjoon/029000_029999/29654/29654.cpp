#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define bet(a,b,c) ( (a) <= (b) && (b) <= (c) )
void init(){
}
void process(int Case) {
    int N=10 ;
    int DF, MF, FW, d, m, f;
    vector<pair<ll,ll>> A(N);
    DF = MF = FW = 0;
    for (auto &[x,y]: A) {
        cin >> x >> y ;
        if ( x < 40 ) DF++;
        else if ( x < 80 ) MF ++;
        else FW++;
    }

    vector<string> ans;
    for ( int i = -2 ; i <= 2 ; i ++ ) {
        for ( int j = -2 ; j <= 2 ; j ++ ) {
            d = DF + i;
            m = MF - i - j ;
            f = FW + j;

            if ( bet(1,d,5) && bet(1,m,5) && bet(0,f,3) ) {
                stringstream iss("");
                iss << d << '-' << m << '-' << f ;
                ans.push_back(iss.str());
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto &s: ans) cout << s << '\n';
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
