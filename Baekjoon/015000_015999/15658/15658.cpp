#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[12];
int O[4];
int N ;
int retMin = 2000000000, retMax = -2000000000;

int calc(int a, int b, int opIdx) {
    switch (opIdx) {
        case 0: return a+b;
        case 1: return a-b;
        case 2: return a*b;
        case 3: return a/b;
    }
}
void F(int numIdx, int score) {
    if ( numIdx >= N ) {
        retMax = max(retMax, score);
        retMin = min(retMin, score);
        return;
    }
    for ( int i = 0 ; i < 4 ; i ++ ) {
        if ( O[i] > 0 ) {
            O[i]--;
            F(numIdx+1, calc(score, A[numIdx], i));
            O[i]++;
        }
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
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[ i ] ;
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        cin >> O[i] ;
        O[i] = min(O[i], N-1);
    }
    F(1, A[0]);
    cout << retMax << '\n' << retMin << '\n';
    return 0;
}


