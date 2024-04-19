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
    vector<string> A;

    fastio;
    int i, j, ty, tx, d;

    cin >> Y >> X ;
    A.resize(Y);
    for (auto &s: A) cin >> s;
    for (i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ ) {
            if ( A[i][j] == 'W' ) {
                for (d = 0 ;d < 8 ; d +=2 ) {
                    ty = i + dy[d];
                    tx = j + dx[d];
                    if ( valid(ty, tx) && A[ty][tx] == 'S' ) {
                        cout << '0';
                        return 0;
                    }
                }
            }
        }
    cout << "1\n";
    for (auto &s: A) {
        for (auto &c : s ) {
            if ( c == '.' ) c = 'D';
        }
    }
    for (auto &s: A)
        cout << s << '\n';

    return 0;
}


