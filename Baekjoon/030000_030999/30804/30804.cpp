#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	int N, l, r, cnt, ans=0;
	cin >> N ;
	vector<int> A(N), C(10, 0);
	for (auto &n: A) cin >> n;

	for ( r=0, l = 0, cnt=0 ; r < N ; r ++ )
	{
		if ( C[ A[r] ]++ == 0 )
			cnt ++;

		while ( cnt > 2 && l < r )
			if ( --C[ A[l++] ] == 0 )
				cnt--;
		ans = max(ans, r-l+1);
	}
	cout << ans << '\n';
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
