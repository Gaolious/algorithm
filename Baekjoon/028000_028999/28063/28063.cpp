#include <bits/stdc++.h>
using namespace std;

int N ;

int F(int sx, int sy, int ex, int ey, int cnt)
{
	if ( sx == 1 && sy == 1 && ex == N && ey == N )
		return cnt ;
	int ret = 1000;
	if ( 1 < sx ) ret = min(ret, F(1, sy, ex, ey, cnt+1));
	if ( ex < N ) ret = min(ret, F(sx, sy, N, ey, cnt+1));
	if ( 1 < sy ) ret = min(ret, F(sx, 1, ex, ey, cnt+1));
	if ( ey < N ) ret = min(ret, F(sx, sy, ex, N, cnt+1));
	return ret;
}
void process(int Case) {
	int x, y;
	cin >> N >> x >> y ;

	cout << F(x, y, x, y, 0) << '\n';
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
