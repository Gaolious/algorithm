#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int M = 14348907;
const int MaxSum = 459;
int D[10][MaxSum+1];

int main()
{
    fastio;
    int i, j ;
    int s ;

    for ( i = 1 ; i <= 9 ; i ++ )
        D[1][i] = 1;

    for ( i = 2 ; i <= 51 ; i ++ ) {
        s = 0 ;
        for ( j = 0 ; j <= MaxSum ; j ++ ) s = (s + D[i-1][j]) % M ;

        for ( j = 0 ; j <= 9 ; j ++ )
            D[i][ ( j + s ) % M ] += (s + j) % M ;
    }
    
    return 0;
}


