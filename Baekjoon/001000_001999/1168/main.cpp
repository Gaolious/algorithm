#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int T[262145]={0,};
int base;

int F(int idx, int nth) {
    T[idx] --;
    if ( idx >= base )
        return idx - base + 1 ;
    return ( nth <= T[idx*2] ) ?
        F(idx*2, nth) : F(idx*2+1, nth-T[idx*2]);
}
int main()
{
    int i, lookup, j ;
    int N, K ;

    fastio;
    cin >> N >> K;

    base = 1 << ( (int)ceil(log2(N)) ) ;
    for ( i = 0 ; i < N ; i ++ ) T[base+i] = 1;
    for ( i = base-1 ; i >= 1 ; i -- ) T[i] = T[i*2] + T[i*2+1];

    lookup = 0;
    cout << '<';
    do {
        lookup = ( lookup + K - 1 ) % N ;
        cout << F(1, lookup + 1) ;
        if ( N > 1 ) cout << ", ";
    } while (--N);
    cout << '>' << '\n';
    return 0;
}


