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


struct Matrix{
    vector< vector<pii> > P[2];
    int curr;
    vector< vector<int> > A, ans;
    bool xy_rotated;
    Matrix (int y, int x){
        curr = 0;
        xy_rotated = false;
        A.resize(100, vector<int>(100));
        ans.resize(100, vector<int>(100));
        P[0].resize(4, vector<pii>(4));
        P[1].resize(4, vector<pii>(4));

        int w = X / 2 ;
        int h = Y / 2 ;
        for ( int i = 0 ; i < 2 ; i ++ ) {
            for ( int j = 0 ; j < 2 ; j ++ ) {
                int sy = i * h, sx = j * w;
                P[0][i*2][j*2] = {sy, sx};
                P[0][i*2+1][j*2] = {sy+h-1, sx};
                P[0][i*2][j*2+1] = {sy, sx+w-1};
                P[0][i*2+1][j*2+1] = {sy+h-1, sx+w-1};
            }
        }

    };

    void flipY() {
        int i, j;
        for ( i = 0 ; i < 2 ; i ++ )
            for ( j = 0 ; j < 4 ; j ++ )
                swap(P[curr][i][j], P[curr][4-1-i][j]);
    }
    void flipX() {
        int i, j;
        for ( i = 0 ; i < 4 ; i ++ )
            for ( j = 0 ; j < 2 ; j ++ )
                swap(P[curr][i][j], P[curr][i][4-1-j]);
    }
    void rot90() {
        int i, j;
        for ( i = 0 ; i < 4 ; i ++ )
            for ( j = 0 ; j < 4 ; j ++ )
                P[1-curr][i][j] = P[curr][4-1-j][i];
        swap(X, Y);
        xy_rotated = !xy_rotated;
        curr = 1 - curr;
    }
    void rot180() {
        int i, j;
        for ( i = 0 ; i < 4 ; i ++ )
            for ( j = 0 ; j < 4 ; j ++ )
                P[1-curr][i][j] = P[curr][4-1-i][4-1-j];
        curr = 1 - curr;
    }
    void rot270() {
        int i, j;
        for ( i = 0 ; i < 4 ; i ++ )
            for ( j = 0 ; j < 4 ; j ++ )
                P[1-curr][i][j] = P[curr][j][4-1-i];
        swap(X, Y);
        xy_rotated = !xy_rotated;
        curr = 1 - curr;
    }
#define COPY(fy,fx,ty,tx) do { \
    P[1-curr][(ty)+0][(tx)+0] =P[curr][(fy)+0][(fx)+0];\
    P[1-curr][(ty)+1][(tx)+0] =P[curr][(fy)+1][(fx)+0];\
    P[1-curr][(ty)+0][(tx)+1] =P[curr][(fy)+0][(fx)+1];\
    P[1-curr][(ty)+1][(tx)+1] =P[curr][(fy)+1][(fx)+1];\
} while (false);
    void rot90_group() {
        COPY(2, 0, 0, 0);
        COPY(2, 2, 2, 0);
        COPY(0, 2, 2, 2);
        COPY(0, 0, 0, 2);
        curr = 1 - curr;
    }

    void rot270_group() {
        COPY(0, 2, 0, 0);
        COPY(2, 2, 0, 2);
        COPY(2, 0, 2, 2);
        COPY(0, 0, 2, 0);
        curr = 1 - curr;
    }
    void fill(int sy, int sx, int ey, int ex, pii sp, pii ep) {
        int i, j, x, y, xp, yp;
        int init_y = sp.first, init_x = sp.second;

        yp = ep.first > sp.first ? 1 : ep.first < sp.first ? -1 : 0;
        xp = ep.second > sp.second ? 1 : ep.second < sp.second ? -1 : 0;

        if (xy_rotated ) {
            for (i = sx, y = init_y; i <= ex; i++, y += yp)
                for (j = sy, x = init_x; j <= ey; j++, x += xp)
                    ans[j][i] = A[y][x];
        }
        else {
            for (i = sy, y = init_y; i <= ey; i++, y += yp)
                for (j = sx, x = init_x; j <= ex; j++, x += xp)
                    ans[i][j] = A[y][x];
        }
    }
    void dump() {
        int i, j;

        int W = X / 2 ;
        int H = Y / 2 ;
        fill(0, 0, H-1, W-1, P[curr][0][0], P[curr][1][1]);
        fill(0, W, H-1, X-1, P[curr][0][2], P[curr][1][3]);
        fill(H, 0, Y-1, W-1, P[curr][2][0], P[curr][3][1]);
        fill(H, W, Y-1, X-1, P[curr][2][2], P[curr][3][3]);

        for ( i = 0 ; i < Y ; i ++ ) {
            for (j = 0; j < X; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void dumpP() {
        for ( int i = 0 ; i < 4 ; i ++ ) {
            for (int j = 0 ; j < 4 ; j ++ ) {
                cout << "(" << P[curr][i][j].first << ", " << P[curr][i][j].second << ") ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

void process() {
    int i, j, C, c ;
    cin >> Y >> X >> C ;
    Matrix mat(Y, X);

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> mat.A[ i ][ j ] ;

//    mat.dumpP();

    while ( C -- ) {
        cin >> c ;
        switch (c) {
            case 1: mat.flipY(); break;
            case 2: mat.flipX(); break;
            case 3: mat.rot90(); break;
            case 4: mat.rot270(); break;
            case 5: mat.rot90_group(); break;
            case 6: mat.rot270_group(); break;
        }
    }
//    mat.dumpP();
    mat.dump();

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


