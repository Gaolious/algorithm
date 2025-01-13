#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
const int MOD = 1'000'000'007;
#define M(a, x) ( (a) = ( (a) + (x) ) % MOD );

void process(int Case) {
    int Y, X, i, j;
    cin >> Y >> X;
    vector A(Y, vector<int>(X));
    A[0][0] = 1;
    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( j - 1 >= 0 ) M( A[i][j], A[i][j-1] );
            if ( i - 1 >= 0 ) M( A[i][j], A[i-1][j] );
            if ( j - 1 >= 0 && i - 1 >= 0 ) M( A[i][j], A[i-1][j-1] );
        }
    }
    cout << A[Y-1][X-1] << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    init();
    // cin >> T;
    for ( int i=1 ; i <= T ; i ++ )
        process(i);
    return 0;
}
