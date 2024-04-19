#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector< vector<int> > D;
vector<int> A;
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;

    cin >> N;

    A.resize(N);
    for (auto &n: A) cin >> n;

    D.resize(N, vector<int>(N, 0));
    int len, s, e, m ;

    for ( len=1 ; len < N ; len ++ ) {
        for ( s = 0 ; s + len < N ; s ++ ) {
            e = s + len ;
            auto &d = D[s][e];
            d = max(d, D[s+1][e-1] + ( A[s] == A[e] ? 1 : 0 ) );
            for ( m = s ; m < e ; m ++ )
                d = max(d, D[s][m] + D[m+1][e]);
        }
    }
    cout << D[0][N-1] << '\n';
    return 0;
}


