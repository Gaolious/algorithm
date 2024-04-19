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

template<typename T> pair<T, T> eGCD(T a, T b) {
    if (b == 0) return { 1, 0 };
    auto t = eGCD(b, a%b);
    return { t.second, t.first - t.second*(a / b) };
}

void process() {
    ll x, n, m ;
    cin >> x >> m ;
    if ( gcd(x, m) == 1 ) {
        auto ret = eGCD(x, m);
        cout << ( ret.first % m + m ) % m;
    }
    else
        cout << "No such integer exists.\n";
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


