#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

int main() {
    fastio;
    ll N, d1, c1, d2, c2;
    cin >> N >> d1 >> c1 >> d2 >> c2 ;
    for ( ll i = N ; ; i ++ ) {
        int cnt[10]={0, };
        for (ll t = i ; t > 0 ; t /= 10) {
            cnt[ t % 10 ] ++;
        }
        if (cnt[d1] >= c1 && cnt[d2] >= c2)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
