#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, K, i, j;
    char c;
    cin >> N >> K ;
    vector<int> A(N) ;
    for ( i = 0 ; i < N ; i ++ ) {
        if ( i > 0 ) cin >> c ;
        cin >> A[i];
    }

    for (i = 0 ; i < K ; i ++ ) {
        for ( j = 0 ; j + 1 < A.size() ; j ++ )
            A[j] = A[j+1] - A[j];
        A.pop_back();
    }
    for ( j = 0 ; j < A.size() ; j ++ ) {
        if ( j > 0 ) cout << ',';
        cout << A[j] ;
    }
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
