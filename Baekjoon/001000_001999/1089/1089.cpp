#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const char B[5][40] = {
    "###...#.###.###.#.#.###.###.###.###.###",
    "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
    "#.#...#.###.###.###.###.###...#.###.###",
    "#.#...#.#.....#...#...#.#.#...#.#.#...#",
    "###...#.###.###...#.###.###...#.###.###"
};
char A[5][40];
int N;

bool compare(int a, int b) {
    int i, j;
    for ( i = 0 ; i < 5 ; i ++ )
        for ( j = 0 ; j < 3 ; j ++ ) {
            if ( A[i][a*4+j] == '.') continue;
            if ( A[i][a*4+j] != B[i][b*4+j] ) return false;
        }
    return true;
}
pair<ll, ll> count() {
    int i, j;

    ll S[11]{}, C[11]{};
    ll ret = 1, sum, digits ;

    for ( digits=1, i = N-1 ; i >= 0 ; i--, digits *= 10l ) {
        for ( C[i] = 0, j = 0 ; j < 10 ; j ++ )
            if (compare(i, j) ) {
                C[i] ++;
                S[i] += j * digits;
            }
        ret *= C[i];
    }

    sum = 0 ;
    if ( ret > 0 ) {
        for ( i = 0 ; i < N ; i ++ )
            sum += S[i] * (ret/C[i]) ;
    }

    return {ret, sum};
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    cin >> N ;
    for ( i = 0 ; i < 5 ; i ++ ) {
        for ( j = 0 ; j < 4*N - 1 ; j ++ )
            cin >> A[i][j];
    }
    auto [cnt, sum] = count();
    if ( cnt == 0 )
        cout << "-1\n";
    else
        cout << setprecision(14) << fixed << (long double)(sum) / cnt << '\n';
    return 0;
}


