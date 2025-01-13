#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int i, j, N, n, ans;
    cin >> N;
    for ( i = 1 ; i <= N ; i ++ ) {
        ans = 0 ;
        for (j = 0 ; j < 5 ; j ++ ) {
            cin >> n; ans = max(ans, n);
        }
        cout << "Case #" << i << ": " << ans << '\n';
    }
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