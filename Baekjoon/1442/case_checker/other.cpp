#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int main()
{
    fastio;
    ll l, r;
    cin >> l >> r ;

    ll cnt = 0;
    for ( ll i = l ; i <= r ; i ++ ) {
        ll n1 = 0, n0 = 0;
        for ( ll t = i ; t > 0 ; t >>= 1) {

            if ( t & 1 ) n1 ++, n0 = 0;
            else n1 = 0, n0 ++;

            if ( n1 >= 3 || n0 >= 3 ) {
                cnt ++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
