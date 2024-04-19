#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll modmul(ll a, ll b, ll m)
{
    return (__int128)a * b % m;
}

ll modpow(ll a, ll b, ll m)
{
    if (b == 0) return 1;
    if (b & 1) return modmul(modpow(a, b-1, m), a, m);
    ll r = modpow(a, b/2, m);
    return modmul(r, r, m);
}

bool test_witness(ull a, ull n, ull s) {
    if (a >= n) a %= n;
    if (a <= 1) return true;
    ull d = n >> s;
    ull x = modpow(a, d, n);
    if (x == 1 || x == n-1) return true;
    while (s-- > 1) {
        x = modmul(x, x, n);
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}

bool is_prime(ull n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;

    ull d = n >> 1, s = 1;
    for(; (d&1) == 0; s++) d >>= 1;

#define T(a) test_witness(a##ull, n, s)
    if (n < 4759123141ull) return T(2) && T(7) && T(61);
    return T(2) && T(325) && T(9375) && T(28178)
           && T(450775) && T(9780504) && T(1795265022);
#undef T
}

ll pollard_rho(ll n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> dis(1, n - 1);

    for (;;)
    {
        ll x = dis(gen);
        ll y = x;
        ll c = dis(gen);
        ll g = 1;
        while (g == 1) {
            x = (modmul(x, x, n) + c) % n;
            y = (modmul(y, y, n) + c) % n;
            y = (modmul(y, y, n) + c) % n;
            g = gcd(abs(x - y), n);
        }
        if (g != n) return g;
    }
}
void factorize(ll n, vector<ll>& fl) {
    if (n == 1) {
        return;
    }
    if (n % 2 == 0) {
        fl.push_back(2);
        factorize(n / 2, fl);
    }
    else if (is_prime(n)) {
        fl.push_back(n);
    }
    else {
        ll f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}
ll phi(ll n) {

    vector<ll> fl;
    factorize(n, fl);
    sort(fl.begin(), fl.end());

    fl.push_back(-1);

    ll ans = 1;

    for (int i = 0; i < fl.size() - 1; i++)
    {
        if (fl[i] == fl[i+1]) ans *= fl[i];
        else ans *= fl[i] - 1;
    }

    return ans;
}
void process() {
    fastio;
    const ll INF = 100'000'000'000;
    ll n, t, sol = 100'000'000'000 ;
    cin >> n ;

    for ( ll i = 1 ; i * i <= n ; i ++ ) {
        if ( n % i != 0 ) continue;
        t = n / i ;

        if (phi(i) == t)
            sol = min(sol, i);
        else if (phi(t) == i)
            sol = min(sol, t);
    }
    cout << ( sol >= INF ? -1 : sol) << endl;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


