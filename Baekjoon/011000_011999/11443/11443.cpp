#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MatrixSize = 2;
const ll MOD = 1000000007ll;
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

void init(){
}
void process(int Case) {
	ll n;
	ll ans ;
	cin >> n;
	ans = Fib(n+1);
	ans = (ans - Fib(n - 1 + (n%2)) - 1 + MOD ) % MOD;
	cout << ans << '\n';
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
