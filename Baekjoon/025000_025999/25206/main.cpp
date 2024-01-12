#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

long double S(string s ) {

}
int main()
{
    fastio;
    string s, deg ;
    long double score, total, p ;
    total = score = 0.0;
    for ( int i = 0 ; i < 20 ; i ++ ) {
        cin >> s >> p >> deg ;
        if (deg[0] == 'P') continue;
        if ( 'A' <= deg[0] && deg[0] <= 'D' ) {
            score += (69 - deg[0] + (deg[1] == '+' ? 0.5:0.0) ) * p;
        }
        total += p;
    }
    cout << fixed << setprecision(12) << score / total << '\n';
    return 0;
}


