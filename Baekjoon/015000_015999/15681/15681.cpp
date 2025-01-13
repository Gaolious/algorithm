#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> C;
vector<int> D;

int F(int root)
{
	auto &ret = D[root];
	if ( ret < 0 )
	{
		ret = 1;
		for (auto nxt: C[root])
			if ( D[nxt] == -1 )
				ret += F(nxt);
	}
	return ret;
}
void process(int Case) {
	int N, R, Q;
	int i, a, b;
	cin >> N >> R >> Q; R--;
	C.resize(N, vector<int>());
	D.resize(N, -1);

	for (i = 1; i < N; i++)
	{
		cin >> a >> b;
		a--; b--;
		C[a].push_back(b);
		C[b].push_back(a);
	}
	F(R);
	while ( Q-- )
	{
		cin >> a ;
		cout << D[a-1] << '\n';
	}
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
