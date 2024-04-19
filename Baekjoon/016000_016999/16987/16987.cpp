#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int S[10];
int W[10];
int N;
int best = 0;

void F(int idx, int cnt) {
    best = max(best, cnt);
    if( idx >= N ) return ;
    if ( S[idx] <= 0 ) {
        F(idx+1, cnt);
        return;
    }
    int i;
    for ( i = 0 ; i < N ; i ++ ) {
        if ( i == idx ) continue;
        if ( S[i] <= 0 ) continue;

        S[i] -= W[idx];
        S[idx] -= W[i];

        F(idx+1, cnt + (S[i] <= 0) + (S[idx] <= 0) );

        S[i] += W[idx];
        S[idx] += W[i];
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

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ )
        cin >> S[ i ] >> W[ i ] ;
    F(0, 0);
    cout << best ;
    return 0;
}


