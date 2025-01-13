#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void dump(vector<int> &A) {
    for (auto n: A) cout << n << ' ' ;
    cout << '\n';
}
void process(int Case) {
    int N, M, i, j, k;
    cin >> N ;
    vector<int> A(N);
    for (auto &n: A) cin >> n ;
    cin >> M;
    vector<int> W(M);
    for (auto &n: W) cin >> n ;

    std::sort(A.begin(), A.end(), greater<>());
    std::sort(W.begin(), W.end(), greater<>());
    if ( A[0] < W[0] ) {
        cout << "-1\n";
        return;
    }
    int cnt ;
    for ( cnt = 0 ; !W.empty() ; cnt ++ ) {
        for ( i = j = k = 0 ; i < N ; i ++ ) {
            for ( ; j < W.size() && A[i] < W[j] ; j ++ ) W[k++] = W[j];
            if ( j < W.size() && A[i] >= W[j] ) j++;
        }
        for ( ; j < W.size() ; j ++ ) W[k++] = W[j];

        if ( k != W.size() ) W.resize(k);
    }
    cout << cnt << '\n';
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
