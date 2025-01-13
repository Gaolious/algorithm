#include <bits/stdc++.h>
using namespace std;
void init(){
}
void process(int Case) {
    int N, K, i, k, maxN ;
    cin >> N >> K ;
    vector<int> A(N);
    maxN = -1;
    for (auto &n: A) {
        cin >> n;
        maxN = max(maxN, n);
    }
    vector<int> D(maxN+1);

    while ( K -- ) {
        cin >> k;
        D[k] = 1;
    }
    for ( i = 10 ; i <= maxN ; i ++ )
        D[i] = D[i/10] + D[i%10] ? 1 : 0;
    for ( i = 2 ; i <= maxN ; i ++ )
        D[i] += D[i-1];

    long long ans = 0 ;
    for (auto n: A) ans += D[n];
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
