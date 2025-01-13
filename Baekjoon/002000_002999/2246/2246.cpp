#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
struct Data {
    int dist, cost;
    bool r1, r2;
};
void process(int Case) {
    int N, i ;
    cin >> N;
    vector<Data> A(N);
    vector<int> C(N);
    for (auto &a: A) {
        cin >> a.dist >> a.cost;
        a.r1 = a.r2 = true;
    }
    std::sort(A.begin(), A.end(), [](Data &a, Data &b) {
        return a.dist < b.dist;
    });
    for ( C[0] = A[0].cost, i = 1 ; i < N ; i ++ ) C[i] = min(C[i-1], A[i].cost);
    for ( i=1 ; i < N ; i ++ )
        if ( C[i-1] <= A[i].cost )
            A[i].r1 = false;

    std::sort(A.begin(), A.end(), [](Data &a, Data &b) {
        return a.cost < b.cost;
    });
    for ( C[0] = A[0].dist, i = 1 ; i < N ; i ++ ) C[i] = min(C[i-1], A[i].dist);
    for ( i=1 ; i < N ; i ++ )
        if ( C[i-1] <= A[i].dist )
            A[i].r2 = false;

    int ans = 0 ;
    for ( i=0 ; i < N ; i ++ )
        if ( A[i].r1 && A[i].r2 ) ans ++;
    cout << ans << '\n';
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
