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

int N ;
const int INF = 1000000000;
void click(string &s, int i) {
    for ( int j = i - 1 ; j <= i + 1 ; j ++ ) {
        if ( j >= s.size() || j < 0 ) continue;
        s[j] = s[j] == '0' ? '1' : '0';
    }
}

int sol(string src, string &dest, bool startClick) {
    int i ;
    int cnt = 0 ;
    if (startClick) {
        cnt++;
        click(src, 0);
    }
    for ( i = 1 ; i < src.size() ; i ++ ) {
        if ( src[i-1] != dest[i-1] ) {
            click(src, i);
            cnt++;
        }
    }
    return ( src == dest ) ? cnt : INF;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int t, ans = INF  ;

    string S[2] ;
    cin >> N >> S[0] >> S[1];

    ans = min(ans, sol(S[0], S[1], false));
    ans = min(ans, sol(S[0], S[1], true));

    cout << ( ( ans >= INF ) ? -1 : ans ) << '\n'; ;
    return 0;
}


