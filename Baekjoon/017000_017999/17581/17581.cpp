#include <bits/stdc++.h>
using namespace std;
enum FACE {UP, LEFT, DOWN, RIGHT, ALL};
struct P2 { int x, y; };
struct P3 { int x, y, z; };
ostream &operator <<(ostream &out, const P3 &p) { cout << '(' << p.x << ',' << p.y << ',' << p.z << ") "; return out;}
ostream &operator <<(ostream &out, const P2 &p) { cout << '(' << p.x << ',' << p.y << ") "; return out;}

P2 R90(const P2& p, int N) { return { -p.y + (N-1), p.x }; }
P2 R180(const P2& p, int N) { return { -p.x + (N-1), -p.y + (N-1) };}
P2 R270(const P2& p, int N) { return { p.y, -p.x + (N-1) }; }
P2 RXm(const P2& p, int N) { return { -p.x + (N-1), p.y }; }
P3 Rx90(const P3& p, int N) { return { p.x, -p.z + (N-1), p.y }; }
P3 Rx180(const P3& p, int N) { return { p.x, -p.y + (N-1), -p.z + (N-1) };}
P3 Rx270(const P3& p, int N) { return { p.x, p.z, -p.y + (N-1) };}
P3 Ry90(const P3& p, int N) { return { p.z, p.y, -p.x + (N-1) };}
P3 Ry180(const P3& p, int N) { return { -p.x + (N-1), p.y, -p.z + (N-1) };}
P3 Ry270(const P3& p, int N) { return { -p.z + (N-1), p.y, p.x };}
P3 Rz90(const P3& p, int N) { return { -p.y + (N-1), p.x, p.z };}
P3 Rz180(const P3& p, int N) { return { -p.x + (N-1), -p.y + (N-1), p.z };}
P3 Rz270(const P3& p, int N) { return { p.y, -p.x + (N-1), p.z };}

typedef P3 (*P3Ptr)(const P3&, int );
typedef P2 (*P2Ptr)(const P2&, int );
typedef vector<string> BoardType;
typedef vector<BoardType> CubeType;

const int MaxBoard = 6;
const int MaxRotation = 4;
const int MaxN = 9;

int N;
vector<BoardType> Board[6];
CubeType Cube[2];
int CubeIndex;
vector<bool> Visit;
void boardRotate(BoardType &src, BoardType &desc, P2Ptr conv) {
    int x, y;
    P2 p;
    for ( y = 0 ; y < N ; y ++ ) {
        x=0, p = conv({x, y}, N);
        desc[p.y][p.x] = src[y][x];
        x=N-1, p = conv({x, y}, N);
        desc[p.y][p.x] = src[y][x];
    }
    for (x = 0; x < N; x++) {
        y=0, p = conv({x, y}, N);
        desc[p.y][p.x] = src[y][x];
        y=N-1, p = conv({x, y}, N);
        desc[p.y][p.x] = src[y][x];
    }
}
void boardInit(int boardIndex, BoardType &s) {
    int i;
    auto &b = Board[boardIndex];
    b.clear();
    b.resize(MaxRotation*2, s);

    for ( i = 1 ; i < MaxRotation ; i ++ ) boardRotate(b[i-1], b[i], R90);
    for ( i = 0 ; i < MaxRotation ; i ++ ) boardRotate(b[i], b[MaxRotation+i], RXm);
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
}

