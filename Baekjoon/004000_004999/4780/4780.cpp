#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
pii Rot(pii a) {
    return {a.second, 4-a.first};
}
struct Shape {
    vector<pii> P;
    int sx;
    void rotate() {
        int minX=100000, minY=100000;
        for (auto &p: P) {
            p = Rot(p);
            minY = min(minY, p.first);
            minX = min(minX, p.second);
        }
        sx = 100000 ;
        for (auto &p: P) {
            p.first -= minY;
            p.second -= minX;
            if ( p.first == 0 ) sx = min(sx, p.second);
        }
        std::sort(P.begin(), P.end());
    }
    void dump() {
        bool A[4][4]={false,};
        int i, j;
        for (auto p: P) {
            A[p.first][p.second] = true;
        }
        cout << "sx = " << sx << '\n';
        for ( i = 0 ; i < 4 ; i ++ ) {
            for ( j = 0 ; j < 4 ; j ++ ) {
                cout << ( A[i][j] ? 'O' : '.' ) << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

Shape InitShape[7] = {
        {
                {{0, 0}, {0, 1}, {0, 2}, {0, 3}, }, 0,
        },
        {
                {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 0,
        },
        {
                {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, 0,
        },
        {
                {{0, 1}, {0, 2}, {1, 0}, {1, 1}}, 1,
        },
        {
                {{0, 0}, {1, 0}, {1, 1}, {1, 2}}, 0,
        },
        {
                {{0, 0}, {0, 1}, {0, 2}, {1, 0}}, 0,
        },
        {
                {{0, 1}, {1, 0}, {1, 1}, {1, 2}}, 1,
        }
};
vector<vector<Shape>> R;
void init() {
    int i, j ;

    for ( i = 0 ; i < 7 ; i ++ ) {
        R.emplace_back();
        for ( j = 0 ; j < 4 ; j ++ ) {
            bool f = false;
            for (auto &r: R.back() ) {
                if ( r.P == InitShape[i].P ) {
                    f = true;
                    break;
                }
            }
            if ( !f ) {
                R.back().push_back(InitShape[i]);
            }
            InitShape[i].rotate();
        }
//        cout << "Shape #" << i << "\n";
//        for (auto &r: R.back() ) {
//            r.dump();
//        }
    }
}
char Map[6][6];
struct UserShape {
    char name;
    int shapeIndex;
    bool used;
};
UserShape A[9];

bool CanFill(int y, int x, Shape &s) {
    int ty, tx;
    for ( auto p: s.P ) {
        ty = y + p.first ;
        tx = x + p.second - s.sx;
        if ( ty < 0 || tx < 0 || ty >= 6 || tx >= 6 ) return false;
        if ( Map[ty][tx] != 0 ) return false;
    }
    return true;
}
void Fill(int y, int x, Shape &s, char c) {
    int ty, tx;
    for ( auto p: s.P ) {
        ty = y + p.first ;
        tx = x + p.second - s.sx;

        Map[ty][tx] = c;
    }
}
void dumpMap() {
    int i, j;
    for ( i = 0 ; i < 6 ; i ++ ) {
        for ( j = 0 ; j < 6 ; j ++ ) {
            cout << ( Map[i][j] ? Map[i][j] : '.' ) ;
        }
        cout << '\n';
    }
    cout << endl;
}
bool F(int idx) {
    if ( idx >= 36 ) return true;
    int y, x;
    y = idx / 6;
    x = idx % 6;
    if ( Map[y][x] != 0 )
        return F(idx+1);

    for ( int i = 0 ; i < 9 ; i ++ ) {
        if ( A[i].used ) continue;
        A[i].used = true;

        for (auto &r : R[ A[i].shapeIndex ] ) {
            if (CanFill(y, x, r)) {
                Fill(y, x, r, A[i].name);
//                dumpMap();
                auto ret = F(idx+1);
                if ( ret )
                    return ret;
                Fill(y, x, r, 0);
            }
        }
        A[i].used = false;
    }
    return false;
}
bool fillMap() {
    int i, n;

    for ( i = 0 ; i < 9 ; i ++ ) {
        cin >> n;
        A[i].shapeIndex = n-1;
        A[i].name = (char)('A' + i);
        A[i].used = false;
    }

    return F(0);
}
void process() {
    int N ;
    int Case;
    int i, j;

    init();

    cin >> N ;
    for ( Case = 1 ; Case <= N ; Case ++, cout << '\n' ) {
        cout << "Data Set " << Case << '\n';
        memset(Map, 0, sizeof(Map));
        memset(A, 0, sizeof(A));
        if ( fillMap() ) {
            cout << "The floor may be tiled.\n";
            for ( i = 0 ; i < 6 ; i ++ ) {
                for ( j = 0 ; j < 6 ; j ++ ) {
                    cout << Map[i][j];
                }
                cout << '\n';
            }
        }
        else {
            cout << "The floor may not be tiled.\n";
        }
    }
    cout << "End of Output\n";
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


