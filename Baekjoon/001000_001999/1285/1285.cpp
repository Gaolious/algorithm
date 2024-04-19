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

int N ;
int mask ;
struct Data {
    int A[20];
    int cnt[20];
};
void flip(Data &d, int n) {
    d.A[n] = (~d.A[n]) & mask ;
    for ( int i = 0 ; i < N ; i ++ ) {
        if ( d.A[n] & ( 1 << i ) ) {
            d.cnt[i] ++;
        }
        else {
            d.cnt[i] --;
        }
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i, j;
    char c;
    int ans, s ;

    Data init{} ;

    fastio;
    cin >> N ;

    ans = N*N ;

    mask = ( 1 << N ) - 1;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> c ;
            if ( c == 'T') {
                init.A[i] |= (1 << j );
                init.cnt[j] ++;
            }
        }
    }
    for ( i = 0 ; i <= mask ; i ++ ) {
        Data curr = init;
        for ( j = 0 ; j < N ; j ++ )
            if ( i & ( 1<<j ) )
                flip(curr, j);
        s = 0;
        for ( j = 0 ; j < N ; j ++ )
            s += min(curr.cnt[j], N-curr.cnt[j]);
        ans = min(ans, s);
    }

    cout << ans << '\n';
    return 0;
}


