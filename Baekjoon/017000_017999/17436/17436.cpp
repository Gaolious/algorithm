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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(a%b, a);
}
ll lcd(ll a, ll b) {
    return a / gcd(a,b) * b ;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll N, M, v ;
    int i, j, c;
    vector<ll> A;

    cin >> N >> M ;
    A.resize(N);
    for (auto &n: A) cin >> n ;

    ll ans = 0;
    for ( int n = (1<<N) - 1 ; n > 0 ; n -- ) {
        for ( v=1, c = 0, i = 0 ; i < N ; i ++ ) {
            if ( n & (1<<i) ) {
                c++; v *= A[i];
            }
        }
        ans += ( c % 2 == 0 ) ? -M/v : M/v;
    }
    cout << ans ;
    return 0;
}


