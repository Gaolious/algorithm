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
    int i, j;
    string S, P;
    cin >> S >> P ;
    vector<int> table(P.size());

    if ( P.size() <= S.size() ) {
        for ( j=0, i = 1 ; i< P.size() ; i++) {
            while ( j > 0 && P[i] != P[j] ) j = table[j-1];
            if ( P[i] == P[j] ) table[ i ] = ++j;
        }
        for ( j=0, i = 0 ; i< S.size() ; i++) {
            while ( j > 0 && S[i] != P[j] ) j = table[j-1];

            if ( S[i] == P[j] && ++j == P.size() ) {
                cout << "1\n";
                return 0;
            }
        }
    }
    cout << "0\n";

    return 0;
}


