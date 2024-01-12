#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MAXN (20)
const ll MOD = 1'000'000'007ll;

int T, N, D;

struct MATRIX {
    ll m[MAXN][MAXN];
    MATRIX() {
        memset(m, 0, sizeof(m));
    }
    MATRIX operator *(MATRIX &o) {
        MATRIX ret ;
        int i, j, k;
        for ( i = 0 ; i <N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                for ( k = 0 ; k < N ; k ++ ) {
                    ret.m[i][j] += this->m[i][k] * o.m[k][j] % MOD;
                    ret.m[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    MATRIX pow(int k) {
        MATRIX ret, a = *this ;
        ret.setE();
        while ( k > 0 ) {
            if ( k % 2 ) ret = ret * a ;
            a = a*a;
            k /=2 ;
        }
        return ret;
    }
    void setE() {
        int i;
        for ( i = 0 ; i <N ; i ++ )
            m[i][i] = 1;
    }
    void print() {
        int i, j;
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ )
                cout << m[i][j] << ' ';
            cout << '\n';
        }
    }
};

MATRIX Cache[101];

int main()
{
    int i, M, a, b, c ;

    fastio;
    cin >> T >> N >> D ;
    vector<MATRIX> Mat(T);

    for (auto &m : Mat) {
        cin >> M ;
        while ( M -- ) {
            cin >> a >> b >> c ;
            m.m[a-1][b-1] = c;
        }
    }
    Cache[0].setE();
    for ( i = 0 ; i < T ; i ++ )
        Cache[i+1] = Cache[i] * Mat[i];

    (Cache[T].pow(D/T) * Cache[D%T]).print();
    return 0;
}


