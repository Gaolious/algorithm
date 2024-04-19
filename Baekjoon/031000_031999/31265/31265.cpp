#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N, M, i, j, k, t, curr, prev;
    cin >> N >> M ;
    vector<int> D(M+1, -1);
    vector<int> T(N);
    for (auto &t : T) cin >> t;

    D[0] = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        for (j = 0 ; j < T[i] ; j ++) {
            cin >> t ;
            for ( k = M; k >= t ; k-- ) {
                if (D[k-t] >= i)
                    D[k] = i+1;
            }
        }
    }
    int ret = -1;
    for ( i = 1 ; i <= M ; i ++ ) {
        if ( D[i] == N) {
            ret = max(ret, i);
        }
    }
    cout << ret << '\n';
    return 0;
}
