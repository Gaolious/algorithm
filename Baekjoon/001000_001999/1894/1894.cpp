#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<long double, long double> pdd;
void init(){
}
long double eps=1.0e-12;
bool operator == (pdd a, pdd b) {
    return ( abs(a.first-b.first) < eps && abs(a.second - b.second) < eps );
}
pdd operator - (pdd a, pdd b) {
    return {a.first-b.first, a.second-b.second};
}
pdd operator + (pdd a, pdd b) {
    return {a.first+b.first, a.second+b.second};
}
pdd operator / (pdd a, ld n) {
    return {a.first/n, a.second/n};
}
void process(int Case) {
    ld a, b, c, d, e, f, g, h;
    int i, j;
    while ( cin >> a >> b >> c >> d >> e >> f >> g >> h ) {
        vector<pdd> p = { { a, b }, { c, d }, { e, f }, { g, h }};
        pdd s = {0, 0}, ret;
        for (i=0 ; i < 4 ; i ++ )
            s = s + p[i];

        for (i=0 ; i < 2 ; i ++ )
            for ( j = 2 ; j < 4 ; j ++ )
                if ( p[i] == p[j] )
                    ret = s - p[i] - p[i] - p[j];
        cout << fixed << setprecision(3) << ret.first << ' ' << ret.second << '\n';
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
