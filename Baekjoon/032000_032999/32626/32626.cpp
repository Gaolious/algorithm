#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}

void init(){
}
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
const ll INF = 10'000'000'000ll;
void process(int Case) {
	int i, d;
	vector<ll> X{-INF, INF}, Y{-INF, INF};
	pll P[3];

	for ( auto &p : P ) cin >> p ;
	for ( auto p: P) X.push_back(p.first), Y.push_back(p.second);
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());

	for ( auto &p: P)
	{
		p.first = (ll)(lower_bound(X.begin(), X.end(), p.first) - X.begin());
		p.second = (ll)(lower_bound(Y.begin(), Y.end(), p.second) - Y.begin());
	}

	vector D(4, vector(Y.size(), vector(X.size(), INF)));
	for ( i = 0 ; i < 4 ; i ++ )
	{
		D[i][ P[0].second ][ P[0].first ] = 0;
		D[i][ P[2].second ][ P[2].first ] = -1;
	}

	queue<pair<int, pll>> Q;
	for ( i = 0 ; i < 4 ; i ++ )
		Q.push({i, {P[0].second, P[0].first}});

	while ( !Q.empty() )
	{
		auto [dir, p] = Q.front(); Q.pop();
		auto [y, x] = p;
		for ( d = 0 ; d < 4 ; d ++ )
		{
			if ( d != dir && (dir-d+4)%4 != 1 && (dir-d+4)%4 != 3  ) continue;
			auto ty = y + dy[d];
			auto tx = x + dx[d];
			if ( ty < 0 || ty >= Y.size() || tx < 0 || tx >= X.size() || D[d][ty][tx] < 0)
				continue;

			auto step = D[dir][y][x] + (d != dir );

			if ( D[d][ty][tx] > step )
			{
				D[d][ty][tx] = step;
				Q.push({d, {ty, tx}});
			}
		}
	}
	auto ans = INF;
	for ( i = 0 ; i < 4 ; i ++ ) ans = min(ans, D[i][P[1].second][P[1].first]);

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
