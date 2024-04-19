#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }


const int MatrixSize = 2;
const ll MOD = 1000000000ll;
struct Matrix {
    ll M[MatrixSize][MatrixSize];

    Matrix operator *(Matrix &o) {
        int i, j, k;
        Matrix ret = {};
        for ( i = 0 ; i < MatrixSize ; i ++ ) {
            for ( j = 0 ; j < MatrixSize ; j ++ ) {
                for ( k = 0 ; k < MatrixSize ; k ++ )
                    ret.M[i][j] += M[i][k] * o.M[k][j];
                ret.M[i][j] %= MOD;
            }
        }
        return ret;
    }
};
Matrix m = {
    {
        { 1, 1 },
        { 1, 0 },
    }
};
Matrix I = {
        {
                { 1, 0 },
                { 0, 1 },
        }
};
Matrix Pow(Matrix &a, ll n) {
    if ( n == 0 ) return I;
    if ( n == 1 ) return a;
    auto ret = Pow(a, n/2);
    ret = ret * ret;
    if ( n%2 == 1 ) ret = ret * a;
    return ret;
}
ll Fib(ll n){
    auto ret = Pow(m, n);
    return ret.M[0][0];
}
void process() {
    ll a, b;
    cin >> a >> b;

    // F(4) ~ F(10) :
    // F(12) = F(11) + F(10)
    // F(12) = F(10) + F(9) + F(9) + F(8)
    //       = F(10) + F(9) + F(8) + F(8) + F(7)
    //       = F(10) + F(9) + F(8) + F(7) + F(7) + F(6)
    //       = F(10) + F(9) + F(8) + F(7) + F(6) + F(6) + F(5)
    //       = F(10) + F(9) + F(8) + F(7) + F(6) + F(5) + F(5) + F(4)

    // F(9) = F(8) + F(7)
    // F(9) = F(7) + F(6) + F(6) + F(5)


    cout << (Fib(b+1) - Fib(a) + MOD) % MOD << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


