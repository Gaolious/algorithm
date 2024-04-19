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

const ll MOD = 998'244'353ll;

ll Pow(ll a, ll b ) {
    if ( b == 0 ) return 1 ;
    if ( b == 1 ) return a % MOD ;
    auto ret = Pow(a, b/2);
    ret = ret * ret % MOD ;
    if ( b%2 == 1 ) ret = ret * a % MOD;
    return ret ;
}
void process() {
    ll R, C, ans, i;
    cin >> R >> C ;

    ans = R * Pow(R-1, C-1) % MOD ;
    cout << ans << '\n';
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


