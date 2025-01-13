#include <bits/stdc++.h>
using namespace std;

enum TOKEN_TYPE { UNARY_NOT, BINARY_AND, BINARY_OR, VARIABLE };
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
struct Token
{
	TOKEN_TYPE type;
	int varIndex{};
	Token(TOKEN_TYPE type, int varIndex) : type(type), varIndex(varIndex) {}
	Token(TOKEN_TYPE type) : type(type), varIndex(-1) {}
};
struct Problem
{
	vector<string> data;
	vector<Token> tokenList;
	bool readLogic()
	{
		int i, j;
		int y=0, x=0;
		bool foundQuestionMark = false;
		string s;
		for ( i = 0 ; getline(cin, s) && s != "*" ; i ++)
		{
			data.emplace_back(s);
			for ( j = 0 ; j < s.length() && !foundQuestionMark ; j ++ )
				if ( s[j] == '?' ) { y = i, x = j; foundQuestionMark = true; }
		}

		if ( foundQuestionMark )
		{
			for ( int d = 0 ; d < 4 ; d ++ )
				if ( valid(y + dy[d], x + dx[d]) && data[ y + dy[d] ][ x + dx[d] ] == (d%2 == 0 ? '-' : '|') )
				{
					parseLogic(y, x, d);
					return true;
				}
		}
		else
			return false;
	}
	bool valid(int y, int x)
	{
		return !( y < 0 || y >= data.size() || x < 0 || x >= data[y].size() );
	}
	bool isSkip(char c)
	{
		return ( c == '?' || c == '-' || c == '|' || c == '+' );
	}
	void parseLogic(int y, int x, int dir)
	{
		while ( valid(y, x) )
		{
			if ( data[y][x] == '?' || data[y][x] == '|' || data[y][x] == '-' ) { y += dy[dir], x += dx[dir]; continue; }
			if ( data[y][x] == '+' )
			{
				char lookup = ( dir % 2 == 0 ) ? '|' : '-';
				for (auto d: { (dir+1)%4, (dir+3)%4 } )
					if ( valid(y + dy[d], x + dx[d]) && data[ y + dy[d] ][ x + dx[d] ] == lookup ) { dir = d; break; }
				y += dy[dir], x += dx[dir];
				continue;
			}

			if ( 'A' <= data[y][x] && data[y][x] <= 'Z' )
			{
				tokenList.emplace_back(VARIABLE, data[y][x] - 'A');
				return;
			}
			else if ( data[y][x] == 'o' )
			{
				parseLogic( y+dy[dir], x+dx[dir], dir);
				tokenList.emplace_back(UNARY_NOT);
				return;
			}
			else if ( data[y][x] == ')' )
			{
				parseLogic( y-1, x-3, 2 );
				parseLogic( y+1, x-3, 2 );
				tokenList.emplace_back(BINARY_AND);
				return;
			}
			else if ( data[y][x] == '>' )
			{
				parseLogic( y-1, x-3, 2 );
				parseLogic( y+1, x-3, 2 );
				tokenList.emplace_back(BINARY_OR);
				return;
			}
		}
	}
	void calc(bool var[26])
	{
		stack<bool> S;
		bool a, b;
		for (auto &t: tokenList)
		{
			if ( t.type == VARIABLE ) { S.push(var[t.varIndex]); continue; }

			b = S.top(); S.pop();
			if ( t.type == UNARY_NOT ) { S.push( !b ); continue; }

			a = S.top(); S.pop();
			if ( t.type == BINARY_AND ) { S.push( a && b ); continue; }
			if ( t.type == BINARY_OR ) { S.push( a || b ); continue; }
		}
		cout << S.top() << endl;
	}
	void readVar()
	{
		int i;
		string s ;
		while ( getline(cin, s) && s != "*" )
		{
			bool var[26]={false};
			for (i = 0 ; i < 26 ; i ++ ) var[i] = s[i] == '1';
			calc(var);
		}
	}
};
void process() {
	for ( int i = 0 ; ; i ++)
	{
		Problem p;
		if ( p.readLogic() )
		{
			if ( i > 0 ) cout << '\n';
			p.readVar();
		}
		else break;
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
