#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const char BLANK     = 0x00;
const char WALL      = 0x01;
const char TARGET    = 0x02;
const char BOX       = 0x04;
const char CHARACTER = 0x10;

char Map[15][15];
int Y, X;
typedef pair<int, int> pii ;
pii operator + (pii a, pii b) {
    return {a.first + b.first, a.second + b.second };
}
bool isWall(pii pos) {
    if ( pos.first < 0 || pos.second < 0 || pos.first >= Y || pos.second >= X )
        return false ;
    return Map[pos.first][pos.second] == WALL;
}
bool isBox(pii pos) {
    if ( pos.first < 0 || pos.second < 0 || pos.first >= Y || pos.second >= X )
        return false ;
    return Map[pos.first][pos.second] & BOX;
}
bool isBlank(pii pos) {
    if ( pos.first < 0 || pos.second < 0 || pos.first >= Y || pos.second >= X )
        return false ;
    return Map[pos.first][pos.second] == BLANK;
}
bool Move(pii &player, pii delta) {
    pii nextPos = player + delta;
    pii nextnextPos = nextPos + delta;
    auto &currP = Map[player.first][player.second];
    auto &nextP = Map[nextPos.first][nextPos.second];

    if ( isWall(nextPos) ) return false ;
    if ( isBlank(nextPos)) {
        currP = currP & ( ~CHARACTER );
        nextP = nextP | CHARACTER ;
        player = nextPos;
        return true;
    }
    if ( isBox(nextPos) ) {
        if ( isWall(nextnextPos) || isBox(nextnextPos) ) return false;

        auto &nextnext = Map[nextnextPos.first][nextnextPos.second];
        nextnext = nextnext | BOX;
        nextP = nextP & (~BOX) ;

        currP = currP & ( ~CHARACTER );
        nextP = nextP | CHARACTER ;
        player = nextPos;
        return true;
    }

    return true;
}
void dump() {
    int i, j ;

    for ( i = 0;  i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if (Map[i][j] & WALL) cout << '#';
            else if (Map[i][j] == (BOX | TARGET)) cout << 'B';
            else if (Map[i][j] == (BOX)) cout << 'b';
            else if (Map[i][j] == (CHARACTER | TARGET)) cout << 'W';
            else if (Map[i][j] == (CHARACTER)) cout << 'w';
            else if (Map[i][j] == TARGET) cout << '+';
            else cout << '.';
        }
        cout << '\n';
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    pii player;
    char c ;
    string command ;
    vector<pii> target_list ;
    for (int game=1 ; ; game ++ ) {
        memset(Map, 0, sizeof(Map));
        target_list.clear();

        cin >> Y >> X ;

        if ( Y == 0 && X == 0 )
            break;

        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                cin >> c;
                switch (c) {
                    case '#': Map[i][j] = WALL; break;
                    case '+': Map[i][j] = TARGET; break;
                    case 'b': Map[i][j] = BOX; break;
                    case 'B': Map[i][j] = BOX | TARGET; break;
                    case 'w': Map[i][j] = CHARACTER; break;
                    case 'W': Map[i][j] = CHARACTER | TARGET; break;
                    default: Map[i][j] = BLANK; break;
                }
                if ( Map[i][j] & TARGET )
                    target_list.emplace_back(i, j);
                if ( Map[i][j] & CHARACTER )
                    player = {i, j};
            }
        }
        cin >> command;
        bool isOver = false ;
        int cnt = 0;
        for( i = 0 ; i < command.size() && !isOver ; i ++ ) {
            c = command[i];
            if ( c == 'U' ) Move(player, {-1,0 });
            if ( c == 'D' ) Move(player, {1, 0});
            if ( c == 'L' ) Move(player, {0, -1});
            if ( c == 'R' ) Move(player, {0, 1});

            // cout << " Command : " << c << '\n';
            // dump();

            cnt = 0;
            for (auto p : target_list)
                if ( Map[p.first][p.second] & BOX )
                    cnt ++;
            if ( cnt == target_list.size() )
                isOver = true;
        }
        cout << "Game " << game <<": ";
        if ( isOver ) cout << "complete\n";
        else  cout << "incomplete\n";
        dump();
    }

    return 0;
}


