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

ll nCr( ll n, ll r) {
    ll ret = 1, j, i;
    j = max(n - r, r);
    for (i = n; i > j; i--) ret *= i;
    for (i = n - j; i > 1; i--) ret /= i;
    return ret;
}
void process() {
    ll A, B, ans;
    while ( cin >> A >> B ) {
        if ( A < 0 && B < 0 ) break;
        ans = nCr(A + B, A);

        cout << A << "+" << B ;
        if (A + B == ans ) cout << "=";
        else cout << "!=";
        cout << A+B << '\n';
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


