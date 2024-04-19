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

const ll MOD = 100000ll;
void M(ll &a) {
    if ( a > MOD )
        a = (a % MOD ) + MOD;
}
ll Pow(ll a, ll b) {
    if ( b == 0 ) return 1;
    if ( b == 1 ) return a % MOD;
    auto ret = Pow(a, b/2);
    M(ret *= ret);
    if ( b%2 == 1 ) M(ret *= a);
    return ret;
}
void process() {
    ll N, n2, n5;
    ll i, t, ans ;
    cin >> N ;
    n2 = n5 = 0 ;

    for ( ans = 1, i = 2 ; i <= N ; i ++ ) {
        t = i ;
        for ( ; t % 2 == 0 ;t /= 2, n2++);
        for ( ; t % 5 == 0 ;t /= 5, n5++);
        M( ans *= t);
    }
    t = min(n2, n5);
    n2 -= t;
    n5 -= t;
    M( ans *= Pow(2, n2));
    M( ans *= Pow(5, n5));

    if ( ans >= MOD )
        cout << setw(5) << setfill('0') << ans % MOD << '\n';
    else
        cout << ans % MOD << '\n';
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


