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
	bool B(char c) { return c == ' ' || c == '\n'; }
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
void SuffixArray(string &s, vector<int> &SA, vector<int> &LCP) {
    vector<int> Index, Freq, Group, NextGroup;
    int i, j, m = 26, len;
    int n = s.size();

    SA.resize(n);
    Freq.resize( max(n+1, m), 0);
    Index.resize(n);
    Group.resize(n);
    NextGroup.resize(n);
    for (i = 0; i < n; i++) Freq[Group[i] = s[i] - 'a']++;
    for (i = 1; i < m; i++) Freq[i] += Freq[i - 1];
    for (i = 0; i < n; i++) SA[--Freq[Group[i]]] = i;

    for (len = 1; len == 1 || m < n; len <<= 1) {
        for (j = 0; j < n; j++)
            NextGroup[j] = Group[j], Freq[Group[Index[j] = SA[j]]] = j;

        for (j = n - 1; j >= 0; j--)
            if(Index[j] >= len)
                SA[Freq[Group[Index[j] - len]]--] = Index[j] - len;

        for (j = n - 1; j >= 0; j--)
            if(Index[j] + len >= n)
                SA[Freq[Group[Index[j]]]--] = Index[j];

        for (j = m = 0; j < n; j++) {
            Group[SA[j]] = m;
            if (j + 1 == n || NextGroup[SA[j]] != NextGroup[SA[j + 1]] ||
                SA[j] + len >= n || NextGroup[SA[j] + len] != NextGroup[SA[j + 1] + len])
                m++;
        }
    }

    LCP.resize(n);
    for (len = j = 0; len < n; len++) if (Group[len]) {
        for (; s[len + j] == s[SA[Group[len] - 1] + j]; j++);
        LCP[Group[len]] = j; if(j) j--;
    }
}
void process() {
	string s;
	vector<int> sa, lcp;
	int n;
	cin >> n >>  s ;
	SuffixArray(s, sa, lcp);
	cout << *max_element(lcp.begin(), lcp.end()) << '\n';
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


