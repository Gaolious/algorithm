#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
vector<ll> Prime;
void sieve() {
    bitset<1'000'001> F;
    Prime.push_back(2);
    for ( ll a=3 ; a <= 1'000'000 ; a += 2 ) {
        if ( F[a] ) continue;
        Prime.push_back(a);
        for ( ll b=a*a ; b <= 1'000'000 ; b+= a)
            F[b] = 1;
    }
}
bool Div(ll n) {
    for (auto p: Prime)
        if ( n % p == 0 )
            return false;
    return true;
}
void process(int Case) {
    sieve();
    int N ;
    ll a;
    cin >> N ;
    while ( N -- ) {
        cin >> a ;
        if ( Div(a) ) cout << "YES\n";
        else cout << "NO\n";
    }
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
