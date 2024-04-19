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

vector<int> A;
vector<int> L, R;
vector<int> S;
int tail;
ll getMaxPos() {
    int N = A.size();
    int i;
    ll ans = 0;

    tail=-1;
    for ( i = 0 ; i < N ; i ++ ) {
        while ( tail >= 0 && A[ S[tail] ] <= A[i] ) R[ S[tail--] ] = i-1;
        S[++tail] = i;
    }
    while ( tail >= 0 ) { R[S[tail]] = N-1; tail--; }

    tail=-1;
    for ( i = N-1 ; i >= 0 ; i -- ) {
        while ( tail>=0 && A[ S[tail] ] < A[i] ) L[ S[tail--] ] = i+1;
        S[++tail] = i;
    }
    while ( tail>=0 ) { L[S[tail]] = 0; tail--; }

    for ( i = 0 ; i < N ; i ++ )
        ans += (ll)A[i] * ( (ll)(R[i]-i) * (i-L[i]) + R[i] - L[i] + 1 );
    return ans;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N;
    ll ans = 0 ;
    cin >> N;
    A.resize(N);
    L.resize(N); R.resize(N); S.resize(N);
    for (auto &n: A) cin >> n;
    ans += getMaxPos();
    for (auto &n: A) n = -n;
    ans += getMaxPos();
    cout << ans << '\n';
    return 0;
}


