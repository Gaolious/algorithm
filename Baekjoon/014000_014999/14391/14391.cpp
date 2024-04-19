#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int Y, X;
int A[4][4];
bool visited[4][4];
int best = -1;

void F(int idx, int score) {
    int i, s;
    int y, x ;
    if ( idx >= Y*X ) {
        best = max(best, score);
        return ;
    }
    y = idx / X;
    x = idx % X;

    if ( visited[y][x]) {
        F(idx+1, score);
        return;
    }

    s = A[y][x];
    visited[y][x] = true;

    F(idx+1, score + s );

    for ( i = 1 ; x+i < X && !visited[y][x+i] ; i ++ ) {
        s = s * 10 + A[y][x+i];
        visited[y][x+i] = true;
        F(idx+1, score + s);
    }
    for ( i-- ; i >= 1 ; i -- ) visited[y][x+i] = false;

    s = A[y][x];
    for ( i = 1 ; y+i < Y && !visited[y+i][x] ; i ++ ) {
        s = s * 10 + A[y+i][x];
        visited[y+i][x] = true;
        F(idx+1, score + s);
    }
    for ( i-- ; i >= 1 ; i -- ) visited[y+i][x] = false;

    visited[y][x] = false;
}

int main()
{
    int i, j ;
    char c;

    fastio;
    cin >> Y >> X ;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> c;
            A[ i ][ j ] = c - '0';
        }
    }


    F(0, 0);

    cout << best;

    return 0;
}


