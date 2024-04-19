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

vector<ll> prime;
void sieve(ll N) {
    vector<bool> F(N+1);
    ll i, j;
    prime.push_back(2);
    for ( i = 3 ; i <= N ; i +=2 ) {
        if ( F[i]) continue;
        prime.push_back(i);
        for ( j = i * i ; j <= N ; j+= i )
            F[j] = true;
    }
}
ll getPrime(ll N) {
    if ( N <= prime.back() ) {
        return *lower_bound(prime.begin(), prime.end(), N);
    }
    else {
        for ( ll i = N % 2 == 0 ? N +1 : N ;; i += 2 ) {
            bool isPrime = true ;
            for ( auto p: prime ) {
                if ( p*p > N ) break;
                if ( i % p == 0 ) {
                    isPrime = false;
                    break;
                }
            }
            if ( isPrime ) return i;
        }
    }
}
void process() {
    int T;
    ll N ;

    sieve( sqrt(40000000000ll) );

    cin >> T ;

    while ( T -- ) {
        cin >> N ;
        cout << getPrime(N) << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


