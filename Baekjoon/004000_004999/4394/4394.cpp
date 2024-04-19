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
struct R {
    random_device rd;
    uniform_int_distribution<int> dis;
    mt19937 gen;
    R() {
        gen = mt19937 (rd());
        dis = uniform_int_distribution<int>(0, 1);
    }
    bool who() {
        return dis(gen);
    }
};
R r;

struct Data {
    deque<char> Card[2];
    int turn;
    Data () { turn=0; }

    char top() {
        return Card[turn].front();
    }
    void moveAnother() {
        Card[1-turn].push_front( Card[turn].front() );
        Card[turn].pop_front();
    }
    string take(Data &o){
        string ret ;
        while( !o.Card[ 1 - o.turn ].empty() ) {
            char c = o.Card[1 - o.turn].back();
            Card[1 - turn].push_front(c);
            o.Card[1 - o.turn].pop_back();
        }
        for (auto c : Card[ 1 - turn] )
            ret.push_back(c);
        return ret;
    }
    bool empty() {
        return Card[0].empty() && Card[1].empty();
    }
    void read(){
        string s;
        cin >> s;
        for (auto c: s) Card[turn].push_back(c);
    }
    void updateTurn() {

        if ( Card[turn].empty() ) {
            while ( !Card[1-turn].empty() ) {
                Card[turn].push_back(Card[1 - turn].back());
                Card[1-turn].pop_back();
            }
        }
    }
};
void process() {
    Data Jane, John;

    int i ;
    Jane.read();
    John.read();
random_device rd;
auto gen = mt19937 (rd());
auto dis = uniform_int_distribution<int>(0, 1);

    srand(time(NULL));
    for ( i = 0 ; i < 1000 ; i ++ ) {
        if ( Jane.empty() || John.empty() ) {
            if ( !Jane.empty()) cout << "Jane";
            else if ( !John.empty()) cout << "John";
            cout << " wins.\n";
            return;
        }
        Jane.updateTurn();
        John.updateTurn();
        bool isEqual = Jane.top() == John.top() ;
        Jane.moveAnother();
        John.moveAnother();

        if ( isEqual ) {
            bool bWho ;
            // case 1. Jane only. - WA
            // bWho = true;

            // case 2. John only. - WA
            // bWho = false;

            // case 3. srand(time(NULL)) & random - WA
            // bWho = random()/141%2 == 0 ;

            // case 4. m
            bWho = dis(gen) == 0;

            // case 4. - AC
//            bWho = random()/141%2 == 0 ;

            if ( bWho )
                cout << "Snap! for Jane: " << Jane.take(John) << '\n';
            else
                cout << "Snap! for John: " << John.take(Jane) << '\n';
        }
    }
    cout << "Keeps going and going ...\n";
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


