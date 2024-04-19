#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
pair<int, int> Remain[20000+1];

bool FindAndPrint(int N) {
    queue<int> Q;
    int i, t ;

    for ( i = 0 ; i <= 20000 ; i ++ )
        Remain[i] = {-1, -1};
    Remain[ 1 % N ] = {-1, 1};
    Q.push(1);

    while ( !Q.empty() ) {
        auto n = Q.front();
        Q.pop();
        for ( i = 0 ; i <= 1 ; i ++ ) {
            t = (n * 10 + i) % N ;

            if ( Remain[t].second < 0 ) {
                Remain[t] = {n, i};
                Q.emplace(t);
            }

            if ( t == 0 ) {
                string ans ;
                for ( int j = 0 ; j >= 0 ; j = Remain[j].first )
                    ans.push_back( (char)( '0' + Remain[j].second )) ;
                reverse(ans.begin(), ans.end());
                cout << ans << '\n';
                return true;
            }
        }
    }
    return false;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n ;
        if ( !FindAndPrint(n) ) {
            cout << "BRAK\n";
        }
    }
    return 0;
}


