#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;

struct Fenwick {
	vector<ll> T;
	void init(int n) {
		T.resize(n+1);
	}
	ll sum(int i) {
		ll ans = 0;
		while (i > 0) {
			ans += T[i];
			i -= (i & -i);
		}
		return ans;
	}
	void update(int i, ll diff) {
		while (i < T.size()) {
			T[i] += diff;
			i += (i & -i);
		}
	}
};


void process() {
	int N, n ;
	int i, j;
	int l, r, m, v;
	Fenwick fw;

	cin >> N ;
	fw.init(N);
	;
	vector<ll> ans(N+1);
	for ( i = 2 ; i <= N ; i ++ ) fw.update(i, 1);

	for ( i = 1 ; i <= N ; i ++ ) {
		cin >> n ;
		l = 1, r = N, v = N ;
		while ( l <= r ) {
			m = ( l + r ) / 2;
			if ( fw.sum(m) >= n ) {
				r = m - 1;
				v = min(m, v);
			}
			else {
				l = m + 1;
			}
		}
		ans[ v ] = i ;
		fw.update(v, -1);
	}
	for ( i = 1 ; i <= N ; i ++ )
		cout << ans[i] << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


