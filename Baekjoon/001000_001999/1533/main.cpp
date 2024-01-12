#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxRow = 50;

int N, S, E, T;
const ll MOD = 1'000'003;

struct Matrix {
    int n;
    vector<vector<ll>> m;
    Matrix(int n) {
        this->n = n;
        this->m = vector<vector<ll>> (n, vector<ll>(n));
    }
    Matrix operator * (const Matrix &o) {
        Matrix ret(this->n);
        int i, j, k;
        ll t ;
        for ( i = 0 ; i < this->n ; i++ ){
            for ( j = 0 ; j < this->n ; j ++ ) {
                t = 0;
                for ( k = 0 ; k < this->n ; k ++ ) {
                    t = (t + this->m[i][k] * o.m[k][j]) % MOD ;
                }
                ret.m[i][j] = t ;
            }
        }
        return ret;
    }
};

Matrix pow(Matrix a, ll n) {
    if ( n == 1 )
        return a;
    Matrix m = pow(a, n/2);
    m = m * m ;
    if (n % 2 == 1)
        m = m * a ;
    return m;
}

void process() {
    fastio;
    int i, j, minute;
    string s ;

    cin >> N >> S >> E >> T ;

    Matrix matrix(N * 5);

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 1 ; j < 5 ; j ++ ) {
            matrix.m[i * 5 + j][ i * 5 + j - 1 ] = 1;
        }
    }

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        for ( j = 0 ; j < s.length() ; j ++ ) {
            minute = s[j] - '0';
            if ( minute == 1 ) matrix.m[i*5][j*5] = 1;
            else if ( minute > 1 ) matrix.m[i*5][j*5+minute-1] = 1;
        }
    }

    Matrix ans = pow(matrix, T);

    cout << ans.m[(S-1)*5][(E-1)*5] << '\n';

//    for ( i = 0 ; i < N*5 ; i ++ ) {
//        for ( j = 0 ; j < N*5 ; j ++ ) {
//
//            if ( i % 5 == 0 && j % 5 == 0)
//            {
//                cout << '[' << ans.m[i][j] << "] " ;
//            }
//            else
//                cout << ' ' << ans.m[i][j] << "  ";
//        }
//        cout << '\n';
//    }
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


