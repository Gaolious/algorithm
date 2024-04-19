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

void process() {
    //  카밀은 가끔 K 대신 T를 발음하지만, T 대신 K를 발음하지는 않습니다.
    //  비슷하게 G 대신 D를 발음하기도 하고,
    //  R 대신 L 또는 F를 발음하기도 합니다.
    ll ans = 1;

    string s ;
    cin >> s ;
    ans = 1;
    for (auto c: s ) {
        if ( c == 'T' ) ans *= 2;
        else if ( c == 'D' ) ans *=2 ;
        else if ( c == 'L' || c == 'F' ) ans *=2 ;
    }
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


