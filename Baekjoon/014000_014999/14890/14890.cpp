#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[100][100];
int C1[100];
int N, L;
int V(int y, int x, bool f) {
    return f ? A[y][x] : A[x][y];
}
bool check(int y, bool f) {
    int j, c;
    for ( C1[N-1] = 1, j = N-2 ; j >= 0 ; j -- )
        C1[j] = V(y, j, f) == V(y, j+1, f) ? C1[j+1]+1 : 1;
    for ( c=1, j = 1 ; j < N; j ++ ) {
        int diff =  V(y, j-1, f) - V(y, j, f);
        if ( diff == 0 ) c++;
        else if ( diff == 1 ) {
            if ( C1[j] < L ) return false;
            j += L - 1;
            c = 0;
        }
        else if ( diff == -1 ) {
            if ( c < L ) return false;
            c = 1;
        }
        else return false;
    }
    return true;
}

int main()
{
    fastio;
    int i, j;
    int ret = 0 ;

    cin >> N >> L ;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            cin >> A[i][j];

    for ( i = 0 ; i < N ; i ++ ) {
        if ( check(i, true) )
            ret ++;
        if ( check(i, false) )
            ret ++;
    }
    cout << ret << '\n';
    return 0;
}