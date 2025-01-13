#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long int ll;

enum FACE { UP=0, DOWN, LEFT, RIGHT, FRONT, BACK};
enum ROTATING { ROTATE_UP, ROTATE_DOWN, ROTATE_LEFT, ROTATE_RIGHT, ROLLING_LEFT, ROLLING_RIGHT };
FACE RUBIX_PATH[][4] = {
        {UP, FRONT, DOWN, BACK}, // X축 중심 위로 돌릴 때
        {UP, BACK, DOWN, FRONT}, // X축 중심 아래로 돌릴 때
        {FRONT, RIGHT, BACK, LEFT}, // Z축 중심 왼쪽으로 돌릴 때
        {FRONT, LEFT, BACK, RIGHT}, // Z축 중심 오른쪽으로 돌릴 때
        {UP, RIGHT, DOWN, LEFT}, // Y축 중심 왼쪽으로 회전할 때
        {UP, LEFT, DOWN, RIGHT}, // Y축 중심 오른쪽으로 회전할 때
};
int Rx[3][3][3] = {
    {
        {1, 0, 0},
        {0, 0, -1},
        {0, 1, 0},
    }
};
int Ry[3][3][3] = {
    {
        {0, 0, 1},
        {0, 1, 0},
        {-1, 0, 0},
    }
};
int Rz[3][3][3] = {
    {
        {0, -1, 0},
        {1, 0, 0},
        {0, 0, 1},
    }
};


struct Pos {
    int x, y, z;
    Pos operator *( int a[3][3]) {
        Pos ret = {0, 0, 0};
        int m[] = {x, y, z};
        int i;
        for ( i = 0 ; i < 3 ; i ++ ) {
            ret.x += a[0][i] * m[i];
            ret.y += a[1][i] * m[i];
            ret.z += a[2][i] * m[i];
        }
        return ret;
    }
};
ostream &operator <<(ostream &out, Pos &p) {
    out << '(' << p.z +1 << ',' << p.y +1<<',' << p.x +1<< ')';
    return out;
}
struct Face {
    char f[6]{};
    void rotate( ROTATING d ) {
        auto t = f[RUBIX_PATH[d][0]];
        for ( int i = 1 ; i < 4 ; i ++ ) f[RUBIX_PATH[d][i-1]] = f[RUBIX_PATH[d][i]];
        f[RUBIX_PATH[d][3]] = t;
    }
    bool operator == (Face &o) {
        for ( int i = 0 ; i < 6 ; i ++ )
            if ( f[i] != o.f[i] ) return false;
        return true;
    }
    bool operator != (Face &o) {
        return !( *this == o);
    }
};
struct Cube {
    Face c[3][3][3];
    int cnt{};
    void init() {
        int x, y, z, f;
        for ( z=0 ; z<3 ; z++ )
            for (y = 0; y <3; y++)
                for (x = 0; x <3; x++)
                    for ( f=0 ; f<6; f++)
                        c[z][y][x].f[f] = '.';

    }
    bool operator == (Cube &o) {
        int x, y, z;
        for ( z=0 ; z<3 ; z++ )
            for (y = 0; y <3; y++)
                for (x = 0; x <3; x++)
                    if ( c[z][y][x] != o.c[z][y][x])
                        return false;
        return true;
    }
    bool operator != (Cube &o) {
        return !( *this == o);
    }
    void rotate(int R[3][3], ROTATING rot) {
        int x, y, z;

        Face tmp[3][3][3] ;
        for ( z=-1 ; z<=1 ; z++ ) {
            for (y = -1; y <= 1; y++) {
                for (x = -1; x <= 1; x++) {
                    Pos p = {x, y, z};
                    auto p2 = p * R;
                    tmp[ p2.z+1 ][ p2.y+1 ][ p2.x+1 ] = c[z+1][y+1][x+1];
                    tmp[ p2.z+1 ][ p2.y+1 ][ p2.x+1 ].rotate(rot);
                }
            }
        }
        memcpy(c, tmp, sizeof(c));
    }
    void rotateX(bool ccw) {
        if ( ccw ) rotate(Rx[0], ROTATE_DOWN);
        else rotate(Rx[2], ROTATE_UP);
    }
    void rotateY(bool ccw) {
        if ( ccw ) rotate(Ry[0], ROLLING_RIGHT);
        else rotate(Ry[2], ROLLING_LEFT);
    }
    void rotateZ(bool ccw) {
        if ( ccw ) rotate(Rz[0], ROTATE_RIGHT);
        else rotate(Rz[2], ROTATE_LEFT);
    }

