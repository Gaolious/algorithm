#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
pll G(pll a){
    auto g = gcd(a.first, a.second);
    return {a.first/g, a.second/g};
}
bool operator < (pll a, ll b) { return a.first - a.second*b < 0; }
bool operator > (pll a, ll b) { return a.first - a.second*b > 0; }
pll operator / (pll a, pll b) {
    return G( { a.first * b.second, a.second * b.first} );
}

void process(int Case) {
    int N, a, b, p, q ;
    int i, j, k;

    cin >> N ;

    vector A(N, vector<pll>(N, {-1, 1}));
    for ( i = 0 ; i < N ; i ++ ) A[i][i].first = 1;

    for ( i = 0 ; i < N-1 ; i ++ ) {
        cin >> a >> b >> p >> q ;
        A[a][b] = G({p,q});
        A[b][a] = G({q, p});
    }

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            for ( k = 0 ; k < N ; k ++ ) {
                if ( i == j || i == k || j == k ) continue;
                if ( A[i][j] > 0 && A[i][k] > 0 && A[j][k] < 0 ) {
                    A[j][k] = A[i][k] / A[i][j];
                }
            }
        }
    }
    auto &row = A[0];
    ll lcm = row[0].first;
    for ( i = 0 ; i < N ; i ++ )
        lcm = lcm / gcd(lcm, row[i].first) * row[i].first ;
    for ( i = 0 ; i < N ; i ++ )
        cout << row[i].second * lcm / row[i].first << ' ';

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
