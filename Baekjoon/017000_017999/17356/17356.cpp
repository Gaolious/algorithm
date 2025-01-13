#include <bits/stdc++.h>
using namespace std;
int N, firstMask, lastMask, allMask;

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
typedef array<int, 3> P3; // x,y,z
typedef array<int, 2> P2; // x,y
ostream &operator <<(ostream &out, const P3 &p) { cout << '(' << p[0] << ',' << p[1] << ',' << p[2] << ") "; return out;}
ostream &operator <<(ostream &out, const P2 &p) { cout << '(' << p[0] << ',' << p[1] << ") "; return out;}
P3 Rx90(const P3& p) { // RUBIX_PATH[1]
    return { p[0], -p[2] + (N-1), p[1] };
}
P3 Rx180(const P3& p) {
    return { p[0], -p[1] + (N-1), -p[2] + (N-1) };
}
P3 Rx270(const P3& p) { // RUBIX_PATH[0]
    return { p[0], p[2], -p[1] + (N-1) };
}
P3 Ry90(const P3& p) { // RUBIX_PATH[5]
    return { p[2], p[1], -p[0] + (N-1) };
}
P3 Ry180(const P3& p) {
    return { -p[0] + (N-1), p[1], -p[2] + (N-1) };
}
P3 Ry270(const P3& p) { // RUBIX_PATH[4]
    return { -p[2] + (N-1), p[1], p[0] };
}
P3 Rz90(const P3& p) { // RUBIX_PATH[3]
    return { -p[1] + (N-1), p[0], p[2] };
}
P3 Rz180(const P3& p) {
    return { -p[0] + (N-1), -p[1] + (N-1), p[2] };
}
P3 Rz270(const P3& p) { // RUBIX_PATH[2]
    return { p[1], -p[0] + (N-1), p[2] };
}
P2 R90(const P2& p) {
    return { N-1-p[1], p[0] };
}
typedef P3 (*RotFuncPtr)(const P3&);
string bin(int n){
    string ret ;
    for (int i = N-1 ; i >= 0 ; i -- )
        ret.push_back( ( n & (1 << i ) ) ? '1' : '0' );
    return ret;
}
struct Board {
    vector< vector<bool> > C[8];
    void Set(int y, int x) {
        P2 p = {x, y};
        for ( int i = 0 ; i < 4 ; i ++ ) {
            C[0+i][ p[1] ][ p[0] ] = true;
            C[4+i][ p[1] ][ N-1 - p[0] ] = true;
            p = R90(p);
        }
    }
    int mask(int nth) {
        int ret = 0 ;
        for ( int i = 0 ; i < N ; i ++ )
            ret = (ret << 1 ) | (C[nth][N-1][i]?1:0);
        return ret;
    }
    void init(vector<string> &S) {
        int i;
        for (i = 0 ; i < 8 ; i ++ )
            C[i].resize(N, vector<bool>(N));

        for ( i = 0 ; i < N ; i ++ ) {
            if ( S[0][i] == 'X' ) Set( 0, i);
            if ( S[N-1][i] == 'X' ) Set( N-1, i);
        }
        for ( i = 1 ; i < N - 1 ; i ++ ) {
            if ( S[i][0] == 'X' ) Set( i, 0 );
            if ( S[i][N-1] == 'X' ) Set( i, N-1);
        }
    }
    void dump(vector<int> idx = {}) {
        int i, j, k;
        vector<bool> F(N);
        for ( auto n: idx) F[n] = true;

        for ( k = 0 ; k < 8 ; k ++ ) {
            if ( F[k] )
                cout << setw(N-2) << '[' << k << "] ";
            else
                cout << setw(N) << k << " ";
        }
        cout << '\n';
        for ( k = 0 ; k < 8 ; k ++ ) cout << setw(N) << bin(mask(k)) << " ";
        cout << '\n';
        for ( i = 0 ; i < N ; i ++ ) {
            for ( k = 0 ; k < 8 ; k ++ ) {
                for (j = 0; j < N; j++) {
                    if (C[k][N - 1 - i][j]) cout << 'X';
                    else cout << '.';
                }
                cout << ' ';
            }
            cout << '\n';
        }
        cout << endl;
    }
};
struct Cube{
    vector< vector< vector<char> > > C[2];
    int curr;
    void init() {
        C[0].resize(N, vector(N, vector<char>(N)));
        C[1].resize(N, vector(N, vector<char>(N)));
        curr = 0;
    }
    void rotate(RotFuncPtr fn) {
        int i, j;
        P3 q, p;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                p = {j, i, N-1};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];

