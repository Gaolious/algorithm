#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll minSol, maxSol ;
char Oper[10];
bool Used[10];
int N ;

void F(int idx, ll sol) {
    int i ;
    if ( idx == N  ) {
        minSol = min(minSol, sol);
        maxSol = max(maxSol, sol);
        return;
    }
    for ( i = 0 ; i < 10 ; i ++ ) {
        if ( Used[i] ) continue;
        if ( Oper[idx] == '<' && sol%10 > i) continue;
        if ( Oper[idx] == '>' && sol%10 < i) continue;

        Used[i] = true;
        F(idx+1, sol * 10 + i);
        Used[i] = false;
    }
}
int main()
{
    int i;
    fastio;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> Oper[ i ] ;
        Used[ i ] = false;
    }
    minSol = 10000000000;
    maxSol = -1;

    for ( i = 0 ; i < 10 ; i ++) {
        Used[ i ] = true;
        F(0, i);
        Used[ i ] = false;
    }
    cout << setfill('0') << setw(N+1) << maxSol << '\n'
         << setfill('0') << setw(N+1) << minSol << '\n';
    return 0;
}



