#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int w, h, i, j, n, a, b;
    cin >> w >> h ;
    vector<int> X={0, w}, Y={0, h};
    cin >> n ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> a >> b ;
        if ( a == 0 ) Y.push_back(b);
        else X.push_back(b);
    }
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());
    for ( w=0, i = 1 ; i < X.size() ; i ++ )
        w = max(w, X[i]-X[i-1]);
    for ( h=0, i = 1 ; i < Y.size() ; i ++ )
        h = max(h, Y[i]-Y[i-1]);

    cout << w *h ;
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
