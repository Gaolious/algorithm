#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

#define VALID(y, x) ( 0 <= (y) && (y) < N && 0 <= (x) && (x) < N )

int dy[] = { 0, 1};
int dx[] = { 1, 0};
void process(int N) {
	vector A(N, vector(N, 0));
	string s;
	vector Visit(N, vector<ll>(N, 0));
	for (auto &arr: A)
	{
		cin >> s;
		for ( int i = 0 ; i < N ; i ++ ) arr[i] = s[i] - '0';
	}
	Visit[0][0] = 1;
	for ( int y = 0 ; y < N ; y ++ )
		for ( int x = 0 ; x < N ; x ++ )
		{
			if ( Visit[y][x] == 0 || A[y][x] == 0 ) continue;

			for ( int d = 0 ; d < 2 ; d ++ )
			{
				int ty = y + dy[d] * A[y][x];
				int tx = x + dx[d] * A[y][x];
				if ( !VALID(ty, tx) ) continue;
				Visit[ty][tx] += Visit[y][x] ;
			}
		}

	cout << Visit[N-1][N-1] << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	while ( cin >> T && T > 0 )
	    process(T);
    return 0;
}
