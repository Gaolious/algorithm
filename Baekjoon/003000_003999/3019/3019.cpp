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
typedef struct  {
    char C[16];
} SHAPE ;
SHAPE InitShape[7] = {
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0}
};
struct Data {
    vector<pii> pos;
    vector<int> HeightByX;
    int w, h ;
    bool operator == ( Data &o ) const {
        if ( w != o.w || h != o.h ) return false;
        if ( pos.size() != o.pos.size() ) return false;
        for ( int i = 0 ; i < pos.size() ; i ++ )
            if ( pos[i] != o.pos[i]) return false;
        return true;
    }
    void dump() {
        char A[4][4]={0, };
        cout << "W = " << w << ", H = " << h << '\n';
        for ( auto &[y,x] : pos )
            A[ y ][ x ] = '#';

        for ( int y = 0 ; y < h ; y ++ ) {
            for ( int x = 0 ; x < w ; x ++ ) {
                if ( A[y][x] ) cout << '#' ;
                else cout << '.';
            }
            cout << '\n';
        }
    }
};
vector<Data> RotatedShape[7];
vector<int> A;

void Rotate() {
    int i, j, y, x ;
    int minX, maxX, minY, maxY;
    char A[4][4][4]{};
    for ( i = 0 ; i < 7 ; i ++ ) {

        for ( j = 0 ; j < 16 ; j ++ )
            A[0][j/4][j%4] = InitShape[i].C[j];

        for ( j = 1 ; j < 4 ; j ++ ) {
            for ( y = 0 ; y < 4 ; y ++ ) {
                for ( x = 0 ;x < 4 ; x ++ ) {
                    A[j][y][x] = A[j-1][3-x][y];
                }
            }
        }
        for ( j = 0 ; j < 4 ; j ++ ) {
            Data tmp;

            minX = 5, maxX = -1;
            minY = 5, maxY = -1;
            for ( y = 0 ; y < 4 ; y ++ ) {
                for ( x = 0 ;x < 4 ; x ++ ) {
                    if ( A[j][y][x] ) {
                        minX = min(minX, x);
                        minY = min(minY, y);
                        maxX = max(maxX, x);
                        maxY = max(maxY, y);
                        tmp.pos.emplace_back(y, x);
                    }
                }
            }
            maxX -= minX; maxY -= minY;
            for (auto &[ty, tx] : tmp.pos) { ty -= minY; tx -= minX; }
            sort(tmp.pos.begin(), tmp.pos.end());
            tmp.w = maxX + 1; tmp.h = maxY + 1;
            bool found = false ;
            for (auto &prev : RotatedShape[i]) {
                if ( prev == tmp ) {
                    found = true ;
                    break;
                }
            }
            if ( !found ) {
                tmp.HeightByX.resize(tmp.w, 0);
                for (auto p : tmp.pos ) {
                    tmp.HeightByX[ p.second ] = max( tmp.HeightByX[ p.second ], p.first );
                }
                RotatedShape[i].push_back(tmp);

            }
        }
    }
}
void dumpShape() {
    for ( auto &shape_list : RotatedShape ) {
        for ( auto &shape: shape_list ) {
            shape.dump();
        }
    }
}
bool drop(Data &shape, int x) {
    int y = 0;
    int i, j ;
    if ( x + shape.w > X ) return false;

    for ( j = 0 ; j < shape.HeightByX.size() ; j ++ ) {
        y = max(y, A[x+j] + shape.HeightByX[j]);
    }
    // base point : (y,x)
    for ( j = 0 ; j < shape.HeightByX.size() ; j ++ ) {
        if ( A[x + j] + shape.HeightByX[j] != y )
            return false;
    }
    return true;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int shapeNo;
    cin >> X >> shapeNo ;
    A.resize(X, 0);
    for (auto &n : A ) cin >> n;
    Rotate();

    // dumpShape();
    int cnt = 0 ;
    int j ;
    for ( j = 0 ; j < X ; j ++ ) {
        for (auto &shape : RotatedShape[shapeNo-1] ) {
            if ( j + shape.w > X ) continue;
            // cout << "Drop in X=" << j << '\n';
            // shape.dump();

            if ( drop(shape, j) ) {
                cnt ++;
                // cout << "OK\n";
            }
            else {
                // cout << "NO\n";
            }
            // cout << '\n';

        }
    }
    cout << cnt << '\n';
    return 0;
}


