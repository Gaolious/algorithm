#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
pii operator - (pii a, pii b) {
    return {a.first - b.first, a.second - b.second};
}
pii operator + (pii a, pii b) {
    return {a.first + b.first, a.second + b.second};
}
pii rotate( pii a ) {
    return {-a.second, a.first};
}
pii extend(pii a, pii b) {
    // a-b
    auto ret = a-b;
    return rotate(ret) + b;
}
void process(int Case) {
    vector<pii> p(4);
    for (auto &[x, y]: p) cin >> x >> y ;

    std::sort(p.begin(), p.end());

    for ( int i = 1 ; i < 3 ; i ++ ) {
        vector<pii> p2 = {p[0], p[i]};
        p2.push_back(extend(p2[0], p2[1]));
        p2.push_back(extend(p2[1], p2[2]));
        std::sort(p2.begin(), p2.end());
        if ( p == p2 ) {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
