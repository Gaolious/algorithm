#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    string A;
    cin >> A;
    ll ans = 1 , t;
    for ( int i = 0 ; i < A.size() ; i ++ ) {
        t = A[i] == 'd' ? 10 : 26;
        if ( i > 0 && A[i-1] == A[i] ) t--;
        ans *= t;
    }
    cout << ans ;
    return 0;
}