                p = {j, i, 0};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];

                p = {j, N-1, i};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];

                p = {j, 0, i};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];

                p = {N-1, j, i};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];

                p = {0, j, i};
                q = fn(p);
                C[1-curr][q[2]][q[1]][q[0]] = C[curr][p[2]][p[1]][p[0]];
            }
        }
        curr = 1 - curr;
    }
    void rotateRollUp() {// X축 기준 위로 올림
        rotate(Rx270);
    }
    void rotateRollDown() {// X축 기준 위로 올림
        rotate(Rx90);
    }
    void rotateTurnLeft() {// Z축 기준 왼쪽
        rotate(Rz270);
    }
    void rotateTurnAround() {// Z축 기준 180
        rotate(Rz180);
    }
    void rotateTurnRight() {// Z축 기준 90
        rotate(Rz90);
    }
    bool checkDup(vector< vector<bool> > &board) {
        int i = 0 ;
        for ( i = 0 ; i < N ; i ++ ) {
            if (C[curr][N - 1][0][i] && board[N-1][i]) // UP
                return false;
            if (C[curr][0][0][i] && board[0][i]) // down
                return false;
            if (C[curr][i][0][0] && board[i][0]) // left
                return false;
            if (C[curr][i][0][N - 1] && board[i][N - 1]) // right
                return false;
        }
        return true;
    }

    bool isFit(vector< vector<bool> > &board, FACE f ) {
        int i = 0 ;
        switch (f) {
            case UP:
                for ( i = 1 ; i < N-1 ; i ++ )
                    if (!C[curr][N - 1][0][i] && !board[N-1][i])
                        return false;
                break;
            case LEFT:
                for ( i = 1 ; i < N-1 ; i ++ )
                    if (!C[curr][i][0][0] && !board[i][0])
                        return false;
                break;
            case DOWN:
                for ( i = 1 ; i < N-1 ; i ++ )
                    if (!C[curr][0][0][i] && !board[0][i])
                        return false;
                break;
            case RIGHT:
                for ( i = 1 ; i < N-1 ; i ++ )
                    if (!C[curr][i][0][N - 1] && !board[i][N - 1])
                        return false;
                break;
        }
        return true;
    }
    bool isFitAll(vector< vector<bool> > &board ) {
        int i = 0 ;

        for ( i = 0 ; i < N ; i ++ ) {
            if (!C[curr][N - 1][0][i] && !board[N - 1][i])
                return false;
            if (!C[curr][i][0][0] && !board[i][0])
                return false;
            if (!C[curr][0][0][i] && !board[0][i])
                return false;
            if (!C[curr][i][0][N - 1] && !board[i][N - 1])
                return false;
        }
        return true;
    }
    int getPossibleMask() {
        int i, bit = 0 ;
        for ( i = 0 ; i < N ; i ++)
            bit = (bit<<1) | (C[curr][N-1][0][i] ? 1 : 0); // Z=n-1, y=0, x=i

        bit= (~bit) & allMask;
        return bit;
    }
    void Set(vector<vector<bool>> &board, char flag) {
        int i, j ;
        for ( i = 0 ; i < N ; i ++ )
            for ( j = 0 ; j < N ; j ++ )
                if ( board[i][j] )
                    C[curr][i][0][j] = flag;
    }
    void dump() {
        int i, j;
        string padding (N, ' ');

        for ( i = 0 ; i < N ; i ++ ) {
            cout << padding << ' ';
            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][N-1][N-1-i][j] ) cout << C[curr][N-1][N-1-i][j];
                else cout << '.';
            }
            cout << '\n';
        }
        cout << '\n';

        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][N-1-i][N-1-j][0] ) cout << C[curr][N-1-i][N-1-j][0];
                else cout << '.';
            }
            cout << ' ';
            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][N-1-i][0][j] ) cout << C[curr][N-1-i][0][j];
                else cout << '.';
            }
            cout << ' ';

            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][N-1-i][j][N-1] ) cout << C[curr][N-1-i][j][N-1];
                else cout << '.';
            }
            cout << '\n';
        }
        cout << '\n';
        for ( i = 0 ; i < N ; i ++ ) {
            cout << padding << ' ';
            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][0][i][j] ) cout << C[curr][0][i][j];
                else cout << '.';
            }
            cout << '\n';
        }
        cout << '\n';
        for ( i = 0 ; i < N ; i ++ ) {
            cout << padding << ' ';
            for ( j = 0 ; j < N ; j ++ ) {
                if ( C[curr][i][N-1][j] ) cout << C[curr][i][N-1][j];
                else cout << '.';
            }
            cout << '\n';
        }
        cout << endl;
    }
};
struct Sol {
    vector<Board> board;
    unordered_map<int, unordered_map<int, vector<int> > > BitMaskIndex;
    vector<bool> Visited;
    Cube cube;
    void init() {
        Visited.resize(6, false);
        board.resize(6);
        cube.init();
    }
    bool dfs() {
        int i, j ;
        for ( j = 0 ; j < 6 ; j ++ )
            for ( i = 0 ; i < 8 ; i ++ ) {
                cube.Set(board[j].C[i], '0' + j);
#ifdef AJAVA_DEBUG
                cout << "Check Board " << 0 << " / Rotation = " << i << '\n';
                board[j].dump();
                cube.dump();
#endif
                Visited[0] = true;
                cube.rotateRollUp();
                if (fitUp(1))
                    return true;
                cube.rotateRollDown();
                Visited[j] = false;
                cube.Set(board[j].C[i], 0);
#ifdef AJAVA_DEBUG
                cout << "[Roll back Clear] Check Board " << 0 << " / Rotation = " << i << '\n';
                cube.dump();
#endif
            }
        return false;
    }
    bool fitUp(int depth) {
        int mask;
        if (depth == 4) {
            cube.rotateTurnLeft();
            for (int boardIndex = 0 ; boardIndex < 6 ; boardIndex ++ ) {
                if (Visited[boardIndex]) continue;
                auto &b = board[boardIndex];
                for (int rotIdx = 0; rotIdx < 8; rotIdx++) {

//            mask = cube.getPossibleMask();
//            for (auto &[boardIndex, rotationIdxList]: BitMaskIndex[mask]) {
//                if (Visited[boardIndex]) continue;
//                auto &b = board[boardIndex];
//                for (auto rotIdx: rotationIdxList) {
                    if (!cube.checkDup(b.C[rotIdx])) continue;
                    if (!cube.isFitAll(b.C[rotIdx])) continue;
                    cube.Set(b.C[rotIdx], boardIndex + '0');
                    Visited[boardIndex] = true;
                    if (fitUp(depth + 1))
                        return true;
                    Visited[boardIndex] = false;
                    cube.Set(b.C[rotIdx], 0);
                }
            }
            cube.rotateTurnRight();
        } else if (depth == 5) {

            cube.rotateTurnAround();
            mask = cube.getPossibleMask();
            for (auto &[boardIndex, rotationIdxList]: BitMaskIndex[mask]) {
                if (Visited[boardIndex]) continue;

                auto &b = board[boardIndex];
                for (auto rotIdx: rotationIdxList) {
                    if (!cube.checkDup(b.C[rotIdx])) continue;
                    if (!cube.isFitAll(b.C[rotIdx])) continue;
                    return true;
                }
            }
            cube.rotateTurnAround();
        } else {

            mask = cube.getPossibleMask();
            vector<int> possibleMask = {mask};
            if (firstMask == (mask & firstMask)) possibleMask.push_back(mask & ~firstMask);
            if (lastMask == (mask & lastMask)) possibleMask.push_back(mask & ~lastMask);
            if ((firstMask | lastMask) == (mask & ~(firstMask | lastMask)))
                possibleMask.push_back((mask & ~(firstMask | lastMask)));

            unordered_map< int, vector<int> > possibles;

            for (auto bitMask: possibleMask) {
                for (auto &[boardIndex, rotationIdxList]: BitMaskIndex[bitMask]) {
                    if (Visited[boardIndex]) continue;
                    for (auto rotIdx: rotationIdxList)
                        possibles[boardIndex].push_back(rotIdx);
                }
            }
            for (auto &[boardIndex, rotList]: possibles) {
                std::sort(rotList.begin(), rotList.end());
                rotList.erase(std::unique(rotList.begin(), rotList.end()), rotList.end());
            }

            for (auto [boardIndex, rotList]: possibles) {
                auto &b = board[boardIndex];
                b.dump(rotList);

                for (auto rotIdx: rotList) {
                    if (!cube.checkDup(b.C[rotIdx]))
                        continue;
                    if (depth == 3 && !cube.isFit(b.C[rotIdx], DOWN))
                        continue;

                    if ( cube.isFit(b.C[rotIdx], UP)) continue;

                    cube.Set(b.C[rotIdx], boardIndex + '0');
#ifdef AJAVA_DEBUG
                    cout << "[Before rollUP] Depth = " << depth << " / Check Board " << boardIndex << " / Rotation = "
                         << rotIdx << '\n';
                    cube.dump();
#endif

                    cube.rotateRollUp();
                    Visited[boardIndex] = true;
                    if (fitUp(depth + 1))
                        return true;
                    Visited[boardIndex] = false;
                    cube.rotateRollDown();

#ifdef AJAVA_DEBUG
                    cout << "[rotateRollDown] Depth = " << depth << " / Check Board " << boardIndex << " / Rotation = "
                         << rotIdx << '\n';
                    cube.dump();
#endif

                    cube.Set(b.C[rotIdx], 0);
#ifdef AJAVA_DEBUG
                    cout << "[Roll back] Depth = " << depth << " / Check Board " << boardIndex << " / Rotation = "
                         << rotIdx << '\n';
                    cube.dump();
#endif
                }
            }
        }
        return false;
    }
    void dump() {
        int i;
        for ( i = 0 ; i < 6 ; i ++ )
            board[i].dump();


        for ( int j = 0 ; j < 6 ; j ++ ) {
            auto &b = board[j];
            for ( i = 0 ; i < 8 ; i ++ ) {
                cube.Set(b.C[i], j+'0');
                cube.rotateRollUp();

                int mask = cube.getPossibleMask();
                vector<int> possibleMask = {mask};
                if (firstMask == (mask & firstMask)) possibleMask.push_back(mask & ~firstMask);
                if (lastMask == (mask & lastMask)) possibleMask.push_back(mask & ~lastMask);
                if ((firstMask | lastMask) == (mask & ~(firstMask | lastMask)))
                    possibleMask.push_back((mask & ~(firstMask | lastMask)));

                cout << "Current Cube : \n";
                cube.dump();

                for (auto bitMask: possibleMask) {
                    for (auto &[boardIndex, rotationIdxList]: BitMaskIndex[bitMask]) {
                        auto &b = board[boardIndex];
                        b.dump(rotationIdxList);
                    }
                }

                cube.rotateRollDown();
                cube.Set(b.C[i], 0);
            }

        }
    }
};

void process() {
    int i, j, k, b;
    int bit;
    vector<string> S[6];
    Sol sol;

    sol.init();
    for ( i = 0 ; i < 6 ; i ++ ) {
        S[i].resize(N);
        for ( j = N-1 ; j >= 0 ; j -- )
            cin >> S[i][j];
    }
    for ( k = 0 ; k < 6 ; k ++  ) {
        for (i = 1; i < N - 1; i++)
            for (j = 1; j < N - 1; j++)
                if (S[k][i][j] != 'X') {
                    cout << "No\n";
                    return;
                }
        sol.board[k].init(S[k]);
    }
    for ( i = 0 ; i < 6 ; i ++ ) {
        for ( j = 0 ; j < 8 ; j ++ ) {
            bit = sol.board[i].mask(j) ;
            sol.BitMaskIndex[bit][i].push_back(j);
        }
    }
    sol.dump();

    if ( sol.dfs() )
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
        allMask = (1 << N) - 1;
        firstMask = 1 << (N-1);
        lastMask = 1;

        process();
    }
    return 0;
}
