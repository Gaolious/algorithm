#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MAXN (5000)
const int INF = MAXN + 1;

int A[MAXN+1]{};
int D[3][5];
int N;

int min(int a, int b, int c) {
    return min( min(a, b), c);
}
int min(int a, int b, int c, int d) {
    return min( min(a, b), min(c, d));
}
#define F(idx, nth) ( D[(idx)][ ( (nth) + 4 ) % 4 ] )
#define BETWEEN(v, a, b) ( (a) <= (v) && (v) <= (b) )
int main()
{
    fastio;
    int n;
    int i, j ;
    char c;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> c;
        A[i] = c - '0';
    }

    for ( i = 0 ; i < 5 ; i ++ )
        D[0][i] = D[1][i] = D[1][i] = INF;

    n = 0;
    D[0][0] = 0;
    for ( i = 1 ; i <= N ; i ++ ) {
        n = ( n % 100 ) * 10 + A[i-1];
        F(0, i) = F(1, i) = F(2, i) = INF;

        if ( BETWEEN(n%10, 1, 9) )
            F(0, i) = min( F(0, i-1), F(1, i-1), F(2, i-1) ) + 1;
        if ( BETWEEN(n%100, 10, 99) )
            F(1, i) = min( F(0, i-2), F(1, i-2), F(2, i-2) ) + 1;
        if ( BETWEEN(n%1000, 100, 641) )
            F(2, i) = min( F(0, i-3), F(1, i-3), F(2, i-3) ) + 1;
    }
    cout << min( F(0, N), F(1, N), F(2, N)) << '\n';
    return 0;
}


