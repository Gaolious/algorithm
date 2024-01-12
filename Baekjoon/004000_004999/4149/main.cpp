#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ull modmul(ull a, ull b, ull m)
{
    return (__int128)a * b % m;
}

ull modpow(ull a, ull b, ull m)
{
    if (b == 0) return 1;
    if (b & 1) return modmul(modpow(a, b-1, m), a, m);
    ull r = modpow(a, b/2, m);
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

ull pollard_rho(ull n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ull> dis(1, n - 1);

    for (;;)
    {
        ull x = dis(gen);
        ull y = x;
        ull c = dis(gen);
        ull g = 1;
        while (g == 1) {
            x = (modmul(x, x, n) + c) % n;
            y = (modmul(y, y, n) + c) % n;
            y = (modmul(y, y, n) + c) % n;
            g = gcd(x>y?x-y:y-x, n);
        }
        if (g != n) return g;
    }
}
void factorize(ull n, vector<ull>& fl) {
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
        ull f = pollard_rho(n);
        factorize(f, fl);
        factorize(n / f, fl);
    }
}
int main()
{
    fastio;
    ull n ;
    vector<ull> a ;

    cin >> n ;
    factorize(n, a);

    std::sort(a.begin(), a.end());
    for ( auto i : a) {
        cout << i << '\n';
    }
    return 0;
}


