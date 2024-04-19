#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN (61)

int D[61][61][61];

const int INF = 10000000;
#define P(x) max(0, (x))
int min(int a, int b, int c) {
    return min( min(a, b), c);
}
int max(int a, int b, int c) {
    return max( max(a, b), c);
}
int F(int _a, int _b, int _c ) {
    int a, b, c;
    a = min( _a, _b, _c);
    c = max( _a, _b, _c);
    b = _a+_b+_c - a - c;

    auto &ret = D[a][b][c] ;
    if ( ret < 0 ) {
        int A[] = { 1, 3, 9 };
        ret = INF;
        do {
            ret = min(ret, F( P(a-A[0]), P(b-A[1]), P(c-A[2])) +1);
        } while ( next_permutation(A, A+3) ) ;
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
    int A[3]{};
    int n ;

    memset(D, -1, sizeof(D));
    D[0][0][0] = 0;
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ ) cin >> A[i];
    cout << F(A[0], A[1], A[2]) ;
    return 0;
}


