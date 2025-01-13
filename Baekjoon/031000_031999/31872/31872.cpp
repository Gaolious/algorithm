#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}
void process(int Case) {
    int N, K, i;
    ll ans;
    cin >> N >> K ;
    vector<ll> A(N);
    vector<ll> B(N);
    for (auto &n: A) cin >> n;
    A.push_back(0);
    std::sort(A.begin(), A.end());
    for ( i = 0 ; i < N ; i ++ ) B[i] = A[i+1]-A[i];
    std::sort(B.begin(), B.end());
    for (ans = 0, i = 0 ; i < N-K ; i ++ )
        ans += B[i];
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
