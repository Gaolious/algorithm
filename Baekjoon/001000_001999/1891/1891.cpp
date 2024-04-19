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


int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N;
    ll size, sx, sy, addX, addY, x, y;
    string s, ans;
    cin >> N >> s;
    cin >> addX >> addY;
    size = 1ll << N ;
    sx = sy = 0 ;
    for (auto c: s ) {
        if ( c == '2' || c == '1' ) sy += size / 2ll;
        if ( c == '1' || c == '4' ) sx += size / 2ll;
        size /= 2ll ;
    }
    sy += addY, sx += addX;
    x = y = 0;
    size = 1ll << N ;
    if ( sx < 0 || sx >= size || sy < 0 || sy >= size ) {
        cout << "-1\n";
        return 0;
    }

    for ( int i = 0 ; i < N ; i ++ ) {
        if ( x + size/2ll <= sx && y + size/2ll <= sy ) {
            x += size/2ll;
            y += size/2ll;
            ans.push_back('1');
        }
        else if ( x + size/2ll <= sx ) {
            x += size/2ll;
            ans.push_back('4');
        }
        else if ( y + size/2ll <= sy ) {
            y += size/2ll;
            ans.push_back('2');
        }
        else {
            ans.push_back('3');
        }
        size >>=1l;
    }
    cout << ans;
    return 0;
}


