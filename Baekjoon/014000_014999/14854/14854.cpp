#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}

ll modFact(ll n, ll p) {
	ll result = 1;
	for (ll i = 1; i <= n; i++) {
		result = (result * i) % p;
	}
	return result;
}

ll modInverse(ll a, ll p) {
	ll result = 1, power = p - 2;
	while (power > 0) {
		if (power % 2 == 1) result = (result * a) % p;
		a = (a * a) % p;
		power /= 2;
	}
	return result;
}

ll binomialMod(ll n, ll k, ll p) {
	if (k > n) return 0;
	ll numerator = modFact(n, p);
	ll denominator = (modFact(k, p) * modFact(n - k, p)) % p;
	return (numerator * modInverse(denominator, p)) % p;
}

ll lucasTheorem(ll n, ll k, ll p) {
	ll result = 1;
	while (n > 0 || k > 0) {
		ll ni = n % p, ki = k % p;
		if (ki > ni) return 0;
		result = (result * binomialMod(ni, ki, p)) % p;
		n /= p;
		k /= p;
	}
	return result;
}

ll chineseRemainder(vector<ll> &remainders, vector<ll> &mods) {
	ll prod = 1, result = 0;
	for (ll mod : mods) prod *= mod;

	for (size_t i = 0; i < mods.size(); i++) {
		ll pp = prod / mods[i];
		result += remainders[i] * modInverse(pp, mods[i]) * pp;
		result %= prod;
	}
	return result;
}
void process(int Case) {

	vector<ll> primes = {27, 11, 13, 37};
	int T;
	cin >> T;

	while (T--) {
		ll N, K;
		cin >> N >> K;

		vector<ll> remainders;
		for (ll p : primes) {
			remainders.push_back(lucasTheorem(N, K, p));
		}

		ll result = chineseRemainder(remainders, primes);
		cout << result << '\n';
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
