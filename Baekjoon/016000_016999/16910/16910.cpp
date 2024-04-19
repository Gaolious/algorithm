#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
// constexpr int SZ = 1 << 20;
//
// class INPUT {
// private:
// 	char _b[SZ];
// 	int ri, ni;
// 	bool _e, _g;
// public:
// 	explicit operator bool() { return !_e; }
// 	bool B(char c) { return c <= ' '; }
// 	bool E(char c) { return c == '\0'; }
// 	char C() {
// 		if (ri == ni) {
// 			ni = fread(_b, sizeof(char), SZ, stdin);
// 			if (ni == 0) return 0;
// 			ri = 0;
// 		}
// 		return _b[ri++];
// 	}
// 	char ReadChar() {
// 		char ret = C();
// 		for (; B(ret); ret = C());
// 		return ret;
// 	}
// 	template<typename T> T ReadInt() {
// 		T ret = 0; char cur = C(); bool flag = 0;
// 		for (; B(cur); cur = C());
// 		if (cur == '-') flag = 1, cur = C();
// 		for (; !B(cur) && !E(cur); cur = C()) ret = 10 * ret + (cur & 15);
// 		if (E(cur)) _e = 1;
// 		return flag ? -ret : ret;
// 	}
// 	string ReadString() {
// 		string ret; char cur = C();
// 		for (; B(cur); cur = C());
// 		for (; !B(cur) && !E(cur); cur = C()) ret.push_back(cur);
// 		if (E(cur)) _e = 1;
// 		return ret;
// 	}
// 	double ReadDouble() {
// 		string ret = ReadString();
// 		return stod(ret);
// 	}
// 	string getline() {
// 		string ret; char cur = C();
// 		for (; cur != '\n' && !E(cur); cur = C()) ret.push_back(cur);
// 		if (_g) _e = 1;
// 		if (E(cur)) _g = 1;
// 		return ret;
// 	}
// 	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
// } _in;
//
// class OUTPUT {
// private:
// 	char _b[SZ];
// 	int wi;
// public:
// 	~OUTPUT() { Flush(); }
// 	explicit operator bool() { return 1; }
// 	void Flush() {
// 		fwrite(_b, sizeof(char), wi, stdout);
// 		wi = 0;
// 	}
// 	void WriteChar(char c) {
// 		if (wi == SZ) Flush();
// 		_b[wi++] = c;
// 	}
// 	template<typename T> int GetSize(T n) {
// 		int ret = 1;
// 		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
// 		return ret;
// 	}
// 	template<typename T> void WriteInt(T n) {
// 		int sz = GetSize(n);
// 		if (wi + sz >= SZ) Flush();
// 		if (n < 0) _b[wi++] = '-', n = -n;
// 		for (int i = sz; i-- > 0; n /= 10) _b[wi + i] = n % 10 | 48;
// 		wi += sz;
// 	}
// 	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
// 	void WriteDouble(double d) { WriteString(to_string(d)); }
// } _out;
//
// /* operators */
// INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
// INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
// template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
// INPUT& operator>> (INPUT& in, T& i) {
// 	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
// 	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }
//
// OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
// OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
// template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
// OUTPUT& operator<< (OUTPUT& out, T i) {
// 	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
// 	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }
//
// /* macros */
// #define fastio 1
// #define cin _in
// #define cout _out
// #define istream INPUT
// #define ostream OUTPUT

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1000000000000000001ll;
struct Data {
	ll q, l, r;
};
vector<Data> A;
vector<ll> X;
struct LazySegmentTree {
	struct Node {
        ll sum;
		ll lazy;
	};
	Node Default = {0, 0};
	int base{};
	vector<Node> T{};
	int N{}, H{} ;
	LazySegmentTree(int n) {
		N = n;
		H = ceil( log2(n) );
		base = 1 << int( H );
		T.resize( base * 2, Default);
	}
	Node Merge(Node l, Node r) {
		return {l.sum+r.sum,0} ;
	}
	void propagate(int idx, int s, int e) {
		if ( T[idx].lazy ) {
			if ( T[idx].lazy == 1 ) {
                T[idx].sum = 0;
                if ( s != e ) {
                    T[idx*2].lazy = 1 ;
                    T[idx*2+1].lazy = 1 ;
                }
            }
            else if ( T[idx].lazy == 2 ) {
                T[idx].sum = (e-s+1);
                if ( s != e ) {
                    T[idx*2].lazy = 2 ;
                    T[idx*2+1].lazy = 2 ;
                }
            }
            else if ( T[idx].lazy == 3 ) {
                T[idx].sum = (e-s+1) - T[idx].sum;
                if ( s != e ) {
                    T[idx*2].lazy ^= 3 ;
                    T[idx*2+1].lazy ^= 3 ;
                }
            }

			T[idx].lazy = 0;
		}
	}
	void Update(int idx, int s, int e, int l, int r, int lazy) {
		propagate(idx, s, e);
		if ( r < s || e < l ) return;
		if ( l <= s && e <= r ) {
			T[idx].lazy = lazy;
			propagate(idx, s, e);
		}
		else {
			int m = (s+e)/2;
			Update(idx*2, s, m, l, r, lazy);
			Update(idx*2+1, m+1, e, l, r, lazy);
			T[idx] = Merge(T[idx*2], T[idx*2+1]);
		}
	}
    void Init(int idx, int s, int e) {
        if ( s == e ) {
            T[idx].lazy = 0;
            T[idx].sum = 1;
        }
        else {
            int m = (s+e)/2;
            Init(idx*2, s, m);
            Init(idx*2+1, m+1, e);
            T[idx] = Merge(T[idx*2], T[idx*2+1]);
        }
    }
	ll Query(int idx, int s, int e, int k) {
        propagate(idx, s, e);
        if ( s == e ) return X[s];
        int m = (s+e)/2;
        propagate(idx*2, s, m);
        propagate(idx*2+1, m+1, e);
        return ( T[idx*2].sum >= k ) ? Query(idx*2, s, m, k) : Query(idx*2+1, m+1, e, k);
	}
	void dump() {
		int width = 5, prevW;
		queue<pii> Q[2];
		int turn = 0;
		Q[turn].emplace(1, (1<<H)*width );
		for ( int i = 0 ; i <= H ; i ++, turn = 1 - turn ) {
			prevW = 0;
			while (!Q[turn].empty()) {
				auto [idx, w] = Q[turn].front();
				Q[turn].pop();
				cout << setw(w - prevW) << ' ';
				cout << setw(2) << T[idx].sum << '/' << setw(2) << T[idx].lazy ;
				Q[1-turn].emplace(idx*2, w -  ( 1 << (H-i-1) ) * width );
				Q[1-turn].emplace(idx*2+1, w + ( 1 << (H-i-1) ) * width);
				prevW = w + width;
			}
			cout << endl;
		}
        cout << endl;
	}
};
int N ;
void Input() {
	cin >> N ;
	A.resize(N);
	X.push_back(1);
	for (int i = 0 ; i < N ; i ++ ) {
		cin >> A[i].q >> A[i].l >> A[i].r ;
		for ( auto k : {A[i].l, A[i].r} ) {
			for (auto d: {-1, 0, 1}) {
				if ( k + d >= 1 )
					X.push_back(k+d);
			}
		}
	}
	sort(X.begin(), X.end());
	X.erase( unique(X.begin(), X.end()), X.end());
	for ( auto &[q, l, r] : A) {
		l = lower_bound(X.begin(), X.end(), l) - X.begin();
		r = lower_bound(X.begin(), X.end(), r) - X.begin();
	}
}

void process() {
	int i ;
	Input();
	int N = X.size();
    LazySegmentTree lst(N) ;
    lst.Init(1, 0, N-1);
//	lst.dump();
	for ( auto [q, l, r] : A) {
		 if ( q == 1 ) lst.Update(1, 0, N-1, l, r, 1);
		 else if ( q == 2 ) lst.Update(1, 0, N-1, l, r, 2);
		 else if ( q == 3 ) lst.Update(1, 0, N-1, l, r, 3);

//         lst.dump();
		 cout << lst.Query(1, 0, N-1, 1) << '\n';
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