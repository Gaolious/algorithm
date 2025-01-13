#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void init(){
}
ll Conv(ll v, int F[])
{
	ll a, ret;
	for (a = 1, ret=0 ; v > 0 ; a *= 10, v /= 10)
		ret += (ll)(F[v%10]) * a ;
	return ret;
}
void process(int Case) {
	int F[10], Fp[10];
	ll Fa, Fb, A, B;
	for (int i = 0; i < 10; i++)
	{
		cin >> F[i] ;
		Fp[ F[i] ] = i;
	}
	cin >> Fa >> Fb ;
	A = Conv(Fa, Fp);
	B = Conv(Fb, Fp);
	cout << Conv(A+B, F) << '\n';
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
