#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<string> A = {
        "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};
int T[127];
int G[127];
void init(){
    int g = 1 ;
    for ( auto &s: A) {
        for ( int i = 0 ; i < s.size() ; i ++ ) {
            T[s[i]] = i;
            G[s[i]] = g;
        }
        g++;
    }
}
void process(int Case) {
    int p, w, ans=0, prevG=-1;
    string s;
    cin >> p >> w ;
    cin.ignore();
    while(getline(cin, s) && !s.empty() ) {
        for (auto c: s) {
            if ( c == ' ' ) ans += p;
            else
                ans += p * (1 + T[c]) + (prevG == G[c] ? w : 0);
            prevG = G[c];
        }
    }
    cout << ans;
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
