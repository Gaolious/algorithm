#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
void init(){
}
void process(int Case) {
    int N, M, i;
    cin >> N >> M ;
    vector<pii> A(N);
    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ].first ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[ i ].second ;
        A[i].second -= A[i].first;
    }

    std::sort(A.begin(), A.end(), [](pii a, pii b){
        return a.second < b.second;
    });
    for (i = 0 ;  i < N && M >= A[i].second ; i++)
        M += A[i].first;
    cout << M << '\n';
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
