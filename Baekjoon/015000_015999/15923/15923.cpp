#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    int n, x, y;
    pii a, b;
    int ans;
    cin >> n  ;
    ans = 0;
    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> x >> y;
        if ( i == 0 ) a = b = {x, y};
        a.first = min(a.first, x);
        b.first = max(b.first, x);
        a.second = min(a.second, y);
        b.second = max(b.second, y);
    }
    b.first -= a.first;
    b.second -= a.second;
    cout << (b.first+b.second)*2 << '\n';
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
