#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int Y, X;

int RS[1000], CS[1000];

int Swap(int A[1000], int len) {
    int ret = 0, i ;
    if ( len > 2 ) {
        sort(A+1, A+len-1);
        int T[3] = { A[0], A[1], A[len-1] };
        sort(T, T+3);
        A[0] = T[0];
        A[len-1] = T[1];
        A[1] = T[2];
    }
    for ( i = 0 ; i < len ; i ++ ) {
        if ( i == 0 || i == len - 1 ) ret += A[i];
        else ret += A[i] * 2;
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k;

    cin >> Y >> X ;

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            cin >> k ;
            RS[i] += ( j == 0 || j == X-1 ) ? k : k*2 ;
            CS[j] += ( i == 0 || i == Y-1 ) ? k : k*2 ;
        }
    }

    cout << max( Swap(RS, Y), Swap(CS, X) ) << '\n';
    return 0;
}


