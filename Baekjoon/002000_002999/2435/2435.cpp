#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, K, i;
    cin >> N >> K ;
    vector<int> A(N+1);
    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> A[i];
        A[i] += A[i-1];
    }
    int ans = -1000000;
    for ( i = K ; i <= N ; i ++ )
        ans = max(ans, A[i]-A[i-K]);
    cout << ans ;
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
