#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef pair<int, int> pii ;

int N, X;

int D[1000][1000];
int S[1000];
vector<int> A;
const int INF = 1000000000;
int Sum(int from, int to) {
    if ( to < from || to < 0 || from < 0 || to >= N || from >= N)
        return 0;
    int ret ;
    ret = A[to];
    if ( from ) ret -= A[from - 1];
    return ret + (to-from);
}

int F(int from, int to) {
    if ( to < from ) return 0;

    int &ret = D[from][to];
    if ( ret < 0 ) {
        ret = INF;
        if ( to <= S[from] ) {
            int t = ( to == N-1 ) ? 0 : X - Sum(from, to);
            ret = t*t;
        }
        else {
            for( int m = S[from] ; m >= from ; m -- )
                ret = min(ret, F(from, m) + F(m+1, to));
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
    int i, j;
    cin >> N >> X ;
    memset(D, -1, sizeof(D));
    memset(S, -1, sizeof(S));

    A.resize(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i] ;
        if ( i ) A[i] += A[i-1];
    }

    for ( j = 0 ; j < N ; j ++ ) {
        if ( Sum(0, j) <= X ) S[0] = j;
        else break;
    }

    for ( i = 1 ; i < N ; i++ )
        for ( j = S[i-1]; j < N && Sum(i, j) <= X ; j++ )
            S[i] = j;

    cout << F(0, N-1) << '\n';
    return 0;
}


