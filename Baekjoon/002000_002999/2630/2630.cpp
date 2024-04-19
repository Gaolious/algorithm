#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[128+1][128+1]={0,};
int S(int sy, int sx, int N) {
    return A[sy+N-1][sx+N-1] - A[sy-1][sx+N-1] - A[sy+N-1][sx-1] + A[sy-1][sx-1];
}
pair<int, int> F(int sy, int sx, int N) {
    int s = S(sy, sx, N);
    if ( s == N*N )
        return {1, 0};
    else if ( s == 0 )
        return {0, 1};
    else {
        int n = N / 2;
        pair<int, int> ret = {0, 0};
        for(auto x : {0, n})
            for (auto y: {0, n}) {
                auto r = F(sy+y, sx+x, n);
                ret.first += r.first;
                ret.second += r.second;
            }
        return ret;
    }
}
int main()
{
    fastio;
    int i, j ;
    int N ;

    cin >> N ;
    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = 1 ; j <= N ; j ++ ) {
            cin >> A[i][j];
            A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        }
    }

    auto ret = F(1, 1, N);
    cout << ret.second << '\n' << ret.first << '\n';
    return 0;
}


