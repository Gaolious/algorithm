#include <bits/stdc++.h>
using namespace std;

void init(){}
void process(int Case) {
	int N, M;
	string s;
	int has[26]{};
	int del[26]{};
	cin >> N >> M >> s ;
	for (auto c: s) has[ c - 'a' ]++;
	for ( int i = 0 ; i < 26 && M > 0; i ++ )
	{
		del[i] = min(M, has[i]);
		M -= del[i];
	}

	for (auto c: s )
	{
		if (del[c-'a'] > 0 )
		{
			del[c-'a']--;
			continue;
		}
		cout << c ;
	}
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
