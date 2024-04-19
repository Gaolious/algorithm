#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int sign[10][10];
int N ;
int PreSum[10]{};
int A[10]{};

int SUM(int l, int r) {
    int ret = 0;
    if ( r >= 0 ) {
        ret = PreSum[ r ];
        if ( l > 0 )
            ret -= PreSum[ l - 1 ];
    }
    return ret;
}

int SIGN(int l, int r) {
    if ( r >= 0 ) {
        int ret = SUM(l, r);
        if ( ret > 0 ) return 1;
        if ( ret < 0 ) return -1;
    }
    return 0;
}

bool F(int idx) {
    int i;
    for ( i = 0 ; i < idx ; i ++ ) {
        if ( sign[i][idx-1] != SIGN(i, idx-1) )
            return false;
    }

    if ( idx == N ) {
        return true;
    }

    if ( idx > 0 )
        PreSum[ idx ] = PreSum[ idx - 1 ];
    int lo, hi, s, e;
    lo = -10, hi = 10;

    for ( i = 0 ; i <=idx ; i ++ ) {
        s = e = 0;
        if ( sign[i][idx] < 0 ) s=-10, e=-1;
        if ( sign[i][idx] > 0 ) s=1, e=10;
        s -= SUM(i, idx-1), e -= SUM(i, idx-1);
        lo = max(lo, s);
        hi = min(hi, e);
    }
    for ( i = lo ; i <= hi ; i ++ ) {
        A[idx] = i;
        PreSum[idx] += i;
        if (F(idx+1))
            return true;
        PreSum[idx] -= i;
    }
    return false;
}
int main()
{
    int i, j;
    char c;

    fastio;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = i ; j < N ; j ++ ) {
            cin >> c ;
            if ( c == '-') sign[ i ][ j ] = -1;
            else if ( c == '+') sign[ i ][ j ] = 1;
            else sign[ i ][ j ] = 0;
        }
    }
    F(0);
    for ( i = 0 ; i < N ; i ++ )
        cout << A[ i ] << ' ';

    return 0;
}


