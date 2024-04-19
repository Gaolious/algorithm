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

ll F(ll a, ll digit, ll b) {
    ll ret ;
    ret = (a/digit)*digit + b%digit;
    if ( a % digit >= b % digit )
        ret += digit;
    return ret;
}
void process() {
    ll a, b;
    int i;
    ll digit;
    char c;
    while ( cin >> a >> c >> b ) {
        for ( i = 1, digit=10 ; ; i++, digit*=10 ) {
            if ( F(a, digit, b%digit) == b ) {
                cout << a << "-" << setw(i) << setfill('0') << b%digit << '\n';
                break;
            }
        }
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


