#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
enum POS { UP=0, DOWN, LEFT, RIGHT, FRONT, BACK};
enum ROTATING { ROTATE_UP, ROTATE_DOWN, ROTATE_LEFT, ROTATE_RIGHT, ROLLING_LEFT, ROLLING_RIGHT };
POS RUBIX_PATH[][4] = {
        {UP, FRONT, DOWN, BACK}, // X축 중심 위로 돌릴 때
        {UP, BACK, DOWN, FRONT}, // X축 중심 아래로 돌릴 때
        {FRONT, RIGHT, BACK, LEFT}, // Z축 중심 왼쪽으로 돌릴 때
        {FRONT, LEFT, BACK, RIGHT}, // Z축 중심 오른쪽으로 돌릴 때
        {UP, RIGHT, DOWN, LEFT}, // Y축 중심 왼쪽으로 회전할 때
        {UP, LEFT, DOWN, RIGHT}, // Y축 중심 오른쪽으로 회전할 때
};

struct Cube {
    bool c[6];
    bool hasError;
    Cube() {
        hasError=false;
        for (bool &b : c) b = false;
    }
    void rotate( ROTATING d ) {
        int i, j;
        bool t = c[RUBIX_PATH[d][0]];
        for ( j = 1 ; j < 4 ; j ++ )
            c[RUBIX_PATH[d][j-1]] = c[RUBIX_PATH[d][j]];
        c[RUBIX_PATH[d][3]] = t;
    }
    bool set() {
        if ( c[ DOWN ] ) return false;
        return c[ DOWN ] = true;
    }
    bool valid() {
        for (bool b : c)
            if (!b) return false;
        return true;
    }
    void debug() {
        cout << "U:" << c[UP] << "\n";
        cout << "D:" << c[DOWN] << "\n";
        cout << "L:" << c[LEFT] << "\n";
        cout << "R:" << c[RIGHT] << "\n";
        cout << "F:" << c[FRONT] << "\n";
        cout << "B:" << c[BACK] << endl;
    }
};

int A[6][6];
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
ROTATING dr[][2] = {
    {ROLLING_RIGHT, ROLLING_LEFT},
    {ROTATE_DOWN, ROTATE_UP},
    {ROLLING_LEFT,ROLLING_RIGHT},
    {ROTATE_UP, ROTATE_DOWN},
};

void dumpA() {
    int i, j;

    for ( i = 0 ; i < 6 ; i ++ ) {
        for ( j = 0 ; j < 6 ; j ++ ) {
            cout << setw(2) << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}
void Spread(Cube &C, int y, int x) {
    int ty, tx, d;

    A[y][x] = -1;
    if ( !C.set() ) return;
    for ( d = 0 ; d < 4 ; d ++ ) {
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || ty >= 6 || tx < 0 || tx >= 6 || A[ty][tx] != 1) continue;
        C.rotate(dr[d][0]);
        Spread(C, ty, tx);
        C.rotate(dr[d][1]);
    }
}
bool Check() {
    int i, j;
    Cube C;

    for ( i = 0 ; i < 6 ; i ++ ) {
        for ( j = 0 ; j < 6 ; j ++ ) {
            if ( A[i][j] == 1 ) {
                Spread(C, i, j);
                return !C.hasError && C.valid();
            }
        }
    }
    return false;
}
int main()
{
    fastio;
    int i, j;

    while ( cin >> A[0][0] ) {
        for ( i = 0 ; i < 6 ; i ++ ) {
            for ( j = 0 ; j < 6 ; j ++ ) {
                if ( !i && !j ) continue;
                cin >> A[i][j];
            }
        }
        if (Check())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}


