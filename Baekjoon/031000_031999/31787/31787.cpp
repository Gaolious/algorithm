#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
unordered_map<ll, ll> D;
void init(){
    D[0] = 0;
    D[1] = 2;
    D[2] = 3;
    D[3] = 3;
    D[4] = 1;
    for ( ll i = 16 ; i <= 1000000000000000000ll ; i *= 4 )
        D[i] = D[i/4]+1;
}
ll F(ll N) {
    if ( D.count(N) ) return D[N];
    if ( N % 16 == 0 )
        return D[N] = F(N/4)+1;
    else if ( N % 4 != 0 )
        return D[N] = min( F(N%4) + N/4 , F(N*4) + 1 );
    ll k = N - (N%16);
    return D[N] = min(F(k) + (N%16)/4, F(16+k) + (16-N%16)/4);
}
void process(int Case) {
    ll N ;
    cin >> N ;
    cout << F(N) << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
