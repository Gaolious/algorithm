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
ll P(ll a, ll b) {
    if ( b == 0 ) return 1;
    else if ( b == 1 ) return a;
    auto ret = P(a, b/2);
    ret *= ret;
    if ( b & 1 ) ret *= a ;
    return ret;
}
void process() {
    int a, b, c, d;

    while ( cin >> a >> b >> c >> d ) {
        if ( !a && !b && !c && !d ) break;
        cout << P(a, b*c*d) << '\n';
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


