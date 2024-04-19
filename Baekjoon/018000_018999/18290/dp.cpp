#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int INF = 100000000;

int A[10][10];
int Y, X;
int K;
vector<pair<int, int>> valid_bits ;
int D[11][101][1024+1];

bool is_valid(int choose) {
    while (choose) {
        if ( (choose & 0x03) == 0x03 ) return false;
        choose >>= 1;
    }
    return true;
}
int F(int y, int choose) {
    int x;
    int ret = 0 ;
    if ( choose ) {
        for ( x = 0 ; x < 10 && choose; x ++, choose >>= 1)
            if ( choose & 1)
                ret += A[y][x];
    }
    return ret;
}
int recur(int y, int cnt, int prev_mask, int score) {
    if ( cnt > K || y < 0 )
        return -INF;
    if ( (y+1)*(X+1)/2 + cnt < K )
        return -INF;
    if ( cnt == K ) {

        return score;
    }
    auto &ret = D[y][cnt][prev_mask] ;
    if ( ret <= -INF ) {
        for (auto [bit_count, mask] : valid_bits ) {
            if ( prev_mask & mask ) continue;
            if ( cnt + bit_count > K ) break;
            ret = max(ret, recur(y-1, cnt+bit_count, mask, score + F(y-1, mask)));
        }
    }
    return ret;
}
int main()
{
    fastio;
    cin >> Y >> X >> K ;
    int i, j, maxbit = (1<<X) - 1 ;
    for ( i = 0 ; i <= Y ; i ++ )
        for ( j = 0 ; j <= 100 ; j ++ )
            for ( int k = 0 ; k <= 1024 ; k ++ )
                D[i][j][k] = -INF ;

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];
    for ( j = 0 ; j <= maxbit ; j ++ ) {
        if ( is_valid(j) )
            valid_bits.emplace_back(__builtin_popcount(j), j);
    }
    sort(valid_bits.begin(), valid_bits.end());

    cout << recur(Y, 0, 0, 0);
    return 0;
}


