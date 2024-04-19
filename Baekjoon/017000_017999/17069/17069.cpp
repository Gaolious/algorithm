#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll D[3][32][32];
char A[32][32];
int N;

bool valid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}
bool CheckHori(int y, int x) {
    return valid(y, x) && valid(y, x-1) && A[y][x] == '0' && A[y][x-1] == '0';
}
bool CheckVert(int y, int x) {
    return valid(y, x) && valid(y-1, x) && A[y][x] == '0'&& A[y-1][x] == '0';
}
ll S(int y, int x) {
    return D[0][y][x] + D[1][y][x] + D[2][y][x];
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    bool h, v;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            cin >> A[i][j] ;

    D[0][0][1] = 1;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            h = CheckHori(i, j);
            v = CheckVert(i, j);
            if ( h ) D[0][i][j] += D[0][i][j-1] + D[1][i][j-1];
            if ( v ) D[2][i][j] += D[2][i-1][j] + D[1][i-1][j];
            if ( h && v ) D[1][i][j] += S(i-1, j-1);
        }
    }
    cout << S(N-1, N-1) << '\n';
    return 0;
}


