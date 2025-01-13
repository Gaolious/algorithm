#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init(){
}
void process(int Case) {
	int H, W, K, Q, x, y;
	int i, j, n;
	cin >> H >> W >> K >> Q;
	int INF = H*W + 10;
	vector D(H+2, vector(W+2, 0));
	vector<pii> X(H*W+1, {INF, -INF}), Y(H*W+1, {INF, -INF});
	vector uniqueNum (H*W+1, false);
	int uniqueCnt = 0;
	for (i = 1 ; i <= H ; i++)
	{
		for (j = 1 ; j <= W ; j++)
		{
			cin >> n;
			uniqueNum[n] = true;
			X[ n ].first = min( X[ n ].first, j );
			X[ n ].second = max( X[ n ].second, j );
			Y[ n ].first = min( Y[ n ].first, i );
			Y[ n ].second = max( Y[ n ].second, i );
		}
	}

	for ( i = 1 ; i <= W*H ; i ++ )
	{
		if ( !uniqueNum[i] ) continue;
		uniqueCnt ++;

		int nX = X[i].second - X[i].first + 1;
		int nY = Y[i].second - Y[i].first + 1;
		if ( nX > K || nY > K) continue;
		if ( X[i].first > X[i].second ) continue;
		if ( Y[i].first > Y[i].second ) continue;

		int sx, sy, ex, ey;
		sx = max(1, X[i].second + 1 - K) ;
		sy = max(1, Y[i].second + 1 - K) ;
		ex = X[i].first;
		ey = Y[i].first;
		D[ sy ][ sx ] += 1;
		D[ sy ][ ex + 1 ] -= 1;
		D[ ey + 1 ][ sx ] -= 1;
		D[ ey + 1 ][ ex + 1 ] += 1;
	}
	for ( i = 1 ; i <= H  ; i++ )
		for ( j = 1 ; j <= W ; j++ )
			D[i][j] += D[ i ][ j - 1 ] + D[ i - 1 ][ j ] - D[ i - 1 ][ j - 1 ];
	while ( Q -- )
	{
		cin >> y >> x;
		cout << uniqueCnt - D[y][x] << '\n';
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
