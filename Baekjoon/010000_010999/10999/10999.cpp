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

struct LazySegmentTree {
    // 0-index
    struct Node {
        __int128 sum;
        __int128 lazy;
    };
    vector<Node> T;
    int base{};
    int N{}, H{} ;
    LazySegmentTree(int n) {
        N = n;
        H = ceil( log2(n) );
        base = 1 << int( H );
        T.resize( base * 2);
    }
    Node Merge(Node a, Node b) {
        return {a.sum + b.sum, 0};
    }
    void LazyUpdate(int idx, int s, int e) {
        if ( T[idx].lazy ) {
            T[idx].sum += 1ll * (e-s+1) * T[idx].lazy;
            if ( s != e ) {
                T[idx*2].lazy += T[idx].lazy;
                T[idx*2+1].lazy += T[idx].lazy;
            }
            T[idx].lazy = 0;
        }
    }

    void Update(int idx, int s, int e, int l, int r, ll diff) {
        LazyUpdate(idx, s, e);
        if ( s > r || e < l ) return;
        if ( l <= s && e <= r ) {
            T[idx].lazy += diff;
            LazyUpdate(idx, s, e);
        }
        else {
            int m ;
            m = ( s + e ) / 2 ;
            Update(idx * 2, s, m, l, r, diff);
            Update(idx * 2 + 1, m + 1, e, l, r, diff);
            T[idx] = Merge(T[idx*2], T[idx*2+1]);
        }
    }
    Node query(int idx, int s, int e, int l, int r ) {
        LazyUpdate(idx, s, e);
        if (s > r || e < l ) return {0,0};
        if (l <= s && e <= r) return T[idx];
        int m = ( s + e ) / 2 ;
        return Merge(query(idx * 2, s, m, l, r), query(idx * 2 + 1, m + 1, e, l, r));
    }
	void Init(int idx, int s, int e, vector<ll> &A) {
		if ( s == e ) {
			T[idx].sum = A[s];
			return;
		}
		int m = (s+e)/2;
		Init(idx*2, s, m, A);
		Init(idx*2+1, m+1, e, A);
		T[idx] = Merge(T[idx*2], T[idx*2+1]);
	}
};


void process() {
	int N, M, K;
	int i, j ;
	int a, b, c, d;

	cin >> N >> M >> K;

	vector<ll> A(N+1);
	LazySegmentTree lst(N);

	for ( i = 0 ; i < N ; i ++ ) cin >> A[i];

	lst.Init(1, 0, N-1, A);
//    lst.dump();

	while ( M > 0 || K > 0 ) {
		cin >> a >> b >> c;
		if ( a == 1 ) {
			cin >> d ;
			lst.Update(1, 0, N-1, b-1, c-1, d);
			M--;
		}
		else if ( a == 2 ) {
			cout << lst.query(1, 0, N-1, b-1, c-1).sum << '\n';
			K--;
		}
//        lst.dump();
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


