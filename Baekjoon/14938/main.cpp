#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    int N, M, R ;
    int i, j, k, d;
    int ret ;
    ll D[100][100];

    cin >> N >> M >> R ;

    vector<int> T(N);

    for ( i = 0 ; i < N ; i ++ ) cin >> T[i];

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            D[i][j] = ( i == j ) ? 0 : 1e9;
        }
    }

    for ( i = 0 ; i < R ; i ++ ) {
        cin >> j >> k >> d ;

        assert(1 <= j && j <= N );
        assert(1 <= k && k <= N );
        assert( j != k );

        D[ k - 1 ][ j - 1 ] = D[ j - 1 ][ k - 1 ] = d;
    }


    for ( k = 0 ; k < N ; k ++ ) {
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                D[i][j] = min( D[i][j], D[i][k] + D[k][j]);
            }
        }
    }


    ret = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        int s = 0 ;
        for ( j = 0 ; j < N ; j ++ )
            if ( i == j || D[i][j] <= M )
                s += T[j];

        ret = max(ret, s);
    }
    cout << ret << endl;
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


