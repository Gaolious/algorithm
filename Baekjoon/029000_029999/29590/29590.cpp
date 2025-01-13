#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> prime;
bitset<1000001> F;
void init(){
    ll i, j;
    for ( i = 2 ; i <= 1000000 ; i ++ ) {
        if ( F[i] ) continue;
        prime.push_back(i);
        for (j=i*i ; j <= 1000000 ; j += i )
            F[j] = true;
    }
}

void process(int Case) {
    ll N, K;
    int i, j;
    cin >> N >> K ;
    int ans = 0 ;
    for (j=0, i = 1 ; i <prime.size() && prime[i] <= N ; i ++ ) {
        while ( j < i && prime[j] + K < prime[i] ) j ++;
        if ( prime[j] + K == prime[i] ) ans ++;
    }
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
