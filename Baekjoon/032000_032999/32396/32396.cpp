#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
const ll INF = 1e15;

void process(int Case) {
	int N, i, ans = 0;
	ll M;
	cin >> N >> M;
	vector<ll> A(N);
	for (auto &n: A) cin >> n ;
	for ( i = 1 ; i < N ; i ++ )
		if ( abs(A[i] - A[i-1]) < M )
			A[i] += INF, ans ++;
	cout << ans << endl;
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
