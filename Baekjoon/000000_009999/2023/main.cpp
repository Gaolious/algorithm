#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<vector<ll>> Primes = vector(10, vector<ll>());
int N;

void sieve() {
    const int N = 100000;
    bitset<N> P;
    ll i, j, k, n ;

    k=10;
    n=1;

    for ( i = 2 ; i < N ; i ++ ) {
        if (P[i]) continue;
        while( i >= k ) {
            k *=10; n++;
        }
        Primes[n].push_back(i);
        for (j=i*i; j<N ; j+=i) {
            P[j]=true;
        }
    }
}
bool is_prime(int len, ll n) {
    if ( !Primes[len].empty()) {
        auto p = lower_bound(Primes[len].begin(), Primes[len].end(), n);
        return p != Primes[len].end() && *p == n;
    }
    int i, j ;
    for ( i = 1 ; i <= 8 ; i ++ ) {
        for (auto p: Primes[i] ) {
            if ( p*p > n ) break;
            if ( n % p == 0 )
                return false;
        }
    }
    return true;
}
void F(int len, ll n) {
    if ( !is_prime(len, n) )
        return;

    if ( len == N ) {
        cout << n << '\n';
        return;
    }
    for (auto i : {1,3,7,9}) {
        F(len+1, n*10 + i);
    }
}

int main()
{
    fastio;
    cin >> N ;

    sieve();
    for (auto p : Primes[1]) {
        F(1, p);
    }
    return 0;
}


