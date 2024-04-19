#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

const int MaxN = 1'000'000;
int D[MaxN + 1] = {};
void process() {
    int i, n, N, M, ans, T ;
    D[0] = 1;
    for ( i = 1 ; i <= MaxN ; i ++ ) {
        for ( n = i ; n > 0 ; n /= 10 )
            if ( n % 10 == 0 )
                D[i] ++;
        D[i] += D[i-1];
    }
    cin >> T ;
    while ( T-- ) {
        cin >> N >> M ;
        ans = D[M];
        if ( N > 0 ) ans -= D[N-1];
        cout << ans << '\n';
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


