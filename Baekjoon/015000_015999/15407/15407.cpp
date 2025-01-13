#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

void init(){}
void process(int Case) {
    ll N, area ;
    cin >> N >> area;
    vector<pll> A(N);
    for (auto &[v,a] : A) cin >> v >> a ;
    std::sort(A.begin(), A.end(), [](pll &a, pll &b){
        return a.first > b.first;
    });
    ll ans = 0;
    for (auto [v, a]: A) {
        ans += v * min(area, a);
        area = max(0ll, area - a);
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
