#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

pair<int, int> range(int row, int col, int size) {
    int m = row * row + col ;
    return {m - size, m+size};
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, i, j, s, e, k, t; //, s2, e2 ;
    int ret, sum ;

    for ( int t = 1 ; cin >> N && N > 0 ; t ++ ) {
        vector<int> A(N*N);

        ret = -1000000000;

        for ( i = 0 ; i < N*N ; i ++ ) {
            cin >> A[ i ] ;
            ret = max(ret, A[i]);
            A[ i ] += i == 0 ? 0 : A[i-1];
        }

        for ( i = 0 ; i < N ; i ++ ) {
            s = i*i ;
            e = s + i*2 ;
            for ( j = s ; j <= e ; j ++ ) {
                if ( (j-s) % 2 == 0 ) {
                    for ( sum = 0, k = 0 ; i + k < N ; k ++ ) {
                        auto [s2, e2] = range(i+k, j-s+k, k);
                        sum += A[e2] - (s2 == 0 ? 0 : A[s2-1]);
                        // cout << "row " << i << ", col = " << j - s << ", size = " << k << ", range : " << s2 << " ~ " << e2 << ", sum = " << sum << '\n';
                        ret = max(ret, sum);
                    }
                }
                else {
                    for ( sum = 0, k = 0 ; i - k >= 0 && j-s >= 2*k && (i-k)*(i-k) + j-s < (i-k+1)*(i-k+1) ; k ++ ) {
                        auto [s2, e2] = range(i-k, j-s-k, k);
                        // cout << "row " << i << ", col = " << j - s << ", size = " << k << ", range : " << s2 << " ~ " << e2 << ", sum = " << sum << '\n';
                        sum += A[e2] - (s2 == 0 ? 0 : A[s2-1]);
                        ret = max(ret, sum);
                    }
                }
            }
        }
        cout << t << ". " << ret << '\n';
    }
    return 0;
}


