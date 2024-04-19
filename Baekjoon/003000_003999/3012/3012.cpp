#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
string S;
int N;
vector<vector<ll>> D;
const int INF = 100000000ll;
const int MOD = 100000ll;
int CtoN[127];

bool check(char a, char b) {
    if ( a == '?' ) {
        if ( b != '?' && CtoN[b] < 3 ) return false;
    }
    else {
        if ( CtoN[a] >= 3 ) return false;
        if ( b != '?' && CtoN[b] + CtoN[a] != 5 ) return false;
    }
    return true ;
}
ll F(int left, int right) {
    if ( right <= left ) return 1;
    if ( ( right - left + 1) % 2 != 0 ) return 0;
    auto &ret = D[ left ][ right ];
    if ( ret < 0 ) {
        int m, kinds ;
        ret = 0;
        for ( m = left + 1 ; m <= right ; m +=2 ) {
            if ( !check(S[left], S[m] ) ) continue;
            kinds = (S[left] == '?' && S[m] == '?' ) ? 3 : 1;
            ret += F(left+1, m-1) * F(m+1, right) * kinds;
            //
            // A B C A B C
            // | | |     |
            // +-+ +-----+
            // L m       R
            //
            // A B C A B C
            // |     | | |
            // +-----+ +-+
            // L     m   R
        }
    }
    if ( ret >= MOD ) {
        ret = ret % MOD + MOD ;
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
    CtoN['['] = 0;
    CtoN['('] = 1;
    CtoN['{'] = 2;
    CtoN['}'] = 3;
    CtoN[')'] = 4;
    CtoN[']'] = 5;

    cin >> N >> S;
    D.resize(N, vector<ll>(N, -1ll ) );
    ll ans = F(0, N-1);

    if ( ans >= MOD )
        cout << setw(5) << setfill('0') << (ans%MOD) ;
    else
        cout << ans ;
    return 0;
}


