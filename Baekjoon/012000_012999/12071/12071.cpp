#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MaxN = 1000000000000000ll;
const ll MaxPrime = 35000000ll;
bitset<MaxPrime+1> isPrime;
vector<ll> primes;
bool G[200]; // 9*15=135

void init(){
    ll i, j;

    primes.push_back(2);
    G[1] = G[2] = true;
    isPrime.flip();
    for ( j=4 ; j*j <= MaxN ; j += 2 ) isPrime[j] = false;

    for ( i = 3 ; i*i <= MaxN ; i += 2 ) {
        if ( !isPrime[i] ) continue;
        primes.push_back(i);

        for ( j=i*2 ; j*j <= MaxN ; j += i )
            isPrime[j] = false;
        if ( i < 200 )
            G[i] = true;
    }
}
bool isG(ll N){
    ll s = 0 ;
    while(N>0) {
        s += N%10;
        N/=10;
    }
    return G[s];
}
bool isWin(ll N) {
    if (isG(N) || N == 1)
        return false;
    ll T = N;
    for (auto p: primes) {
        if ( p * p > N ) break;
        if ( N % p != 0 ) continue;
        ll n = N ;
        while ( n % p == 0 ) n/=p;
        while ( T % p == 0 ) T/= p;
        if ( !isWin(n))
            return true;
    }

    if (T != 1 && !isWin(N/T) )
        return true;

    return false;
}
void process(int Case) {
    ll N;
    cin >> N;
    cout << "Case #" << Case <<": " ;

    if (isWin(N))
        cout << "Laurence\n";
    else
        cout << "Seymour\n";
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
