#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;

    int N ;
    int i ;

    cin >> N ;
    vector<ll> A(N) ;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[i];

    stack<ll> S;
    ll ans = 0 ;
    for ( i = 0 ; i < N ; i ++ ) {
        int left = i ;
        while ( !S.empty() && A[ S.top() ] > A[i] ) {
            ll H = A[ S.top() ];
            ll W = i ;
            S.pop();
            if ( !S.empty() )
                W = ( i - S.top() - 1 );
            ans = max( ans, W * H );
        }
        S.push(i);
    }
    while (!S.empty()) {
        ll H = A[ S.top() ];
        ll W = i ;
        S.pop();
        if ( !S.empty() )
            W = ( i - S.top() - 1 );
        ans = max( ans, W * H );
    }
    cout << ans ;

    return 0;
}


