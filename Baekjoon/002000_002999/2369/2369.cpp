#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ull count(ull mask, ull N) {
    if ( N < mask ) return 0ull;
    else if ( min(mask*2 - 1, N )
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie();
    ull a, b, ans, cnt, mask;
    cin >> a >> b ;
    ans = 0 ;
    for ( mask = 1ull << 60 ; mask > 0 ; mask >>= 1 ) {
        cnt = (b/mask) - (a/mask);
        for ( int i = 62 ; i >= 0 ; i --)
        {
            if ( (i+1) % 4 == 0 ) cout << ' ';
            cout << (mask & (1ull<<i) ? '1':'0') ;
        }

        if ( cnt % 2 == 1 )
        {
            ans |= mask ;
            cout << " => 1";
        }
        else{
            cout << "";
        }
        cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}


