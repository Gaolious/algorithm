#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxRow = 50;

int N, S, E, T;
const ll MOD = 1'000'003;

typedef vector<vector<ll>> matrix;
matrix operator *(matrix &a, matrix &b) {
    int MaxN = N * 5;
    int i, j, k;
    ll t ;
    matrix ret(MaxN, vector<ll>(MaxN));

    for ( i = 0 ; i < MaxN ; i ++ ) {
        for (j = 0; j < MaxN; j++) {
            t = 0;
            for (k = 0; k < MaxN; k++)
                t = (t + a[i][k] * b[k][j]) % MOD ;
            ret[i][j] = t;
        }
    }
    return ret;
}
void process() {
    fastio;
    int i, j, t;
    string s ;

    cin >> N >> S >> E >> T ;
    matrix A(N*5, vector<ll>(N*5));
    matrix ret(N*5, vector<ll>(N*5));

    for ( i = 0 ; i < N*5 ; i ++ )
        A[i][i] = 1;
    for ( i = 1 ; i < N*5 ; i ++ )
        A[i-1][i] = 1;

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        for ( j = 0 ; j < s.length() ; j ++ ) {
            t = s[j] - '0';
            if ( t > 0 ) {

            }
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


