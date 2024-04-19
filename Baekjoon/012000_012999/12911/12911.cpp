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

const ll MOD =  1000000007ll;

void process() {
    int N, K ;
    int i, j, t;
    ll ss;

    cin >> N >> K ;
    vector D = vector(N+1, vector<ll>(K+1, 0));
    vector<ll> S(N+1, 0);

    for ( i = 1 ; i <= K ; i ++ ) D[1][i] = 1 ;
    S[1] = K ;
    for ( i = 2 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= K ; j ++ ) {
            for ( ss = 0, t=j*2 ; t <= K ; t += j)
                ss = (ss + D[i-1][t]) % MOD;
            D[i][j] = (S[i-1] - ss + MOD) % MOD ;
            S[i] = (S[i] + D[i][j]) % MOD;
        }
    }
    cout << S[N] << '\n';
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