//      y(+)
//     /
//    /
//   /
//  /
// +---------------> x(+)
// |
// |
// |
// |
// z(+)
int getHash(string &s) {
    int ret=0;
    for (auto c: s)
        ret = (ret<<1) | (c=='.' ? 0 : 1);
    return ret;
}
void init() {
    int i;
    for ( i = 0 ; i < MaxBoard ; i ++ ) Board[ i ].clear();
    CubeIndex = 0;
    Visit.clear();
    Cube[0].clear();
    Cube[1].clear();
//    BoardHash.clear();
    Cube[0].resize(N, vector(N, string(N, '.')));
    Cube[1].resize(N, vector(N, string(N, '.')));
}
void cubeRotate(P3Ptr conv) {
    int x, y, z;
    P3 p;

    for (z = 0; z < N; z++) {
        for (x = 0; x < N; x++) {
            y=0, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
            y=N-1, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
        }
    }
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            z=0, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
            z=N-1, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
        }
    }

    for (z = 0; z < N; z++) {
        for (y = 0; y < N; y++) {
            x=0, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
            x=N-1, p = conv({x, y, z}, N);
            Cube[1-CubeIndex][p.z][p.y][p.x] = Cube[CubeIndex][z][y][x];
        }
    }
    CubeIndex = 1 - CubeIndex;
}
void cubeRollUp() { cubeRotate(Rx90);}
void cubeRollDown() { cubeRotate(Rx270);}
void cubeTurnLeft() { cubeRotate(Rz270);}
void cubeTurnAround() { cubeRotate(Rz180);}
void cubeTurnRight() { cubeRotate(Rz90);}
void cubeApply(BoardType &board, char c) {
    int x, y, z;
    for (z = 0; z < N; z++) {
        for (x = 0; x < N; x++) {
            if (board[z][x] != '.')
                Cube[CubeIndex][z][0][x] = c;
        }
    }
}
bool cubeCan(BoardType &board) {
    int x, y, z;
    for (x = 0; x < N; x++) {
        z=0;
        if (board[z][x] != '.' && Cube[CubeIndex][z][0][x] != '.')
            return false;
        z=N-1;
        if (board[z][x] != '.' && Cube[CubeIndex][z][0][x] != '.')
            return false;
    }
    for (z = 0; z < N; z++) {
        x=0;
        if (board[z][x] != '.' && Cube[CubeIndex][z][0][x] != '.')
            return false;
        x=N-1;
        if (board[z][x] != '.' && Cube[CubeIndex][z][0][x] != '.')
            return false;
    }
    return true;
}
bool cubeCheck() {
    int x, y, z;
    for (z = 0; z < N; z++) {
        for (x = 0; x < N; x++) {
            if (Cube[CubeIndex][z][0][x] == '.') return false;
            if (Cube[CubeIndex][z][N - 1][x] == '.') return false;
        }
    }
    for (z = 0; z < N; z++) {
        for (x = 0; x < N; x++) {
            if (Cube[CubeIndex][0][z][x] == '.') return false;
            if (Cube[CubeIndex][N - 1][z][x] == '.') return false;
        }
    }
    for (z = 0; z < N; z++) {
        for (x = 0; x < N; x++) {
            if (Cube[CubeIndex][z][x][0] == '.') return false;
            if (Cube[CubeIndex][z][x][N - 1] == '.') return false;
        }
    }
    return true;
}

void input() {
    int i, j;
    Visit.resize(MaxBoard, false);

    vector<string> in(N);
    for (i = 0; i < MaxBoard; i++) {
        for (j = 0; j < N; j++)
            cin >> in[j];
        boardInit(i, in);
    }
}

bool dfs(int depth) {
    int i, j;
    switch (depth) {
        case 0:
            cubeApply(Board[0][0], '0' + depth);
            Visit[0] = true;
            if (dfs(depth + 1)) return true;
            break;
        case 1:
        case 2:
        case 3:
            cubeRollUp();
            for (i = 0; i < MaxBoard; i++) {
                if (Visit[i]) continue;
                for (auto &b: Board[i]) {
                    if (!cubeCan(b)) continue;
                    cubeApply(b, '0' + depth);
                    Visit[i] = true;
                    if (dfs(depth + 1)) return true;
                    Visit[i] = false;
                    cubeApply(b, '.');
                }
            }
            cubeRollDown();
            break;
        case 4:
            cubeTurnLeft();
            for (i = 0; i < MaxBoard; i++) {
                if (Visit[i]) continue;
                for (auto &b: Board[i]) {
                    if (!cubeCan(b)) continue;
                    cubeApply(b, '0' + depth);
                    Visit[i] = true;
                    if (dfs(depth + 1)) return true;
                    Visit[i] = false;
                    cubeApply(b, '.');
                }
            }
            cubeTurnRight();
            break;
        case 5:
            cubeTurnAround();
            for (i = 0; i < MaxBoard; i++) {
                if (Visit[i]) continue;
                for (auto &b: Board[i]) {
                    if (!cubeCan(b)) continue;
                    cubeApply(b, '0' + depth);
                    Visit[i] = true;
                    if (cubeCheck())
                        return true;
                    Visit[i] = false;
                    cubeApply(b, '.');
                }
            }
            cubeTurnAround();
            break;
    }
    return false;
}
void process() {
    if (dfs( 0))
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	while ( cin >> N && N ) {
        init();
        input();
        process();
    }
    return 0;
}
