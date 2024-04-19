#include <bits/stdc++.h>
//#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char _b[SZ];
	int ri, ni;
	bool _e, _g;
public:
	explicit operator bool() { return !_e; }
	bool B(char c) { return c <= ' '; }
	bool E(char c) { return c == '\0'; }
	char C() {
		if (ri == ni) {
			ni = fread(_b, sizeof(char), SZ, stdin);
			if (ni == 0) return 0;
			ri = 0;
		}
		return _b[ri++];
	}
	char ReadChar() {
		char ret = C();
		for (; B(ret); ret = C());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = C(); bool flag = 0;
		for (; B(cur); cur = C());
		if (cur == '-') flag = 1, cur = C();
		for (; !B(cur) && !E(cur); cur = C()) ret = 10 * ret + (cur & 15);
		if (E(cur)) _e = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = C();
		for (; B(cur); cur = C());
		for (; !B(cur) && !E(cur); cur = C()) ret.push_back(cur);
		if (E(cur)) _e = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = C();
		for (; B(cur); cur = C());
		for (; cur != '\r' && cur != '\n' && !E(cur); cur = C()) ret.push_back(cur);
		if (_g) _e = 1;
		if (E(cur)) _g = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char _b[SZ];
	int wi;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		fwrite(_b, sizeof(char), wi, stdout);
		wi = 0;
	}
	void WriteChar(char c) {
		if (wi == SZ) Flush();
		_b[wi++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (wi + sz >= SZ) Flush();
		if (n < 0) _b[wi++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) _b[wi + i] = n % 10 | 48;
		wi += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

typedef enum { VAR_X, VAR_Y, CONSTANT, UNKNOWN } VAR_TYPE ;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

struct Fraction {
	ll a, b ;
	Fraction() { a=0, b=1; }
	Fraction(ll v) { a=v, b = 1; }
	Fraction(ll q, ll w) { a=q, b=w; }
	Fraction &simplify() {
		ll g = gcd(a,b);
		a /= g;
		b /= g;
		if ( b < 0 ) a *= -1, b *= -1;
		return *this;
	}
	Fraction operator + (Fraction o) const {
		ll g = gcd(b, o.b);
		Fraction ret = {
			a*o.b/g + b * o.a/g,
			b / g * o.b
		};
		return ret.simplify();
	}
	Fraction operator - (Fraction o) const {
		Fraction tmp = o;
		tmp.a *= -1;
		return *this + tmp ;
	}
	Fraction operator * (Fraction o) const {
		ll g = gcd(b, o.b);
		Fraction ret = {
			a * o.a,
			b * o.b
		};
		return ret.simplify();
	}
	Fraction operator / (Fraction o) const {
		Fraction tmp( o.b, o.a);
		tmp.simplify();
		return *this * tmp;
	}
	bool operator == (ll v ) const {
		Fraction tmp( v);
		return *this == tmp;
	}
	bool operator != (ll v ) const {
		Fraction tmp( v);
		return *this != tmp;
	}
	bool operator == (Fraction o ) const {
		Fraction tmp = *this - o;
		return tmp.a == 0;
	}
	bool operator != (Fraction o ) const {
		Fraction tmp = *this - o;
		return tmp.a != 0;
	}
	string str() {
		std::ostringstream sstr;
		if ( b == 1 ) sstr << a ;
		else sstr << a << '/' << b;
		return sstr.str();
	}
};
struct Variable {
	VAR_TYPE type;
	ll coefficient;
	Variable(): type(UNKNOWN), coefficient(0) {}
	Variable(VAR_TYPE t, ll c): type(t), coefficient(c) {}
	Variable operator + (Variable o) {
		Variable ret ;
		if (type == UNKNOWN )
			ret = o;
		else if ( o.type == UNKNOWN )
			ret = *this;
		else if ( type == o.type ) {
			ret = *this;
			ret.coefficient += o.coefficient;
		}
		return ret;
	}
	Variable operator - (Variable o) {
		Variable tmp = o ;
		tmp.coefficient *= -1;
		return *this + tmp ;
	}
	void setVariable(string &s) {
		if ( s.size() ) {
			if ( s.back() == 'x' ) {
				type = VAR_X; s.pop_back();
			}
			else if ( s.back() == 'y' ) {
				type = VAR_Y; s.pop_back();
			}
			else {
				type = CONSTANT;
			}
			coefficient = 0;
			int sign = 1;
			bool hasCoefficient = false;
			for (auto c: s ) {
				if ( c == '-' ) sign = -1;
				else if ( '0' <= c && c <= '9') {
					coefficient = coefficient * 10 + (c-'0');
					hasCoefficient = true;
				}
			}
			if ( type != CONSTANT && !hasCoefficient )
				coefficient = 1; // 생략된 계수
			coefficient *= sign;
		}
	}
};
struct Equation {
	vector<Variable> lhs;
	vector<Variable> rhs;
	void setEquation(vector<string> &equation_list) {
		int prev_sign = 1;
		vector<Variable> * addTo[] = { &lhs, &rhs};
		int turn = 0;
		for ( auto expr : equation_list ) {
			if ( expr == "-" ) prev_sign = -1;
			else if ( expr == "+" ) prev_sign = 1;
			else if ( expr == "=" ) turn = 1 - turn, prev_sign = 1;
			else {
				Variable var{};
				var.setVariable(expr);
				var.coefficient *= prev_sign;
				addTo[turn]->push_back(var);
			}
		}
	}
};

void Solve(Equation &eq1, Equation &eq2) {
	Variable x1 = {VAR_X, 0}, y1{VAR_Y, 0}, c1{CONSTANT, 0};
	Variable x2 = {VAR_X, 0}, y2{VAR_Y, 0}, c2{CONSTANT, 0};
	for ( auto e : eq1.lhs ) {
		if ( e.type == VAR_X ) x1 = x1 + e ;
		else if ( e.type == VAR_Y ) y1 = y1 + e ;
		else if ( e.type == CONSTANT ) c1 = c1 - e ;
	}
	for ( auto e : eq1.rhs ) {
		if ( e.type == VAR_X ) x1 = x1 - e ;
		else if ( e.type == VAR_Y ) y1 = y1 - e ;
		else if ( e.type == CONSTANT ) c1 = c1 + e ;
	}

	for ( auto e : eq2.lhs ) {
		if ( e.type == VAR_X ) x2 = x2 + e ;
		else if ( e.type == VAR_Y ) y2 = y2 + e ;
		else if ( e.type == CONSTANT ) c2 = c2 - e ;
	}
	for ( auto e : eq2.rhs ) {
		if ( e.type == VAR_X ) x2 = x2 - e ;
		else if ( e.type == VAR_Y ) y2 = y2 - e ;
		else if ( e.type == CONSTANT ) c2 = c2 + e ;
	}
	Fraction Matrix[2][3] = {
		{x1.coefficient, y1.coefficient, c1.coefficient},
		{x2.coefficient, y2.coefficient, c2.coefficient},
	};
	int i, j, k ;

	if ( Matrix[0][0] == 0 && Matrix[1][0] != 0 ) {
		for ( i = 0 ; i < 3 ; i ++ )
			swap(Matrix[0][i], Matrix[1][i]);
	}
	else if ( Matrix[0][1] != 0 && Matrix[1][1] == 0 ) {
		for ( i = 0 ; i < 3 ; i ++ )
			swap(Matrix[0][i], Matrix[1][i]);
	}
	for ( i = 0 ; i < 2 ; i ++ ) {
		if ( Matrix[i][i] != 0 ) {
			Fraction t = Matrix[i][i];
			for ( j = 0 ; j < 3 ; j ++ ) Matrix[i][j] = Matrix[i][j] / t ;

			t = Matrix[1-i][i] / Matrix[i][i];

			for ( j = 0 ; j < 3 ; j ++ )
				Matrix[1-i][j] = Matrix[1-i][j] - Matrix[i][j] * t ;

		}
	}
	bool invalid = false;
	for ( i = 0 ; i < 2 ; i ++ )
		if ( Matrix[i][0] == 0 && Matrix[i][1] == 0 && Matrix[i][2] != 0 )
			invalid = true;

	if ( !invalid ) {
		if ( Matrix[0][0] != 0 && Matrix[0][1] == 0)
			cout << Matrix[0][2].str() << '\n';
		else
			cout << "don't know\n";

		if ( Matrix[1][0] == 0 && Matrix[1][1] != 0 ) {
			cout << Matrix[1][2].str() << '\n';
		}
		else
			cout << "don't know\n";
		return ;
	}
	cout << "don't know\n";
	cout << "don't know\n";
}
vector<string> Tokenize(string &s) {
	vector<string> ret;

	for ( auto c: s ) {
		if ( ret.empty() || ( c == ' ' && !ret.back().empty() ) )
			ret.emplace_back();
		if ( c != ' ' )
			ret.back().push_back(c);
	}
	return ret;
}
void process() {
	int T;
	string s1, s2;

	cin >> T ;
	while (T--) {
		Equation a{}, b{};
		s1 = cin.getline();
		s2 = cin.getline();
		// cout << "Expr 1 : " << s1 << '\n';
		auto t = Tokenize(s1);
		a.setEquation(t);
		// a.dump();
		// cout << "Expr 2 : " << s2 << '\n';
		t = Tokenize(s2);
		b.setEquation(t);
		// b.dump();
		Solve(a, b);
		if (T) cout << '\n';
	}
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


