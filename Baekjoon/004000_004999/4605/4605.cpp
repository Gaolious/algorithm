#include <bits/stdc++.h>
using namespace std;

const int INF = 1'000'000;
#define MIN(a, b) ( (a) = min((a), (b) ) )
#define MAX(a, b) ( (a) = max((a), (b) ) )
#define MINMAX(a, b, c) ( MIN(a,c), MAX(b, c) )
struct Tile
{
	int W{}, H{};
	vector<pair<int, int>> visible;
	vector<pair<int, int>> invisible;
	int sy{}, ey{}, sx{}, ex{};
	vector<int> range_minx;
	vector<int> range_maxx;
	int lx{}, rx{};

	Tile(int width, int height)
	{
		W = width;
		H = height;
	}
	Tile(vector<string> &A, int x1, int x2)
	{
		int i, j, y, x;
		H = A.size();
		W = x2 - x1 + 1;

		for ( i = 0 ; i < H ; i ++ )
		{
			for ( j = x1 ; j <= x2 ; j ++ )
			{
				y = i;
				x = j - x1;
				if ( A[i][j] == '.' ) continue;

				if ( A[i][j] == '#' )
					visible.emplace_back(y, x);
				else
					invisible.emplace_back(y, x);
			}
		}
		update_minmax_range();
	}
	void update_minmax_range()
	{
		int i, j;
		lx = sy = sx = INF;
		rx = ey = ex = -INF;
		range_minx.resize(H, INF);
		range_maxx.resize(H, -INF);
		for (auto [y, x]: visible)
		{
			MINMAX(range_minx[y], range_maxx[y], x);
			MINMAX(sy, ey, y);
			MINMAX(sx, ex, x);

			MINMAX(lx, rx, x);
		}
		for (auto [y, x]: invisible)
		{
			MINMAX(range_minx[y], range_maxx[y], x);
			MINMAX(sy, ey, y);
			MINMAX(sx, ex, x);
		}
	}
	void putLeft(Tile &other)
	{
		int addedWidth = other.W - 1;

		W += addedWidth;
		for (auto &[y, x]: visible) x += addedWidth;
		for (auto &[y, x]: invisible) x += addedWidth;
		for (auto [y, x]: other.visible) visible.emplace_back(y, x);
		for (auto [y, x]: other.invisible) invisible.emplace_back(y, x);
		update_minmax_range();
	}
	void putRight(Tile &other)
	{
		int gap = W + other.W;
		int addedOffset = 0;
		if ( sx <= ex )
		{
			for ( int y = other.sy ; y <= other.ey ; y ++ )
			{
				if ( other.range_minx[y] <= other.range_maxx[y] && range_minx[y] <= range_maxx[y] )
					gap = min(gap, W-1 - range_maxx[y] + other.range_minx[y]);
			}

			addedOffset = W + ( 1 - gap );
			W = addedOffset + other.W;
		}

		for (auto [y, x]: other.visible) visible.emplace_back(y, x + addedOffset);
		for (auto [y, x]: other.invisible) invisible.emplace_back(y, x + addedOffset);
		update_minmax_range();
	}
	void merge(Tile &other)
	{
		bool cross = false;

		for ( int y = other.sy ; y <= other.ey ; y ++ )
		{
			if ( other.range_minx[y] <= other.range_maxx[y] && range_minx[y] <= range_maxx[y] )
				cross = true;
		}
		if ( cross )
			putRight(other);
		else
			putLeft(other);
	}

	void dump()
	{
		if ( sx <= ex )
		{
			vector outputs( H, string( rx-lx+1, '.'));
			for (auto [y,x]: visible)
			{
				outputs[ y ][ x - lx ] = '#';
			}
			for (auto &s: outputs)
				cout << s << '\n';
		}
	}
};

void Input(int N, vector<Tile> &ret)
{
	int sx, ex;
	int len;

	vector<string> A(N);
	for (auto &s: A) getline(cin, s);

	len = A[0].length();

	for ( sx = ex = -1; ex < len ;)
	{
		for (sx = ex+1; sx < len && A[0][sx] == ' ' ; sx ++ ) {}
		for (ex = sx+1; ex < len && A[0][ex] != ' ' ; ex ++ ) {}

		if ( sx < len)
			ret.emplace_back(A, sx, ex-1);
	}
}

void process(int N, int Case) {
	vector<Tile> tiles;
	Input(N, tiles);

	// cout << "After Tile " << 0 << '\n';
	// tiles[0].dump();;
	for ( int i = 1 ; i < tiles.size() ; i ++ )
	{
		// cout << "After Tile " << i << '\n';
		tiles[0].merge(tiles[i]);
	}

	cout << Case << '\n';
	tiles[0].dump();
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int N, t=0;
	while ( cin >> N && N )
	{
		cin.ignore();
		process(N, ++t);
	}
    return 0;
}
