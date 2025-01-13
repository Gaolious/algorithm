#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pii Pt;

struct pair_hash {
	template <typename T1, typename T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto h1 = hash<T1>{}(p.first);
		auto h2 = hash<T2>{}(p.second);
		return h1 ^ (h2 << 1);
	}
};
ll gcd(ll a, ll b) {
	if (b == 0) return abs(a); // 절대값 반환
	return gcd(b, a % b);
}
int sign(ll v)
{
	if ( v > 0 ) return 1;
	if ( v < 0 ) return -1;
	return 0;
}

void init(){
}
int solve(const vector<Pt>& points) {
	int n = points.size();
	int ret = 0;
	int i, j;
	ll x1, x2, y1, y2, xx, yy, g;
	ll xx1, xx2, yy1, yy2;
	int cnt, maxCnt;

	for (i = 0; i < n; ++i)
	{
		x1 = points[i].first, y1 = points[i].second;
		xx1 = x1*x1, yy1 = y1*y1 ;
		cnt = 1;
		maxCnt = 0;
		unordered_map<ll, unordered_map<ll, int>> Count ;
		for (j = i+1 ; j < n; ++j)
		{
			x2 = points[j].first, y2 = points[j].second;
			xx2 = x2*x2, yy2 = y2*y2 ;

			if ( xx1 == xx2 && yy1 == yy2 )
			{
				cnt ++;
				continue;
			}

			xx = xx1 - xx2, yy = yy1 - yy2 ;
			if ( ( xx && !yy ) || ( yy && !xx ) ) continue;
			if ( sign(xx) * sign(yy) > 0 ) continue;

			g = gcd(abs(xx), abs(yy));
			if (g > 1)
			{
				xx /= g;
				yy /= g;
			}
			if ( xx < 0 || ( xx == 0 && yy < 0 ) )
			{
				xx = -xx; yy = -yy;
			}
			maxCnt = max(maxCnt , ++Count[xx][yy]);
		}
		ret = max(ret, cnt + maxCnt);
	}
	return ret;
}

void process(int Case) {
	int N;
	cin >> N;

    vector<Pt> P(N); //, Points;

	for (auto &[x,y]: P) cin >> x >> y;
	sort(P.begin(), P.end());
	cout << solve(P) << '\n';
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
