#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char A[52][52];
int N;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void input() {
    cin >> N ;
    int i , j;
    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= N ; j ++ ) {
            cin >> A[i][j];
        }
    }
}
int F(int y, int x) {
    int i, Y=0, X=0;

    Y = X = 1;
    for ( i = 1 ; y-i >= 1 && A[y-i][x] == A[y][x]; i ++ ) Y++;
    for ( i = 1 ; y+i <= N && A[y+i][x] == A[y][x]; i ++ ) Y++;
    for ( i = 1 ; x-i >= 1 && A[y][x-i] == A[y][x]; i ++ ) X++;
    for ( i = 1 ; x+i <= N && A[y][x+i] == A[y][x]; i ++ ) X++;

    return max(Y, X);
}
int main()
{
    int i, j, d, tx, ty;

    fastio;
    input();

    int ans = 0;

    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= N ; j ++ ) {
            ans = max(ans, F(i,j));
            for ( d = 0 ; d < 4 ; d ++ ) {
                tx = j + dx[d];
                ty = i + dy[d];
                if ( tx < 1 || tx > N || ty < 1 || ty > N ) continue;
                swap(A[i][j], A[ty][tx]);
                ans = max(ans, F(i,j));
                swap(A[i][j], A[ty][tx]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}


