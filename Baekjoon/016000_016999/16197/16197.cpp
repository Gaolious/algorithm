#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
typedef pair<int, int> POINT;

int M[20][20];
int Check[2][22][22];
int Y, X;
int best = 20;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool isOut(POINT &p) {
    if ( p.first < 0 || p.first >= Y ) return true;
    if ( p.second < 0 || p.second >= X ) return true;
    return false;
}
bool isWall(POINT &p) {
    return !isOut(p) && M[p.first][p.second] == -1;
}
void visit(POINT &p, int idx, bool add) {
    Check[idx][p.first+1][p.second+1] += add ? 1 : -1;
}
void F(int depth, POINT p1, POINT p2) {
    bool b1, b2;
    b1 = isOut(p1);
    b2 = isOut(p2);

    if ( (b1 || b2) ) {
        if ( b1 != b2 )
            best = min(best, depth);
        return ;
    }
    if (depth >= 10 || depth > best ) return ;

    POINT a, b;

    for ( int d = 0 ; d < 4 ; d ++ ) {
        a = {p1.first + dy[d], p1.second + dx[d]};
        b = {p2.first + dy[d], p2.second + dx[d]};
        if ( isWall(a) ) a = p1;
        if ( isWall(b) ) b = p2;
        if ( Check[0][a.first+1][b.second+1] > 0 && Check[1][a.first+1][b.second+1] > 0 )
            continue;
        visit(a, 0, true);
        visit(b, 0, true);
        F(depth + 1, a, b);
        visit(a, 0, false);
        visit(b, 0, false);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c;
    int i, j, k;
    POINT p[2];
    fastio;

    cin >> Y >> X;

    for ( i = 0, k = 0  ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> c;
            if ( c == '#' ) M[i][j] = -1;
            else if ( c == 'o' )
                p[k++] = {i, j};
        }
    }
    F(0, p[0], p[1]);
    if ( best <= 10 )
        cout << best ;
    else
        cout << -1;
    return 0;
}


