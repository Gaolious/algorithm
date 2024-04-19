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

const int MOD = 1'000'000'009;
const int MaxN = 300;
int D[2][ MaxN+1 ][ MaxN+1 ];

int N, K ;
int F(int curr, int depth, bool flag ) {
    if ( curr >= N ) {
        return depth == 0 && flag;
    }
    auto &ret = D[flag][curr][depth];
    if ( ret < 0 ) {
        ret = F(curr+1, depth, flag);
        if ( depth < K )
            ret = ( ret + F(curr+1, depth + 1, flag || (depth+1 == K) ) ) % MOD ;
        if ( depth > 0 )
            ret = ( ret + F(curr+1, depth-1, flag) ) % MOD;
    }
    return ret ;
}
void process() {
    memset(D, -1, sizeof(D));
    cin >> N >> K ;
    cout << F(0, 0, K == 0) << '\n';
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


