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
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
#define all(x) (x).begin(), (x).end()

const ll INF = 100000000000ll;
struct SegmentTree {
	typedef vector<int> Node;
	int base{};
	vector<Node> T;
	int N{}, H{} ;
	void init(int n) {
		N = n;
		H = ceil( log2(n) );
		base = 1 << int( H );
		T.resize( base * 2);
	}
	Node Merge(Node &l, Node &r) {
		int i, j ;
		i = j = 0;
		Node ret;

		while ( i < l.size() && j < r.size() ) {
			if ( l[i] < r[j] ) ret.push_back(l[i++]);
			else ret.push_back(r[j++]);
		}
		while ( i < l.size() ) ret.push_back(l[i++]);
		while ( j < r.size() ) ret.push_back(r[j++]);
		return ret;
	}
	void build() {
		for (int i = (base + N - 1) / 2 ; i >= 1 ; i -- ) {
			T[i] = Merge(T[i*2], T[i*2+1]);
			// merge(all(T[i*2]), all(T[i*2+1]), T[i].begin());
		}
	}
	int Count(Node &node, int k) {
		int ret = upper_bound(node.begin(), node.end(), k) - node.begin();
		return node.size() - ret;
	}
	int query(int l, int r, int k) {
		int ret = 0 ;
		for ( l += base, r+=base ; l <= r ; l/=2, r/=2 ) {
			if ( l % 2 == 1 ) ret += Count(T[l++], k);
			if ( r % 2 == 0 ) ret += Count(T[r--], k);
		}
		return ret;
	}
};
void process() {
	vector<int> A;
	SegmentTree st;
	int a, b, c, N, M, prevN, i, j;

	cin >> N ;
	A.resize(N);
	st.init(N);
	for ( i = 0 ; i < N ; i ++ ) {
		cin >> a ;
		st.T[ st.base + i].push_back(a);
	}
	st.build();

	cin >> M ;
	for ( prevN=0, i = 0 ; i < M ; i ++ ) {
		cin >> a >> b >> c ;
		a ^= prevN;
		b ^= prevN;
		c ^= prevN;
		cout << (prevN = st.query(a-1,b-1,c)) << '\n';
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


