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
const int INF = 100000;

vector<int> A;
pair<int, int> find(int diff) {
    int group = 1, ret = 0 ;
    int minv, maxv;
    minv = INF, maxv = 0;

    for (auto n: A) {
        minv = min(minv, n);
        maxv = max(maxv, n);
        if ( maxv - minv > diff ) {
            group ++;
            minv = n, maxv = n;
        }
        ret = max(ret, maxv - minv);
    }
    return {group, ret};
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, M;
    int L, H, l, r, m ;
    L = INF, H = 0 ;
    cin >> N >> M ;
    A.resize(N);
    for (auto &n: A) {
        cin >> n ;
        L = min(L, n);
        H = max(H, n);
    }

    l = 0, r = H ;
    int best = INF ;
    while ( l < r ) {
        m = ( l + r ) /2 ;
        auto [group, maxv] = find(m);
        if ( group <= M ) {
            best = min(best, maxv);
            r = m ;
        }
        else l = m + 1;
    }
    cout << best << '\n';

    return 0;
}


