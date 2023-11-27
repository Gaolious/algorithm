#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
// 윗 면은 흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 오렌지색, 왼쪽 면은 초록색, 오른쪽 면은 파란색
// U: 윗 면, D: 아랫 면, F: 앞 면, B: 뒷 면, L: 왼쪽 면, R: 오른쪽 면이다.
// 두 번째 문자는 돌린 방향이다. +인 경우에는 시계 방향 (그 면을 바라봤을 때가 기준), -인 경우에는 반시계 방향이다.
enum POS { UP=0, DOWN, LEFT, RIGHT, FRONT, BACK};
enum COLOR { WHITE='w', YELLOW='y', RED='r', ORANGE='o', GREEN='g', BLUE='b'};

enum ROTATING { ROTATE_UP, ROTATE_DOWN, ROTATE_LEFT, ROTATE_RIGHT, ROLLING_LEFT, ROLLING_RIGHT };
POS RUBIX_PATH[][4] = {
        {UP, FRONT, DOWN, BACK}, // X축 중심 위로 돌릴 때
        {UP, BACK, DOWN, FRONT}, // X축 중심 아래로 돌릴 때
        {FRONT, RIGHT, BACK, LEFT}, // Z축 중심 왼쪽으로 돌릴 때
        {FRONT, LEFT, BACK, RIGHT}, // Z축 중심 오른쪽으로 돌릴 때
        {UP, RIGHT, DOWN, LEFT}, // Y축 중심 왼쪽으로 회전할 때
        {UP, LEFT, DOWN, RIGHT}, // Y축 중심 오른쪽으로 회전할 때
};

typedef struct {
    int x, y, z;

    char c[6];

    void debug(bool withColor = false) {
        cout << "Idx z=" << z << ", y=" << y << ", x=" << x << "\n";
        if (withColor) {
            cout << "U:" << c[UP] << "\n";
            cout << "D:" << c[DOWN] << "\n";
            cout << "L:" << c[LEFT] << "\n";
            cout << "R:" << c[RIGHT] << "\n";
            cout << "F:" << c[FRONT] << "\n";
            cout << "B:" << c[BACK] << "\n";
        }
    }
} RUBIX;

void rotate_rubix(RUBIX &r, ROTATING d) { // up, down, left, down
    int i, j;
    char t = r.c[RUBIX_PATH[d][0]];
    for ( j = 1 ; j < 4 ; j ++ )
        r.c[RUBIX_PATH[d][j-1]] = r.c[RUBIX_PATH[d][j]];
    r.c[RUBIX_PATH[d][3]] = t;
}


RUBIX Cube[3][3][3];