    void dump() {
        int i, j;
        for ( i = 0 ; i < 3 ; i ++ ) {
            cout << "    ";
            for (j = 0; j < 3; j++)
                cout << c[2][i][j].f[UP];
            cout << '\n';
        }
        for ( i = 0 ; i < 3 ; i ++ ) {
            for (j = 0; j < 3; j++) cout << c[i][j][0].f[LEFT]; cout << ' ';
            for (j = 0; j < 3; j++) cout << c[i][0][j].f[FRONT]; cout << ' ';
            for (j = 0; j < 3; j++) cout << c[i][j][2].f[RIGHT]; cout << ' ';
            for (j = 0; j < 3; j++) cout << c[i][2][j].f[BACK]; cout << ' ';
            cout << '\n';
        }
        for ( i = 0 ; i < 3 ; i ++ ) {
            cout << "    ";
            for (j = 0; j < 3; j++)
                cout << c[0][i][j].f[DOWN];
            cout << '\n';
        }
        cout << '\n';
    }

    ll score() {
        int i, j;
        ll ret = 0;
        for ( i = 0 ; i < 3 ; i ++ ) {
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[2][i][j].f[UP] == 'x' ? 1 : 0);
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[i][j][0].f[LEFT] == 'x' ? 1 : 0 );
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[i][0][j].f[FRONT] == 'x' ? 1 : 0 );
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[i][j][2].f[RIGHT] == 'x' ? 1 : 0 );
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[i][2][j].f[BACK] == 'x' ? 1 : 0 );
            for (j = 0; j < 3; j++) ret = ret * 2 + (c[0][i][j].f[DOWN] == 'x' ? 1 : 0);
        }
        return ret;
    }
};

int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
vector<string> M;
int H, W;
unordered_map<ll, int> CacheIndex;
void init(){
    int x, y, z, t;
    int i ;

    z=0;
    for ( i = 1 ; i < 3 ; i ++ )
        for ( y = 0 ; y < 3 ; y ++ )
            for ( x = 0 ; x < 3 ; x ++ )
                for ( t = 0 ; t < 3 ; t ++ ) {
                    Rx[i][y][x] += Rx[0][y][t] * Rx[i-1][t][x];
                    Ry[i][y][x] += Ry[0][y][t] * Ry[i-1][t][x];
                    Rz[i][y][x] += Rz[0][y][t] * Rz[i-1][t][x];
                }
}

bool isBox(int y, int x) {
    if ( y < 0 || x < 0 || y + 4 > H || x + 4 > W ) return false;
    if ( M[y+2][x+2] == '!' ) return false;
    if ( M[y][x] != '+' || M[y][x+2] != '-' || M[y][x+4] != '+' ) return false;
    if ( M[y+2][x] != '|' || M[y+2][x+4] != '|' ) return false;
    if ( M[y+4][x] != '+' || M[y+4][x+2] != '-' || M[y+4][x+4] != '+' ) return false;
    return true;
}
void readSpread(Cube &cube, int y, int x) {
    int i, j, d, n;
    for ( i = 0 ; i < 3 ; i ++ )
        for ( j = 0 ; j < 3 ; j ++ )
            cube.c[0][i][j].f[DOWN] = M[y+1+i][x+1+j];
    M[y+2][x+2] = '!';
//    cube.dump();

    for (d=0 ; d < 4 ; d ++ ) {
        int ty = y + dy[d] * 4;
        int tx = x + dx[d] * 4;
        if (isBox(ty, tx)) {
            if ( d == 0 ) cube.rotateY(false);
            else if ( d == 2 ) cube.rotateY(true);
            else if ( d == 1 ) cube.rotateX(true);
            else if ( d == 3 ) cube.rotateX(false);

            readSpread(cube, ty, tx);

            if ( d == 0 ) cube.rotateY(true);
            else if ( d == 2 ) cube.rotateY(false);
            else if ( d == 1 ) cube.rotateX(false);
            else if ( d == 3 ) cube.rotateX(true);
        }
    }
}
void updateCacheIndex(Cube &newCube, int index) {
    int i, j, k;

    for ( i = 0 ; i < 4 ; i ++ ) {
        for (j = 0; j < 4; j++) {
            for ( k = 0; k < 4; k++) {
                ll score = newCube.score();
//                cout << "Score = " << score << '\n';
//                newCube.dump();

                CacheIndex[score] = index;
                newCube.rotateX(true);
            }
            newCube.rotateY(true);
        }
        newCube.rotateZ(true);
    }
}
void process(int Case) {
    int i, j;
    cin >> H >> W ;
    cin.ignore();
    M.resize(H);
    vector<Cube> cubeList;

    for (auto &s: M) getline(cin, s);
    for ( i = 0 ; i < H - 5 ; i ++ ) {
        for ( j = 0 ; j < W - 5 ; j ++ ) {
            if (isBox(i, j)) {
                Cube cube{};
                cube.init();
                cube.cnt = 1;
                readSpread(cube, i, j);
                ll score = cube.score();
                auto idx = CacheIndex.find(score);
                if ( idx != CacheIndex.end() ) {
                    cubeList[ idx->second ].cnt ++;
                }
                else {
                    updateCacheIndex(cube, (int)cubeList.size());
                    cubeList.push_back(cube);
                }
            }
        }
    }
    vector<int> ans ;
    for (auto &c : cubeList) {
//        c.dump();
        ans.push_back(c.cnt);
    }

    std::sort(ans.begin(), ans.end(), greater<>());
    for (auto n: ans)
        cout << n << ' ';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
    init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
