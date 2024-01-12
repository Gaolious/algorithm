#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N, M, K, Q;
int D[301][10001]{};
int main()
{
    fastio;
    int i, k, j, v ;
    int t;
    int worker_no, store_no;
    int ret = 0;

    cin >> N >> M >> K;

    vector<int> BestSalePrice = vector<int>(M+1, 0);
    vector<int> BestSaleWorker = vector<int>(M+1, 0);
    vector<int> NumberOfRank1Store = vector<int>(N+1, 0);

    for ( worker_no = 1 ; worker_no <= N ; worker_no ++ ) {
        for ( k = 0 ; k < K ; k ++ ) {
            cin >> store_no >> t ;
            D[worker_no][store_no] = t;
            if ( BestSalePrice[store_no] < t ) {
                BestSalePrice[store_no] = t ;
                BestSaleWorker[store_no] = worker_no;
            }
        }
    }

    for ( store_no = 1 ; store_no <= M ; store_no ++ )
        NumberOfRank1Store[ BestSaleWorker[store_no] ]++;

    ret = 0;
    for ( worker_no = 1 ; worker_no <= N ; worker_no ++ )
        if ( NumberOfRank1Store[ worker_no ] == K )
            ret ++;

    cin >> Q;

    while (Q--) {
        cin >> worker_no >> store_no >> v ;
        D[worker_no][store_no] += v ;

        if ( D[worker_no][store_no] > BestSalePrice[store_no] ) {
            BestSalePrice[store_no] = D[worker_no][store_no];

            if ( BestSaleWorker[store_no] != worker_no) {
                if ( NumberOfRank1Store[ BestSaleWorker[store_no] ]-- == K) ret--;
                if ( ++NumberOfRank1Store[worker_no] == K ) ret ++;
                BestSaleWorker[store_no] = worker_no ;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}


