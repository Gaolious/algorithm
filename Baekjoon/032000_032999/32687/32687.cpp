#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll N10[18] = {
	0,
	1ll,
};

void init(){
}
ll find(ll n, ll A, ll B, ll K, ll M)
{
	ll num;
	for ( num = 0 ; num <= B ;  num = num * N10[K+1] + n );
	for ( ;num > B ; num /= 10);

	ll ans = 0;
	for ( A = max(A, N10[K]) ; num >= A ; num /= 10)
		if ( num % M == 0 )
			ans ++;
	return ans;
}
void process(int Case) {
	ll A, B, K, M;
	cin >> A >> B >> K >> M;
	for ( int i = 2 ; i <= 17 ; i ++ ) N10[i] = N10[i-1] * 10;

	ll ans = 0;
	for ( ll n = N10[K]; n < N10[K+1]; n++)
		ans += find(n, A, B, K, M);

	cout << ans << endl;
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
