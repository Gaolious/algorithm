#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int D[51][51][51][51];
const int MOD = 1000000007;

int F(int S, int d, int k, int h) {

    if ( S < 0 || d < 0 || k < 0 || h < 0 ) return 0;
    if ( S == 0 && d == 0 && k == 0 && h == 0 ) return 1;

    int &ret = D[S][d][k][h];
    if ( ret < 0 ) {
        ret = 0 ;
        for ( int i = 1 ; i <= 7 ; i ++ ) {
            ret += F(S-1, d - ( (i >> 2 )&1 ), k - ( (i >> 1 ) & 1 ) , h - ( (i >> 0 ) & 1 ));
            ret %= MOD;
        }
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
    int S, d, k, h;

    memset(D, -1, sizeof(D));

    cin >> S >> d >> k >> h ;

    cout << F(S, d, k, h) << '\n';

    return 0;
}


