#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
enum CIRCUIT_TYPE {LITERAL, GATE_AND, GATE_OR, GATE_XOR, VARIABLE };
struct Circuit
{
	CIRCUIT_TYPE type;
	int sx, sy, ex, ey;
	int val;
	vector<pair< int, bool>> inputs; // Circuit Index, not
	vector<pair< int, bool>> outputs; // Circuit Index, not

	Circuit(CIRCUIT_TYPE _type, int y, int x, int v): type(_type), sx(x), sy(y), ex(x), ey(y), val(v) {}
	Circuit(int _sy, int _sx, int _ey, int _ex): sx(_sx), sy(_sy), ex(_ex), ey(_ey) {}
};

struct Problem
{
	vector<string> inputs;
	vector<Circuit> circuitList;
	vector<vector<int>> visit;

	bool readCircuit()
	{
		int i, j;
		string s;

		while(getline(cin, s) && s[0] != '*' )
			inputs.emplace_back(s);

		if (inputs.empty()) return false;

		visit.reserve(inputs.size());
		for (i = 0; i < inputs.size(); ++i)
			visit.emplace_back(inputs[i].length(), -1);

		parseCircuit();
		connectCircuits();
		return true;
	}

	void parseCircuit()
	{
		int i, j, d, y, x;
		for (i = 0; i < inputs.size(); ++i)
			for ( j = 0 ; j < inputs[i].length(); ++j)
			{
				if ( visit[i][j] != -1 ) continue;

				if ( '0' <= inputs[i][j] && inputs[i][j] <= '1' )
				{
					circuitList.emplace_back(LITERAL, i, j, inputs[i][j] == '1');
					visit[i][j] = circuitList.size() - 1;

				}
				else if ( 'A' <= inputs[i][j] && inputs[i][j] <= 'Z' )
				{
					circuitList.emplace_back(VARIABLE, i, j, inputs[i][j] - 'A');
					visit[i][j] = circuitList.size() - 1;
				}
				else if ( inputs[i][j] == '#')
				{
					auto &circuit = circuitList.emplace_back(i, j, i, j);
					visit[i][j] = circuitList.size() - 1;
					while ( circuit.ex + 1 < inputs[i].length() && inputs[circuit.sy][circuit.ex+1] == '#') circuit.ex ++;
					while ( circuit.ey + 1 < inputs.size() && inputs[circuit.ey+1][circuit.ex] == '#') circuit.ey ++;

					for ( y = circuit.sy ; y <= circuit.ey ; y ++ )
						for ( x = circuit.sx ; x <= circuit.ex ; x ++ )
						{
							visit[y][x] = visit[i][j];
							if ( inputs[y][x] == '&' ) circuit.type = GATE_AND;
							else if ( inputs[y][x] == '=' ) circuit.type = GATE_XOR;
							else if ( inputs[y][x] == '1' ) circuit.type = GATE_OR;
						}
				}
			}
	}

	bool valid(int y, int x)
	{
		return !(y < 0 || y >= inputs.size() || x < 0 || x >= inputs[y].length());
	}
	void dump()
	{
		for (auto &s : inputs)
			cout << s << '\n';
		cout << endl;
	}
	void move(int no, int y, int x, int dir, bool neg)
	{
		Circuit &inCircuit = circuitList[ no ];
		int ty, tx;
		while ( true )
		{
			y += dy[dir];
			x += dx[dir];
			if ( !valid(y, x) ) return;
			if ( visit[y][x] != -1 )
			{
				auto &outCircuit = circuitList[ visit[y][x] ];
				inCircuit.outputs.emplace_back(visit[y][x], neg);
				outCircuit.inputs.emplace_back(no, neg);
				return;
			}
			if ( inputs[y][x] == ( dir % 2 == 0 ? '-' : '|') ) { inputs[y][x] = ' ' ; continue; }

			switch ( inputs[y][x] )
			{
			case 'x': inputs[y][x] = dir % 2 == 0 ? '|' : '-'; break;
			case '=': inputs[y][x] = ' ' ; continue;
			case 'o': inputs[y][x] = ' ' ; neg = !neg; continue;
			case '+':
				{
					for ( int d = 0 ; d < 4 ; d ++ )
					{
						ty = y + dy[d];
						tx = x + dx[d];
						if ( !valid(ty,tx) ) continue;
						if ( inputs[ ty ][ tx ] == '=' || inputs[ty][tx] == 'x' || inputs[ty][tx] == ( d % 2 == 0 ? '-' : '|') )
						{
							inputs[y][x] = ' ';
							move(no, y, x, d, neg);
						}
					}
					return;
				}
			}
		}
	}
	void connectCircuits()
	{
		int d, y, x;
		for ( int i = 0 ; i < circuitList.size() ; i ++ )
		{
			auto &circuit = circuitList[ i ];
			if ( circuit.type == LITERAL )
			{
				for ( d = 0 ; d < 4 ; d +=2 ) // x
				{
					y = circuit.sy + dy[d];
					x = circuit.sx + dx[d];
					if ( !valid(y,x) ) continue;
					if ( inputs[ y ][ x ] == '=' || inputs[ y ][ x ] == 'o' || inputs[y][x] == 'x' || inputs[y][x] == '-' )
					{
						move(i, circuit.sy, circuit.sx, d, false);
						break;
					}
				}
			}
			else if (circuit.type == GATE_AND || circuit.type == GATE_XOR || circuit.type == GATE_OR)
			{
				for ( y = circuit.sy ; y <= circuit.ey ; y ++ )
				{
					x = circuit.ex + 1;
					if ( inputs[ y ][ x ] == '=' || inputs[ y ][ x ] == 'o' || inputs[y][x] == 'x' || inputs[y][x] == '-' )
					{
						move(i, y, circuit.ex, 0, false);
					}
				}
			}
		}
	}
	vector<int> varIndex;
	vector<int> D;
	bool F(int i)
	{
		auto &ret = D[i];
		if ( ret < 0 )
		{
			auto &circuit = circuitList[ i ];
			if ( circuit.type == LITERAL ) ret = circuit.val ;
			else if ( circuit.type == GATE_AND || circuit.type == GATE_XOR || circuit.type == GATE_OR )
			{
				int True=0, False=0, val;
				for (auto &[src, neg] : circuit.inputs )
				{
					val = F(src);
					if ( neg) val = !val;
					if ( val ) True ++;
					else False++;
				}
				if ( circuit.type == GATE_AND ) ret = False == 0;
				else if ( circuit.type == GATE_XOR ) ret = True % 2 == 1;
				else if ( circuit.type == GATE_OR ) ret = True > 0;
			}
			else
			{
				for (auto &[src, neg] : circuit.inputs )
				{
					ret = F(src);
					if (neg) ret = !ret;
				}
			}
		}
		return ret ? true : false ;
	}
	void run()
	{
		D.resize( circuitList.size(), -1 );
		for ( int i = 0 ; i < circuitList.size() ; i ++ )
		{
			auto &circuit = circuitList[ i ];
			if ( circuit.type == VARIABLE ) varIndex.push_back( i );
		}
		sort( varIndex.begin(), varIndex.end(), [&](int i, int j){ return circuitList[i].val < circuitList[j].val; } );
		for (auto i: varIndex )
		{
			auto &circuit = circuitList[ i ];
			cout << (char)('A' + circuit.val) << "=" << F(i) << '\n';
		}
	}
};

void process() {
	int i;
	for ( i = 0 ; ; i ++ )
	{
		Problem p;
		if ( !p.readCircuit() ) return;
		if ( i > 0 ) cout << '\n';
		p.run();
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	process();
    return 0;
}
