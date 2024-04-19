#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1};
string CharDir[] = {"↑", "↖", "←", "↙", "↓", "↘", "→", "↗"};

struct Pos {
    char y: 3;
    char x: 3;
    bool alive: 1;
};
struct Data {
    char Map[4][4]{};
    char dir[4][4]{};
    Pos pos[16];
    void setFish(char y, char x, char no, char d) {
        pos[no].y = y ;
        pos[no].x = x ;
        pos[no].alive = true ;
        Map[y][x] = no ;
        dir[y][x] = d;
    }
    bool moveFish(char no, char sy, char sx) {
        char ty, tx, d, i ;
        char y, x, tno;
        if ( !pos[no].alive )
            return false;
        y  = pos[no].y, x = pos[no].x;
        for ( i = 0 , d = dir[y][x]; i < 8 ; i ++, d = (d+1)%8 ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || tx < 0 || ty >= 4 || tx >= 4 ) continue;
            if ( ty == sy && tx == sx) continue;

            dir[y][x] = d;
            tno = Map[ty][tx];

            swap(Map[y][x], Map[ty][tx]);
            swap(dir[y][x], dir[ty][tx]);
            swap(pos[no], pos[tno]);
            bool t = pos[no].alive ; pos[no].alive = pos[tno].alive; pos[tno].alive = t;
            return true;
        }
        return false;
    }
};
int bestScore = -1;

void F(int score, Data data, char y, char x) {

    char i ;
    char ty, tx, d;
    bestScore = max(bestScore, score);

    for ( i = 0 ; i < 16 ; i ++ )
        data.moveFish(i, y, x);

    ty = y, tx = x, d = data.dir[y][x];
    for ( i = 1 ; ; i ++ ) {
        ty += dy[d];
        tx += dx[d];
        if ( ty < 0 || tx < 0 || ty >= 4 || tx >= 4 ) break;

        int no = data.Map[ty][tx];

        if ( data.pos[no].alive ) {
            data.pos[no].alive = false;
            F(score + no + 1, data, ty, tx);
            data.pos[no].alive = true;
        }
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    Data init ;
    int i, j, no, d ;
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( j = 0 ; j < 4 ; j ++ ) {
            cin >> no >> d ;
            init.setFish(i, j, no-1, d-1);
        }
    }
    int score = 0;
    score = init.Map[0][0];
    init.pos[ score ].alive = false;

    F(score + 1, init, 0, 0);

    cout << bestScore << '\n';
    return 0;
}


