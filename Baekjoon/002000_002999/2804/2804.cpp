#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int has[127], i, j;
    string a, b;
    cin >> a >> b ;
    memset(has, -1, sizeof(has));
    for ( i = 0 ; i < b.size() ; i ++ )
        if ( has[ b[i] ] < 0 ) has[ b[i] ] = i ;

    vector<string> ans( b.size() , string(a.size(), '.'));
    for ( i = 0 ; i < a.size() ; i ++ ) {
        if ( has[ a[i] ] != -1 ) {
            ans[ has[ a[i] ] ] = a;
            for ( j = 0 ; j < b.size() ; j ++ ) ans[j][i] = b[j];
            for (auto &s: ans ) cout << s << '\n';
            return;
        }
    }
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
