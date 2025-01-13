#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
	int N;
	string a, b;
	unordered_map<string, bool> map;
	cin >> N ;
	map["ChongChong"] = true;
	while (N--)
	{
		cin >> a >> b;
		if (map[a] || map[b])
			map[a] = map[b] = true;
	}
	int cnt = 0;
	for (auto it = map.begin(); it != map.end(); it++)
		if (it->second) cnt++;
	cout << cnt << '\n';
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
