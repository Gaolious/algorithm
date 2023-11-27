#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll N, K;
ll cnt;
vector<int> ans;
bool F(int n) {
    if ( n == 0 )
        return ( K == ++cnt );

    for ( int i = 1 ; i <= 3 && i <= n ; i ++ )
        if ( F(n-i) ) {
            ans.push_back(i);
            return true;
        }
    return false;
}
int main()
{
    fastio;
    cin >> N >> K ;
    bool ret = F(N) ;
    if ( ret ) {
        std::reverse(ans.begin(), ans.end());
        for ( int i = 0 ; i < ans.size() ; i ++ ) {
            if ( i ) cout << '+';
            cout << ans[i];
        }
    } else {
        cout << "-1";
    }
    return 0;
}


