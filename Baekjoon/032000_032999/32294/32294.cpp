#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
const ll INF = 1e18;
void process(int Case) {
	int i, N, from, b ;
	cin >> N ;
	vector<ll> A(N+2);
	vector<vector<pll>> C(N+2);
	for ( i = 1 ; i <= N ; i ++ ) cin >> A[ i ];
	for ( i = 1 ; i <= N ; i ++ )
	{
		cin >> b ;

		from = max(0ll, i - A[i]);
		C[from].emplace_back(i, b);
		from = min(N+1ll, i + A[i]);
		C[from].emplace_back(i, b);
	}

	priority_queue<pair<ll, int>> Q;
	vector<ll> D(N+2, INF);
	D[0] = D[N+1] = 0;
	Q.emplace(0, 0);
	Q.emplace(0, N+1);

	while ( !Q.empty() )
	{
		auto [dist, curr] = Q.top();
		dist *= -1;
		Q.pop();
		if ( D[curr] < dist ) continue;

		for ( auto [next, t] : C[curr] )
		{
			if ( D[next] > dist + t )
			{
				// cout << "[" << curr << "] -> [" << next << "] : " << dist + t << '\n';
				D[next] = dist + t;
				Q.emplace(-D[next], next);
			}
		}
	}
	for ( i = 1 ; i <= N ; i ++ )
		cout << D[ i ] << ' ';
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
