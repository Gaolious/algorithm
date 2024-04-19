#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int INF = 100000000;

int A[10][10];
int Score[10][1024];
int Y, X;
int K;
vector<pair<int, int>> valid_bits ;

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
    for ( x = 0 ; x < X ; x ++, choose >>= 1)
        if ( choose & 1)
            ret += A[y][x];
    return ret;
}

int D[10][51][1024];

int main()
{
    fastio;
    cin >> Y >> X >> K ;
    int i, j, k, maxbit = (1<<X) - 1 ;

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < 51 ; j ++ )
            for ( k = 0 ; k < 1024 ; k ++ ) {
                D[i][j][k] = -INF;

            }

    for ( i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];

    for ( j = 0 ; j <= maxbit ; j ++ )
        if ( is_valid(j) )
            valid_bits.emplace_back(__builtin_popcount(j), j);

    for ( i = 0 ; i < Y ; i ++ )
        for (auto [bit_cnt, mask] : valid_bits)
            Score[i][mask] = F(i, mask);

    for (auto [bit_cnt, mask] : valid_bits)
        D[0][bit_cnt][mask] = max(D[0][bit_cnt][mask], Score[0][mask]);

    for ( i = 1 ; i < Y ; i ++ ) {
        for( k = 0 ; k <= K ; k ++ ) {
            for (auto [prev_bit_cnt, prev_mask] : valid_bits) {
                for (auto [curr_bit_cnt, curr_mask] : valid_bits) {
                    if ( prev_mask & curr_mask) continue;
                    int sum_bit_count = k + curr_bit_cnt ;
                    if ( sum_bit_count > K) continue;

                    if ( D[i][sum_bit_count][curr_mask] < D[i-1][k][prev_mask] + Score[i][curr_mask] ) {
                        D[i][sum_bit_count][curr_mask] = D[i-1][k][prev_mask] + Score[i][curr_mask];
                    }
                }
            }
        }
    }
    int ret = -INF;

    for (i = 0 ; i <= maxbit ; i ++ ) {
        if ( ret < D[Y-1][K][i] ) {
            ret = D[Y-1][K][i];
        }
    }
    cout << ret << '\n';

    return 0;
}


