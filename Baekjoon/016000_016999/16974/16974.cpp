#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

pair<ll, ll> A[51]; // 총 길이, 페티 개수

ll F(ll N, ll X) {
    if ( X >= A[N].first ) return A[N].second;
    if ( X <= 0 ) return 0;

    if ( X <= 1 + A[N-1].first ) return F(N-1, X-1);
    if ( X <= 1 + A[N-1].first + 1 ) return F(N-1, X-2) + 1;
    return F(N-1, X - 2 - A[N-1].first) + A[N-1].second + 1;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    ll N, X;

    cin >> N >> X;
    A[0] = { 1, 1};
    for ( int i = 1 ; i <= 50 ; i ++ ) {
        A[i] = { A[i-1].first * 2 + 3, A[i-1].second * 2 + 1};
    }

    cout << F(N, X);
    return 0;
}


/*
 *  P               1
 *      BPPPB       3+F(n-1)*2 =
 *
 *      B BPPPB P BPPPB B   13
 * B [B BPPPB P BPPPB B] P B BPPPB P BPPPB B P
 *
 */