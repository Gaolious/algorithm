#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};

void process(int Case) {
    int Y, X, d, ty, tx, y, x, i;
    string s ;
    cin >> Y >> X ;
    cin.ignore();
    getline(cin, s);
    vector<string> ans(Y, string(X, 0));

    y = x = d = 0;
    for (auto c: s ) {
        int val = c == ' ' ? 0 : c-'A'+1;

        for ( i = 4 ; i >= 0 ; i -- ) {
            ans[y][x] = ( (val>>i) & 1) ? '1' : '0';

            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || ty >= Y || tx < 0 || tx >= X || ans[ty][tx] != 0 )
                d = (d+1)%4;
            y += dy[d];
            x += dx[d];
        }
    }
    for (auto &a: ans)
        for (auto &c : a)
            if ( c == 0 ) c = '0';

    for (auto &a: ans) cout << a ;
    cout << '\n';
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
