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


const ll MOD = 1'000'000'007ll;

ll NCR[101][101];
ll Pow(ll a, ll n) { // a^n
    if ( a == 0 ) return 0;
    if ( a == 1 || n == 0 ) return 1;
    if ( n == 1 ) return a % MOD;
    auto ret = Pow(a, n/2);
    ret = (ret*ret) % MOD;
    if ( n%2==1 ) ret = (ret*a) % MOD;
    return ret;
}
void process() {
    int i, j, T, N, M, t, n, r;
    ll ans, sign;
    memset(NCR, 0, sizeof(NCR));
    NCR[0][0] = 1;
    for ( n = 1 ; n <= 100; n ++ ) { // nCr
        NCR[n][0] = 1;
        for ( r = 1 ; r <= n ; r ++ )
            NCR[n][r] = ( NCR[n-1][r-1] + NCR[n-1][r] ) % MOD;
    }

    cin >> T ;

    for ( t = 1 ; t <= T ; t ++ ) {
        cin >> M >> N ;
        ans = Pow(M, N);
        for ( i = 1, sign=-1; i <= M ; i++, sign = -sign ) {
            ans += sign * ( Pow(M-i, N) * NCR[M][i] % MOD );
            ans = ( ans % MOD + MOD ) % MOD;
        }
        cout << "Case #" << t << ": " << ans << '\n';
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


