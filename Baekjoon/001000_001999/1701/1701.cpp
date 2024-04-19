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

vector<int> table;

int kmp(int l, int r, string &s) {
    int i, j ;
    int N = r - l + 1;
    int ret = 0;

    for ( j = 0, i = j + 1 ; i < N ; i ++ ) {
        table[i] = 0;
        while ( j > 0 && s[l + i] != s[l + j] ) j = table[j-1];
        if ( s[l + i] == s[l + j] ) table[i] = ++j;
        ret = max(ret, table[i]);
    }
    return ret ;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    string s ;
    int N ;
    cin >> s ;

    N = s.size();
    table.resize(N);
    int ans = 0 ;
    for ( int i = 0 ; i < N ; i ++ )
        ans = max(ans, kmp(i, N-1, s) );
    cout << ans ;
    return 0;
}


