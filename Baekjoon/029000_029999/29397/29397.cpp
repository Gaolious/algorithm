#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 2, -2, 0, 0, 1, 1, -1, -1};
int dx[] = { 0, 0, 2, -2, 1, -1, 1, -1};
const int Y = 8, X = 8;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
pii input() {
    string s ;
    cin >> s;
    return { s[0] - 'a', s[1] - '0'};
}

void process() {
    pii a = input();
    pii b = input();
    int ta = (a.first + a.second) % 2 ;
    int tb = (b.first + b.second) % 2 ;
    cout << ( ta == tb ? "YES" : "NO" ) << '\n';
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


