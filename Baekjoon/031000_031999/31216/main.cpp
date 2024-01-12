#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MAXN (320'000)

vector<ll> primes;
vector<ll> super_prime;
bitset<MAXN+1> A(0);

void sieve() {
    ll i, j ;
    A[0] = A[1] = true;
    primes.push_back(0);
    primes.push_back(2);
    for (i = 3 ; i < MAXN ; i += 2 ) {
        if ( A[i] ) continue;
        primes.push_back(i);
        for (j=i*i ; j < MAXN ; j += i)
            A[j] = true;
    }
    for ( i = 1 ; i <= 3000 ; i ++ )
        super_prime.push_back(primes[ primes[i] ]);
}
int main()
{
    fastio;
    sieve();
    int T, n;

    cin >> T ;
    while (T--) {
        cin >> n ;
        cout << super_prime[n-1] << '\n';
    }
    return 0;
}