void init() {
    //
    int x, y, z;
    memset(Cube, 0x00, sizeof(Cube));
    // 윗 면은 흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 오렌지색, 왼쪽 면은 초록색, 오른쪽 면은 파란색
    for ( y = 0 ; y < 3 ; y ++ ) for ( x = 0 ; x < 3 ; x ++) Cube[2][y][x].c[UP] = WHITE ;
    for ( y = 0 ; y < 3 ; y ++ ) for ( x = 0 ; x < 3 ; x ++) Cube[0][y][x].c[DOWN] = YELLOW ;

    for ( z = 0 ; z < 3 ; z ++ ) for ( x = 0 ; x < 3 ; x ++) Cube[z][0][x].c[FRONT] = RED ;
    for ( z = 0 ; z < 3 ; z ++ ) for ( x = 0 ; x < 3 ; x ++) Cube[z][2][x].c[BACK] = ORANGE ;

    for ( z = 0 ; z < 3 ; z ++ ) for ( y = 0 ; y < 3 ; y ++) Cube[z][y][0].c[LEFT] = GREEN ;
    for ( z = 0 ; z < 3 ; z ++ ) for ( y = 0 ; y < 3 ; y ++) Cube[z][y][2].c[RIGHT] = BLUE ;

    for ( z = 0 ; z < 3 ; z ++ )
        for ( y = 0 ; y < 3 ; y ++ )
            for ( x = 0 ; x < 3 ; x ++)
            {
                Cube[z][y][x].z = z;
                Cube[z][y][x].y = y;
                Cube[z][y][x].x = x;
            }
}
void rotateXAxis(int x_index, bool isCCW) {
    int y, z, x;
    int i, j, curr_idx, next_idx ;
    RUBIX t ;
    pair<int,int> CUBE_PATH[2][4] = {
            {{0, 0}, {0, 2}, {2, 2}, {2, 0}},
            {{0, 1}, {1, 2}, {2, 1}, {1, 0}},
    };

    for ( z = 0 ; z < 3 ; z ++ )
        for ( y = 0 ; y < 3 ; y ++)
            rotate_rubix(Cube[z][y][x_index],  isCCW ? ROTATE_UP : ROTATE_DOWN);

    for ( i = 0 ; i < 2 ; i ++ ) {
        curr_idx = 0;
        next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;
        t = Cube[ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ][ x_index ];
        for ( j = 1 ; j < 4 ; j ++ )
        {
            Cube[ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ][ x_index ] = Cube[ CUBE_PATH[i][next_idx].first ][ CUBE_PATH[i][next_idx].second ][ x_index ] ;
            curr_idx = next_idx;
            next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;

        }
        Cube[ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ][ x_index ] = t;
    }
}
void rotateYAxis(int y_index, bool isCCW) {
    int y, z, x;
    int i, j, curr_idx, next_idx ;
    RUBIX t ;
    pair<int,int> CUBE_PATH[2][4] = {
            {{0, 0}, {2, 0}, {2, 2}, {0, 2}},
            {{0, 1}, {1, 0}, {2, 1}, {1, 2}},
    };

    for ( z = 0 ; z < 3 ; z ++ )
        for ( x = 0 ; x < 3 ; x ++)
            rotate_rubix(Cube[z][y_index][x],  isCCW ? ROLLING_LEFT : ROLLING_RIGHT);


    for ( i = 0 ; i < 2 ; i ++ ) {
        curr_idx = 0;
        next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;
        t = Cube[ CUBE_PATH[i][curr_idx].first ][y_index][ CUBE_PATH[i][curr_idx].second ];
        for ( j = 1 ; j < 4 ; j ++ )
        {
            Cube[ CUBE_PATH[i][curr_idx].first ][y_index][ CUBE_PATH[i][curr_idx].second ] = Cube[ CUBE_PATH[i][next_idx].first ][y_index][ CUBE_PATH[i][next_idx].second ] ;
            curr_idx = next_idx;
            next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;

        }
        Cube[ CUBE_PATH[i][curr_idx].first ][y_index][ CUBE_PATH[i][curr_idx].second ] = t;
    }
}
void rotateZAxis(int z_index, bool isCCW) {
    int y, x;
    int i, j, curr_idx, next_idx ;
    RUBIX t ;
    pair<int,int> CUBE_PATH[2][4] = {
            {{0, 0}, {0, 2}, {2, 2}, {2, 0}},
            {{0, 1}, {1, 2}, {2, 1}, {1, 0}},
    };

    for ( y = 0 ; y < 3 ; y ++ )
        for ( x = 0 ; x < 3 ; x ++)
            rotate_rubix(Cube[z_index][y][x],  isCCW ? ROTATE_LEFT : ROTATE_RIGHT);

    for ( i = 0 ; i < 2 ; i ++ ) {
        curr_idx = 0;
        next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;
        t = Cube[z_index][ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ];
        for ( j = 1 ; j < 4 ; j ++ )
        {
            Cube[z_index][ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ] = Cube[z_index][ CUBE_PATH[i][next_idx].first ][ CUBE_PATH[i][next_idx].second ] ;
            curr_idx = next_idx;
            next_idx = (curr_idx + ( isCCW ? 1 : -1 ) + 4 ) % 4;

        }
        Cube[z_index][ CUBE_PATH[i][curr_idx].first ][ CUBE_PATH[i][curr_idx].second ] = t;
    }
}

int origin() {
    fastio;
    int N, cnt;
    int z, y, x;
    char c, d;
    bool ccw ;
    cin >> N;
    while (N--) {
        cin >> cnt;

        init();
        while (cnt--) {
            cin >> c >> d;
            ccw = d == '-';
            switch (c) {
                case 'U':
                    rotateZAxis(2, !ccw);
                    break;
                case 'D':
                    rotateZAxis(0, ccw);
                    break;
                case 'F':
                    rotateYAxis(0, ccw);
                    break;
                case 'B':
                    rotateYAxis(2, !ccw);
                    break;
                case 'L':
                    rotateXAxis(0, ccw);
                    break;
                case 'R':
                    rotateXAxis(2, !ccw);
                    break;
            }
        }

        for (z = 2, y = 2; y >= 0; y--) {
            for (x = 0; x < 3; x++)
                cout << Cube[z][y][x].c[UP];
            cout << '\n';
        }
    }
}

void proc() {
    fastio;
    int N, cnt;
    int z, y, x;
    char c, d;
    bool ccw ;
    pair<int,int> CUBE_PATH[][12] = {
            {
                {3, 0},
            },
            {{0, 1}, {1, 2}, {2, 1}, {1, 0}},
    };


    cin >> N;
    while (N--) {
        cin >> cnt;

        init();
        while (cnt--) {
            cin >> c >> d;
            ccw = d == '-';
        }
    }

}
int main() {
    origin();
    return 0;
}