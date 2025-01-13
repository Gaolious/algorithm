#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MatrixSize = 2;
const ll MOD = 10000ll;
#define M(x) ( (x) = (x) >= (MOD) ? ( (x)%(MOD) + MOD ) : (x) )

struct Matrix {
	ll M[MatrixSize][MatrixSize];

	Matrix operator *(Matrix &o) {
		int i, j, k;
		Matrix ret = {};
		for ( i = 0 ; i < MatrixSize ; i ++ ) {
			for ( j = 0 ; j < MatrixSize ; j ++ ) {
				for ( k = 0 ; k < MatrixSize ; k ++ )
					ret.M[i][j] += M[i][k] * o.M[k][j];

				M(ret.M[i][j]);
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
	if ( n < 0 ) return 0;
	auto ret = Pow(m, n);
	return ret.M[0][0];
}

void process(ll n) {
	ll ans ;
	ans = Fib(n-1);
	if ( (ans) % MOD == 0 )
		cout << "0\n";
	else
		cout << ans % MOD << "\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	// cin >> T;
	ll n;
	while ( cin >> n && n >= 0 )
	    process(n);
	return 0;
}
