#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int S = 0, E = 32;
int R0[] = {
    0, 1, 2, 3, 4,
    5, 6, 7, 8, 9,
    10, 11, 12, 13, 14,
    15, 16, 17, 18, 19,
    31, 32
};
int R10[] = {5, 20, 21, 22, 28, 29, 30, 31, 32};
int R20[] = {10, 23, 24, 28, 29, 30, 31, 32};
int R30[] = {15, 25, 26, 27, 28, 29, 30, 31, 32};
int Score[] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18,
    20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
    13, 16, 19,
    22, 24,
    28, 27, 26,
    25, 30, 35, 40, 0
};
int R[4][50];
int A[10];
const int N = 10;
typedef pair<int, int> T;
bool Visited[40];
int best = -1;

T move(T pos, int m) {
    int i ;
    T ret = { pos.first, pos.second };
    for ( i = 0 ; i < m && ret.second != E; i ++ )
        ret.second = R[pos.first][ret.second];

    if ( ret.second >= E )
        ret.second = E;
    else if ( ret.second == 5 )
        ret.first = 1;
    else if ( ret.second == 10 )
        ret.first = 2;
    else if ( ret.second == 15 )
        ret.first = 3;
    return ret;
}

void F(int idx, T pos[4], int score) {
    int i, j ;

    if ( idx >= 10 ) {
        best = max(best, score) ;
        return;
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        if ( pos[i].second == E) continue;

        T tmp = pos[i];
        pos[i] = move(pos[i], A[idx]);
        if ( !Visited[pos[i].second] ) {
            Visited[tmp.second] = false;

            if ( 0 < pos[i].second && pos[i].second < E)
                Visited[pos[i].second] = true;

            F(idx+1, pos, Score[pos[i].second] + score);

            Visited[pos[i].second] = false;
            Visited[tmp.second] = true;
        }
        pos[i] = tmp;
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i ;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ] ;

    for ( i = 0 ; R0[i] != E ; i ++) R[0][ R0[i] ] = R0[i+1];
    for ( i = 0 ; R10[i] != E ; i ++) R[1][ R10[i] ] = R10[i+1];
    for ( i = 0 ; R20[i] != E ; i ++) R[2][ R20[i] ] = R20[i+1];
    for ( i = 0 ; R30[i] != E ; i ++) R[3][ R30[i] ] = R30[i+1];

    for ( i = 0 ; i < 4 ; i ++ ) R[i][E] = E;

    T pos[4]{};
    F(0, pos, 0);
    cout << best << '\n';
    return 0;
}


