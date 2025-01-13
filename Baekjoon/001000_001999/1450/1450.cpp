#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void dfs(ll s, vector<ll> &A, int l, int r, unordered_map<ll, ll> &Map)
{
	if ( l > r )
	{
		Map[s] ++;
		return;
	}
	dfs(s, A, l+1, r, Map );
	dfs(s + A[l], A, l+1, r, Map );
}

ll bsearch(vector<pll> &O, int left, int right, ll v)
{
	ll ret = 0;
	while ( left <= right )
	{
		int mid = left + (right - left) / 2;
		if ( O[mid].first <= v )
		{
			left = mid + 1;
			ret = O[mid].second;;
		}
		else right = mid - 1;
	}
	return ret;
}
void process(int Case) {
	int N, m;
	ll C;
	cin >> N >> C ;
	unordered_map<ll, ll> L, R;
	vector<ll> A(N);
	for (auto &n: A) cin >> n ;

	m = (N-1) / 2;
	dfs(0, A, 0, m, L);
	dfs(0, A, m+1, N-1, R);

	vector<pll> O;
	O.reserve(R.size());
	for (auto [k,v]: R)
		O.emplace_back(k, v);

	sort(O.begin(), O.end());
	for (int i=1 ; i < O.size() ; i++ ) O[i].second += O[i-1].second;

	ll ret = 0;
	for (auto [k,v]: L)
	{
		if ( C-k >= 0 )
			ret += v * bsearch(O, 0, static_cast<int>(O.size())-1, C-k);
	}
	cout << ret << '\n';
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
