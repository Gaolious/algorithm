#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
	int N, t, i, cnt, maxcnt;
	string s;
	unordered_map<string, int> map;
	cin >> N ;
	cnt = maxcnt = 0;
	while (N--)
	{
		cin >> t >> t ;
		for ( i = 0 ; i < t ; i++)
		{
			cin >> s;
			if (map.find(s) == map.end()) map.insert(make_pair(s, 1));
			else map[s]++;
			maxcnt = max(maxcnt, map[s]);
		}
	}

	cnt = 0 ;
	for ( auto &[a, b]: map )
	{
		if ( b == maxcnt )
		{
			cnt ++;
			s = a;
		}
		if ( cnt > 1 ) break;
	}
	if ( cnt == 1 ) cout << s << '\n';
	else cout << "-1\n";
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
