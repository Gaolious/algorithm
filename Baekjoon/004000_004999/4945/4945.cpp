#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
enum TYPE {
	EMPTY,
	PLUS,
	MINUS,
	MULTIPLY,
	BRACKET,
	DIGIT,
	FRAC,
};
const int MOD = 2011;
struct IN
{
	int sy, sx, ey, ex;
	int valid(int y, int x) { return ( sy <= y && y <= ey && sx <= x && x <= ex ); }
};
int Order(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	if (op == '^') return 3;
	return 0;
}
int eGCD(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int gcd = eGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}
int modInverse(int a, int m) {
	int x, y;
	int g = eGCD(a, m, x, y);
	int ret = (x % m + m) % m;
	return ret;
}
int mPOW( int a, int n) {
	if ( n == 0 ) return 1;
	int t = mPOW( a, n / 2);
	t = (t * t ) % MOD ;
	if ( n % 2 == 1 ) t = t * a % MOD;
	return t;
}
pii findBase(vector<string> &A, IN in)
{
	int i, j;
	for ( j = in.sx ; j <= in.ex ; j ++ )
		for ( i = in.sy ; i <= in.ey ; i ++ )
			if ( A[i][j] != '.' )
				return {i, j};
	return {-1, -1};
}
bool isFractionBase(vector<string> &A, IN in, int y, int x)
{
	return ( in.valid(y,x) && in.valid(y, x+2) && A[y][x] == '-' && A[y][x+1] == '-' && A[y][x+2] == '-');
}
int getFractionSize(vector<string> &A, IN in, int y, int x)
{
	int cnt = 0;
	for ( ; x <= in.ex && A[y][x] == '-' ; x ++ ) cnt ++;
	return cnt;
}
#define isDigit(c) ((c) >= '0' && (c) <= '9')

int ParseDigit(vector<string> &A, IN in, int y, int &x)
{
	int ret = 0;
	for ( ; x <= in.ex && isDigit(A[y][x]) ; x++ )
	{
		ret = ret * 10 + (A[y][x] - '0');
		if ( x + 1 > in.ex || !isDigit(A[y][x+1]) ) break;
	}
	return ret;
}
int Calculate(int a, int b, char op) {
	int ret = 0 ;
	switch (op) {
		case '+': ret = a + b; break;
		case '-': ret = a - b; break;
		case '*': ret = a * b; break;
		case '/': ret = a * modInverse(b, MOD); break;
		case '^': ret = mPOW(a, b ); break;
	}
	ret = ( ( ret % MOD ) + MOD ) % MOD ;
	// cout << a << ' ' << (char)op << ' ' << b << " = " << ret << '\n';
	return ret;
}

int Parse(vector<string> &A, IN in, int y, int &x)
{
	TYPE prev = EMPTY;
	int t, tx, ty, sign = 1;
	vector<int> Numbers;
	vector<char> Opers;

	auto PushNumber = [&Numbers] (int n)
	{
		Numbers.push_back( ( ( n % MOD ) + MOD ) % MOD ) ;
	};
	auto Calc = [&Numbers, &Opers, &PushNumber]()
	{
		if ( !Opers.empty()  )
		{
			char op = Opers.back(); Opers.pop_back();;
			int b = Numbers.back(); Numbers.pop_back();
			int a = Numbers.back(); Numbers.pop_back();
			PushNumber( Calculate(a, b, op) );
		}
	};
	auto PushOper = [&Numbers, &Opers, &Calc](char c)
	{
		while ( !Opers.empty() && Opers.back() != '(' && Order(Opers.back()) >= Order(c) ) Calc();
		Opers.push_back(c);
	};

	for ( ; x <= in.ex ; x ++ )
	{
		if ( A[y][x] == '.' ) continue;
		else if ( isFractionBase(A, in, y, x) )
		{
			int fractionSize = getFractionSize(A, in, y, x);

			IN numeratorRange = {in.sy, x+1, y-1, x + fractionSize - 2 };
			IN denominatorRange = {y+1, x+1, in.ey, x + fractionSize - 2 };
			tie(ty, tx) = findBase(A, numeratorRange);
			auto numerator = Parse(A, numeratorRange, ty, tx);
			tie(ty, tx) = findBase(A, denominatorRange);
			auto denominator = Parse(A, denominatorRange, ty, tx);
			PushNumber( Calculate(numerator, denominator, '/') * sign );
			sign = 1;
			x += fractionSize - 1;
			prev = FRAC;
		}
		else if (A[y][x] == '-')
		{
			if ( prev == MINUS || prev == PLUS || prev == MULTIPLY || prev == EMPTY  )
				sign *= -1;
			else
				PushOper('-');
			prev = MINUS;
		}
		else if (A[y][x] == '+' )
		{
			PushOper('+');
			prev = PLUS;
		}
		else if (A[y][x] == '*' )
		{
			PushOper('*');
			prev = MULTIPLY;
		}
		else if (A[y][x] == '(' )
		{
			x++;
			t = Parse(A, in, y, x);
			if ( y > in.sy && x < in.ex && isDigit(A[y-1][x+1]) )
			{
				x++;
				auto e = ParseDigit(A, in, y-1, x);
				t = Calculate(t, e, '^') ;
			}
			PushNumber( t * sign );
			sign = 1;
			prev = BRACKET;
		}
		else if ( A[y][x] == ')' )
		{
			break;
		}
		else if ( isDigit(A[y][x] ) )
		{
			auto number = ParseDigit(A, in, y, x);
			int exp = 1;
			if ( y > in.sy && x < in.ex && isDigit(A[y-1][x+1]) ) { x++; exp = ParseDigit(A, in, y-1, x); }
			PushNumber( Calculate(number, exp, '^') * sign);
			sign = 1;
			prev = DIGIT;
		}
	}
	while (!Opers.empty() ) Calc();
	return Numbers.front();
}

void process(int N) {
	int y, x;
	vector<string> A(N);
	for (auto &s: A) cin >> s;

	IN in = { 0, 0, N-1, (int)(A[0].size()) - 1};
	tie(y, x) = findBase(A, in);

	auto ans = Parse(A, in, y, x);
	cout << ans << '\n';;
}
int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int N;
	while ( cin >> N && N )
		process(N);
    return 0;
}
