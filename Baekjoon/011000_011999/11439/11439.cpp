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

ll N, K, M ;
vector<ll> prime;
vector<ll> prime_count;

void sieve() {
    vector<char> flag(N+1, 0);
    ll i, j;
    prime.push_back(2);

    for ( i = 3 ;  i<= N ; i += 2  ) {
        if ( flag[i] != 0 ) continue;
        prime.push_back(i);
        for ( j=i*i ; j <= N ; j += i)
            flag[j] = 1;
    }
}
ll pow(ll a, ll b) {
    if ( b == 0 ) return 1l;
    if ( b == 1 ) return a;
    ll ret = pow(a, b/2);
    ret = ( ret * ret ) % M ;
    if ( b & 1 ) ret = ( ret * a ) % M ;
    return ret % M;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i;

    cin >> N >> K >> M ;
    sieve();
    prime_count.resize( prime.size() );
    for ( i = 0 ; i < prime.size() ; i ++ )
        for ( ll j = prime[i] ; j <= N ; j *= prime[i] )
            prime_count[i] += (N/j) - (K/j) - ((N-K)/j);

    ll ans  = 1;
    for ( i = 0 ; i < prime.size() ; i ++ )
        ans = ( ans * pow( prime[i], prime_count[i]) ) % M ;
    cout << ans << '\n';

    return 0;
}


