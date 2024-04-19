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

#define MAX_BIT (32)


//struct Trie {
//    ull n;
//    bool isEnd;
//    Trie *Child[2];
//};
//Trie CacheTrie[ 3'200'000 + 1 ];
//int tail = -1;
//Trie *NewNode() {
//    return &(CacheTrie[++tail]);
//}
//void AddTrie(Trie *root, ull n) {
//    int idx;
//    for ( int i = (MAX_BIT-1) ; i >= 0 ; i -- ) {
//        idx = ( (n>>i) & 1) ? 1 : 0;
//        if (root->Child[idx] == nullptr ) root->Child[idx] = NewNode();
//        root = root->Child[idx];
//    }
//    root->isEnd = true;
//    root->n = n;
//}
//ull FindTrie(Trie *root, ull n) {
//    int idx;
//    for ( int i = (MAX_BIT-1) ; i >= 0 && root ; i -- ) {
//        idx = ( (n>>i) & 1) ? 0 : 1;
//        if (root->Child[idx] == nullptr ) idx = 1 - idx;
//        root = root->Child[idx];
//    }
//    return ( root && root->isEnd ) ? (root->n ^ n) : n;
//}
void dump(ull n) {
    cout << n << " : " ;
    for ( int i = (MAX_BIT-1) ; i >= 0 ; i -- ) {
        cout << ( ( (n>>i) & 1 ) ? 1 : 0 ) ;
        if ( (MAX_BIT-i) % 4 == 0 ) cout << ' ';
    }
    cout << '\n';
}
//void process() {
//    int N;
//    memset(CacheTrie, 0, sizeof(CacheTrie));
//    tail = -1;
//    ull ans = 0, x;
//    Trie *root = NewNode();
//    cin >> N ;
//    vector<ull> A(N);
//    x = 0;
//    AddTrie(root, 0);
//
//    for (auto &n: A) {
//        cin >> n;
//        n ^= x;
//        AddTrie(root, x);
//        x = n;
//    }
//    ans = 0;
//    for (auto n: A) {
//        ans = max(ans, FindTrie(root, n) );
//    }
//#ifdef AJAVA_DEBUG
//    for (auto n: A) {
//        dump(n);
//    }
//#endif
//    cout << ans << '\n';
//}

pii FindRange( vector<ull> &X, int left, int right, int bit, bool flag) {
    int l = left, r = right, m;
    int min1=left, max0=right;

    while ( l <= r ) {
        m = (l+r) / 2;
        if ( ( X[m] >> bit ) & 1 ) {
            r = m - 1;
            min1 = m;
        }
        else {
            l = m + 1;
            max0 = m;
        }
    }
    if ( flag )
        return { min1, right} ;
    else
        return {left, max0};
}
void process() {
    int N, i, j;
    ull ans = 0, x;
    cin >> N ;
    vector<ull> A(N), X(N);
    x = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[ i ] ;
        X[ i ] = A[ i ] ^ ( i == 0 ? 0 : X[i-1] );
        ans = max(ans, X[i]);
    }
    sort(X.begin(), X.end());

    int l, r ;
#ifdef AJAVA_DEBUG
    cout << "A : \n";
    for ( i = 0 ; i < N ; i ++ ) dump(A[i]);
    cout << "X : \n";
    for ( i = 0 ; i < N ; i ++ ) dump(X[i]);
#endif

    for ( i = 0 ; i < N ; i ++ ) {
        l = 0 , r = i;
        for ( j = MAX_BIT-1 ; j >= 0 && l < r ; j -- )
        {
            x = (X[i] >> j) & 1 ;
            auto ret = FindRange(X, l, r, j, x == 0);
            l = ret.first, r = ret.second;
        }
        ans = max( ans, X[l] ^ X[i] );
    }
    cout << ans << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int T ;
    cin >> T;
    while ( T-- )
        process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


