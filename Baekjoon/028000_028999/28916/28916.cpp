#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll C[20];
void init(){
    int i;
    C[0] = 1;
    for ( i = 1 ; i < 20 ; i ++) C[i] = C[i-1]*9;
}
ll GetCnt(ll N, ll nDigit, ll n10) {
    ll i, cnt = 0;
    if ( nDigit == 0 ) return 0;
    if ( N / n10 == 9 ) return GetCnt(N/n10*n10 - 1, nDigit, n10);
    for (i = min(N / n10, 8ll); i > 0; i--) cnt += C[nDigit-1];
    return cnt + GetCnt(N % n10, nDigit-1, n10/10);
}
ll F(ll N) {
    ll nDigit, n10;
    for ( nDigit=1, n10=1 ; N >= n10*10 ; nDigit++, n10*=10 );
    return GetCnt(N, nDigit, n10);
}
void process(int Case) {
    ll a, b;
    cin >> a >> b ;
    cout << F(b) - F(a-1) << '\n';
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
