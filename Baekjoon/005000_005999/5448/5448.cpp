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
		for (; cur != '\n' && !E(cur); cur = C()) ret.push_back(cur);
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

typedef pair<ll, ll> pll;

pll operator -( pll &a, pll &b ) {
    return {a.first-b.first, a.second-b.second};
}
pll operator *( pll &a, long double b ) {
    return {a.first*b, a.second*b};
}
pll rotate(pll a) {
    return {a.second, -a.first};
}

void normalize(vector<pll> &A){
    ll X = 10000000000ll;
    ll Y = 10000000000ll;
    for (auto [x,y] : A) {
        X = min(X, x);
        Y = min(Y, y);
    }
    for (auto &[x,y] : A) x-=X, y-=Y;
}
bool isMatching(vector<pll> &A, vector<pll> &B, ll maxA) {
    int i ;
    ll maxB=-1;
    for (auto [x, y]: B) maxB = max(maxB, x);
    auto g = gcd(maxA, maxB);
    if (!g) g = 1;
    maxA /= g;
    maxB /= g;

    for ( i = 0 ; i < A.size() ; i ++ ) {
        if ( A[i].first * maxB != B[i].first * maxA ) return false;
        if ( A[i].second * maxB != B[i].second * maxA) return false;
    }
    return true;
}
bool run() {
    int i;
    int N;
    ll maxA = -1;
    cin >> N ;
    vector<pll> A(N), B(N);
    for (auto &[x, y]: A) cin >> x >> y;
    for (auto &[x, y]: B) cin >> x >> y;
    sort(A.begin(), A.end());
    normalize(A);
    sort(B.begin(), B.end());
    normalize(B);

    for (auto [x, y]: A) maxA = max(maxA, x);

    for ( i = 0 ; i < 4 ; i ++ ) {
        if ( i ) {
            for (auto &p: B)  p = rotate(p);
            sort(B.begin(), B.end());
            normalize(B);
        }
        if ( isMatching(A, B, maxA) ) return true;

    }
    return false;
}
void process() {
    int T;
    cin >> T;
    while ( T-- ) {
        if ( run() )
            cout << "okay\n";
        else
            cout << "mismatch!\n";
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


