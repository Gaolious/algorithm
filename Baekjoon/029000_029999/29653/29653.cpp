#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    int N;
    int i, j;

    cin >> N ;
    vector<pll> A(N);
    ld ans = -1, t;
    for (auto &[x,v]: A) cin >> x >> v;
    std::sort(A.begin(), A.end(), greater<>());

    for ( i = 0 ; i < N-1 ; i ++ ) {
        for (j = i+1; j < N; j++) {
            if (A[i].second >= A[j].second) continue;
            if (A[i].first <= A[j].first) continue;
            t = (ld) (A[j].first - A[i].first) / (ld) (A[i].second - A[j].second);
            if (ans < 0 || ans > t) ans = t;
        }
    }
    cout << setprecision(12) << fixed << ans << '\n';
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
