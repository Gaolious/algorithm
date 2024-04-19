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

vector<ll> A;

ll HowManyChild(ll maxMinute ) {
    ll ret = 0;
    for (auto n : A ) ret += maxMinute / n ;
    return ret;
}
ll FindLastEquip(ll maxMinute, ll N) {
    priority_queue<pll> Q;
    ll minMinute = A[0];
    for (auto n: A) minMinute = max(minMinute, n);

    ll t;
    for ( int i = 0 ; i < A.size() ; i ++ ) {
        t = max(0ll, (maxMinute-minMinute)) / A[i] ;
        Q.emplace(-t * A[i], -i );
        N -= t;
    }
    while ( N > 0 ) {
        auto [endTime, currNo] = Q.top();
        endTime = -endTime;
        currNo = -currNo;
        Q.pop();
        if ( N == 1 )
            return currNo + 1;
        N --;
        Q.emplace( -(endTime + A[currNo]), -currNo);
    }
    return 0;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll N, M, minHour = 31, maxHour = 0;
    cin >> N >> M ;
    A.resize(M);

    minHour = -1;
    for ( auto &n: A) {
        cin >> n ;
        minHour = min(minHour, n);
        maxHour = max(maxHour, n);
    }

    ll l = minHour * N, r = maxHour * N, m ;
    ll best = r + 1;
    while ( l <= r ) {
        m = (l+r) / 2ll ;
        if ( HowManyChild(m) >= N ) {
            r = m-1 ;
            best = min(best, m);
        }
        else
            l = m + 1;
    }
    cout << FindLastEquip(best, N) << '\n';

    return 0;
}


