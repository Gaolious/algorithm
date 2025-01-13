#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, m, M, T, R;
    int r, x, t , a;
    cin >> N >> m >> M >> T >> R ;

    if ( m + T > M ) {
        cout << "-1\n";
        return;
    }
    x = m ;
    for ( t = r = 0 ; r < N ; t++ ) {
        if ( x + T > M ) {
            a = ( x + T - M ) / R ;
            if ( a > 1 ) {
                t += a-1;
                x -= (a-1)*R;
            }
            x = max(m, x - R);
        }
        else if ( x + T <= M ){
            x += T ;
            r ++;
        }
    }
    cout << t << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    init();
    // cin >> T;
    for ( int i=1 ; i <= T ; i ++ )
        process(i);
    return 0;
}
