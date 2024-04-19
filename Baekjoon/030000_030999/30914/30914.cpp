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

const ll MAX_SIZE = 500000ll;
vector<ll> prime;
ll N, A, B;

void sieve() {
    ll i, j ;
    // 7, 11, 13, 17, 19, 23, 29, 31
    int delta[] = {4, 2, 4, 2, 4, 6, 2, 6};
    int d=0, base;

    vector<bool> F(5000000001, false);
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    ll maxN = sqrt(N);
    for ( i = 7 ; i * i <= 5000000000 ; i += delta[d++], d %=8 ) {
        if ( F[i] ) continue;
        prime.push_back(i);
        for ( j = i*i ; j <= 5000000000 ; j += i )
            F[j]=true;
    }
}
void check(ll nth, ll p) {
    // cout << p <<'\n';
    if ( nth % A == B ) {
        cout << p << endl;
    }
}

int segmentedSieve(long long L, long long R, vector<bool> &isPrime) {
    int cnt = R - L + 1 ;
    ll s, i, j;
    // cout << "segmentedSieve " << L << " ~ " << R << endl;
    for (auto p : prime) {
        s = max(p * p , (L + p - 1) / p * p);
        if ( s > R) break;
        for (long long j = s; j <= R; j += p) {
            if ( isPrime[j - L] )
                cnt--;
            isPrime[j - L] = false;
        }
    }
    if (L == 1)
        isPrime[0] = false;
    return cnt;
}

struct Data {
    ll n, q, p;
};
bool operator<(const Data &a, const Data &b) {
    return a.n > b.n ;
}
void segmentedSieve2(long long L, long long R, vector<bool> &isPrime) {
    ll s, i, j;
    priority_queue<Data> Q;

    for (auto p : prime) {
        s = max(p , (L+p-1)/p );
        Q.push({s*p, s, p});
    }
    // for ( i = L ; i <= R ; i ++ ) {
    // }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
    clock_t __t = clock();
#endif

    fastio;
    cin >> N >> A >> B ;
    sieve();

// #ifdef AJAVA_DEBUG
//     __t = clock() - __t;
//     cout << "Estimated Time : " << ((float)__t)/CLOCKS_PER_SEC << '\n';
// #endif
//
//     ll chunk = MAX_SIZE ;
//
//     vector<bool> isPrime(chunk+1);
//
//     for (ll t = 0 ; ; t ++ ) {
//         // fill(isPrime.begin(), isPrime.end(), false);
//         // cout << segmentedSieve(chunk*t+1, chunk*(t+1), isPrime) << '\n';
//         segmentedSieve2(chunk*t+1, chunk*(t+1), isPrime);
//
//
//         if ( chunk*(t+1) >= N ) break;
//     }

#ifdef AJAVA_DEBUG
    __t = clock() - __t;
    cout << "Estimated Time : " << ((float)__t)/CLOCKS_PER_SEC << '\n';
#endif
    return 0;

}


