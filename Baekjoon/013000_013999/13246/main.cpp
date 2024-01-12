#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MOD = 1000 ;
int N ;

struct Matrix {
    int m[5][5];
    Matrix operator *(Matrix b) {
        Matrix ret{};
        int i, j, k, n ;
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                n = 0 ;
                for ( k = 0 ; k < N ; k ++ )
                    n = ( n + this->m[i][k] * b.m[k][j] ) % MOD;
                ret.m[i][j] = n ;
            }
        }
        return ret;
    }
    Matrix operator +(Matrix b) {
        Matrix ret{};
        int i, j, k, n ;
        for ( i = 0 ; i < N ; i ++ ) {
            for ( j = 0 ; j < N ; j ++ ) {
                ret.m[i][j] = (this->m[i][j] + b.m[i][j]) % MOD ;
            }
        }
        return ret;
    }
};
Matrix I ;

Matrix Pow( Matrix &a, ll n) {
    Matrix ret{};
    if ( n == 0 ) {
        memcpy(ret.m, I.m, sizeof(a.m));
    }
    else if (n == 1) {
        memcpy(ret.m, a.m, sizeof(a.m));
    }
    else if ( n % 2 == 0 ) {
        Matrix t = Pow(a, n/2);
        return t*t;
    }
    else {
        return a * Pow(a, n-1);
    }
    return ret;
}

Matrix SeriesSum(Matrix &a, ll b) {
    Matrix ret{};

    if ( b == 1 ) {
        return a ;
    }
    ll m = b/2;
    ret = SeriesSum(a, m) * (Pow(a, m) + I);
    if ( b % 2 == 1 )
        ret = ret + Pow(a,b);

    return ret;
}
int main()
{
    fastio;
    ll B;
    int i, j ;
    Matrix A{};
    cin >> N >> B ;

    for ( i = 0 ; i < N ; i ++ )
        I.m[i][i] = 1;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
        {
            cin >> A.m[ i ][ j ] ;
            A.m[ i ][ j ] %= MOD;
        }

    Matrix ret = SeriesSum(A, B);

    for ( i = 0 ; i < N ; i ++ )
    {
        for ( j = 0 ; j < N ; j ++ )
            cout << ret.m[i][j]  << ' ';
        cout << "\n";
    }
    return 0;
}


