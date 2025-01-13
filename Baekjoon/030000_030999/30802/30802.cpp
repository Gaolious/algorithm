#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void process(int Case) {
	ll N;
	ll A[6];
	ll T, P;
	ll ans;
	cin >> N ;
	for (auto &n: A) cin >> n ;
	cin >> T >> P ;

	ans = 0 ;
	for (auto n: A) ans += (n + T-1) / T;
	cout << ans << '\n';
	cout << N / P << ' ' << N % P << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
