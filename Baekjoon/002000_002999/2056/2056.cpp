#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<vector<int>> A;
vector<int> T;
int N ;
vector<int> D;

int F(int n) {
    auto &ret = D[n] ;
    if ( ret < 0 ) {
        ret = T[n];
        for( auto nxt : A[n] )
            ret = max(ret, F(nxt) + T[n]);
    }
    return ret;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, n;
    cin >> N ;
    D.resize(N, -1);
    T.resize(N);
    A.resize(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> T[i] ;
        cin >> n ;
        A[i].resize(n);
        for (auto &t: A[i] ) {
            cin >> t ;
            t--;
        }
    }
    int ans = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        ans = max(ans, F(i));
        // cout << "i = " << i << ", T = " << F(i) << '\n';
    }
    cout << ans ;
    return 0;
}


