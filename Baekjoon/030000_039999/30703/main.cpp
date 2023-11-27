#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;

    int N;
    int i ;

    cin >> N ;
    int even = 0, odd = 0 ;
    vector<ll> A(N), B(N), X(N);
    ll ans, maxn = 0;
    for ( i = 0 ; i < N ; i ++) cin >> A[i];
    for ( i = 0 ; i < N ; i ++) cin >> B[i];
    for ( i = 0 ; i < N ; i ++) cin >> X[i];

    for ( i = 0 ; i < N ; i ++ ) {
        ans = (B[i] - A[i]) / X[i] ;
        if ( abs(B[i] - A[i]) % X[i] != 0 ) {
            even = odd = 1;
            break;
        }
        if ( abs(ans) % 2 == 0 ) even ++;
        else odd++;
        maxn = max( abs(ans), maxn);
    }
    if ( even > 0 && odd > 0 )
        cout << "-1\n";
    else {
        cout << maxn << "\n";
    }
    return 0;
}


