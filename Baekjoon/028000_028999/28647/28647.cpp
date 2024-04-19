#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int N, S, odd, first ;
    int i, j, t;

    cin >>  N ;
    int digit = pow(10, N);

    int ans = 0;

    for ( i = 0 ; i < digit ; i ++ ) {
        S = odd = first = 0;
        for ( j = N, t = i ; t > 0 ; t /= 10, j-- ) {
            S += (t%10) ;
            if ( (N-j+1) % 2 == 1 ) odd += (t%10);
            if ( j <= N/2 ) first += (t%10);
        }
        if ( first * 2 == S && odd * 2 == S )
            ans ++;
    }
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


