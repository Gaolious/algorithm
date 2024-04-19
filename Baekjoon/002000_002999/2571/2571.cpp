#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<vector<char>> Map;
char T[101][101];

vector<ll> X, Y;
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll N, i, j, sx, sy, ex, ey, x, y ;
    cin >> N ;
    vector<pair<int, int>> A(N);

    for ( auto &[a,b] : A) {
        cin >> b >> a ;
        Y.push_back(a); Y.push_back(a+10);
        X.push_back(b); X.push_back(b+10);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    Map.resize(Y.size()-1, vector<char>(X.size()-1, 0));

    for ( auto &[a,b] : A) {
        sy = lower_bound(Y.begin(), Y.end(), a) - Y.begin();
        sx = lower_bound(X.begin(), X.end(), b) - X.begin();
        ey = lower_bound(Y.begin(), Y.end(), a+10) - Y.begin();
        ex = lower_bound(X.begin(), X.end(), b+10) - X.begin();

        for ( i = sy ; i < ey ; i ++ )
            for ( j = sx ; j < ex ; j ++ ) {
                Map[i][j] = 1;
            }
    }
    vector H(Y.size() - 1, vector<ll>(X.size() - 1, 0ll));

    for ( sx = 0 ; sx + 1 < X.size() ; sx ++) {
        ey = Y.size() - 1;
        for ( sy = ey-1 ; sy >= 0 ; sy -- ) {
            if ( Map[sy][sx] == 0 )
                H[sy][sx] = 0, ey = sy;
            else
                H[sy][sx] = Y[ey] - Y[sy];
        }
    }
    ll area = 0;
    for ( i = 0 ; i + 1 < Y.size() ; i ++ ) {
        for ( sx = 0 ; sx + 1 < X.size() ; sx ++) {
            if ( Map[i][sx] == 0 ) continue;
            y = H[i][sx];
            for ( ex = sx ; ex + 1 < X.size() && Map[i][ex] == 1; ex ++ ) {
                y = min(y, H[i][ex]);
                x = X[ex+1] - X[sx];
                area = max(area, y*x);
            }
        }
    }
    cout << area << '\n';
    return 0;
}


