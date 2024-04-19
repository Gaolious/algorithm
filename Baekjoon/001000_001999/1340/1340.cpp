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
unordered_map<string, int> Month = {
    {"January", 1},
    {"February", 2},
    {"March", 3},
    {"April", 4},
    {"May", 5},
    {"June", 6},
    {"July", 7},
    {"August", 8},
    {"September", 9},
    {"October", 10},
    {"November", 11},
    {"December", 12},
};
int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void process() {
    string s;
    bool isYoon;
    char c;
    int year, month, day, hour, minute, i;
    cin >> s >> day >> c >> year >> hour >> c >> minute;
    month = Month[s];
    isYoon = ( year % 400 == 0 || ( year%100 != 0 && year % 4 == 0 ) );
    m[2] += isYoon;

    ll total = (365ll + isYoon) * 24ll * 60ll;
    ll curr = 0 ;
    for ( i = 1 ; i < month ; i ++ ) curr += m[i];
    curr += day - 1;
    curr *= 24 * 60;
    curr += hour*60 + minute;

    curr *= 100l;
    cout << curr / total << '.';
    curr %= total;

    for ( i = 0 ; i < 50 ; i ++ ) {
        curr *= 10;
        cout << curr / total ;
        curr %= total;
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


