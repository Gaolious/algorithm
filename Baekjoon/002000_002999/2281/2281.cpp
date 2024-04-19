#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef pair<int, int> pii ;

int N, X;

const int INF = 1000000000;

#define P2(x) ( (x) * (x) )

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, x, prevNewLine;
    cin >> N >> X ;
    vector<int> A(N), D(N, INF);

    for (auto &n: A) cin >> n;

    for ( i = 0 ; i < N ; i ++ ) {
        prevNewLine = i == 0 ? 0 : D[i-1];
        x = A[i];
        D[i] = min(D[i], prevNewLine + (i==N-1 ? 0 : P2(X-x) ));

        for ( j = i+1 ; j < N; j ++ ) {
            x += A[j] + 1;
            if ( x > X ) break;
            D[j] = min(D[j], prevNewLine + ( j == N-1 ? 0 : P2(X-x) ));
        }
    }
    cout << D[N-1];
    return 0;
}


