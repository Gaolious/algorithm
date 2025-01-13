#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};
void init(){
}
void process(int Case) {
    int Y, X, d, ty, tx, y, x, idx;
    char c;
    string s ;
    cin >> Y >> X >> s ;
    vector flag(Y, vector<bool>(X, false));

    y = x = d = 0;
    c = 0;
    string ans ;

    for ( int i = 0 ; i < Y*X ; i ++ ) {
        idx = y * X + x;
        flag[y][x] = true;
        c <<=1;
        if (idx < s.size()) c += s[idx]-'0';

        if ( (i+1) % 5 == 0 ) {
            if ( c == 0 ) ans.push_back(' ');
            else ans.push_back((char)(c - 1 + 'A'));
            c = 0;
        }
        ty = y + dy[d];
        tx = x + dx[d];
        if ( ty < 0 || tx < 0 || ty >= Y || tx >= X || flag[ty][tx] ) d = (d+1)%4;
        y += dy[d];
        x += dx[d];
    }
    while ( ans.back() == ' ' ) ans.pop_back();
//    cout << Case << ' ' << ans << '\n';
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
    cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
