#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	int N, M, i;
	vector<int> A, B, CA(101, 0), CB(101, 0);
	vector<int> ans;
	cin >> N ;
	A.resize(N); for (auto &n: A) { cin >> n ; CA[n]++; }
	cin >> M ;
	B.resize(M); for (auto &n: B) {cin >> n ; CB[n]++; }

	vector<int>::iterator a = A.begin(), b=B.begin();

	for ( i = 100 ; i > 0 ; i -- )
	{
		while ( CA[i] > 0 && CB[i] > 0 )
		{
			ans.push_back(i);
			while ( a != A.end() )
			{
				CA[ *a ] --;
				if ( *a++ == i ) break;
			}
			while ( b != B.end() )
			{
				CB[ *b ] --;
				if ( *b++ == i ) break;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto n: ans) cout << n << ' ';
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
