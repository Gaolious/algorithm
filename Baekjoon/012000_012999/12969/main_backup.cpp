#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int D[31][31][31][500];

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, K, i, s, len, a, b, c;
    cin >> N >> K ;
    D[1][1][0][0] = 1;
    D[1][0][1][0] = 2;
    D[1][0][0][0] = 3;

    for ( len = 2 ; len <= N ; len ++ ) {
        for ( a = 0 ; a < len ; a ++ ) {
            for ( b = 0 ; a+b < len ; b ++ ) {
                for ( s = 0 ; s <= 420 ; s ++ ) {
                    if ( D[len-1][a][b][s] > 0 ) {
                        D[len][a+1][b][s] = 1;
                        D[len][a][b+1][s+a] = 2;
                        D[len][a][b][s+a+b] = 3;
                    }
                }
            }
        }
    }
    string ans;
    for ( a = 0 ; a <= N ; a ++ ) {
        for ( b = 0 ; a+b <= N ; b ++ ) {
            if ( D[N][a][b][K] > 0 ) {
                for ( i = N ; i > 0 ; i -- ) {
                    ans.push_back( (char) ( 'A' + D[i][a][b][K] - 1 ) );
                    if ( D[i][a][b][K] == 1 ) a=max(0,a-1);
                    else if ( D[i][a][b][K] == 2 ) K-=a, b=max(0,b-1);
                    else if ( D[i][a][b][K] == 3 ) K-=a+b;
                }
                reverse(ans.begin(), ans.end());
                cout << ans << '\n';
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}


