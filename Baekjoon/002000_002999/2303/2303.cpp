#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, b[5], i, j, k, s, t;
    cin >> N;
    vector<pii> A(N);
    for ( i = 0 ; i < N ; i ++ ) {
        A[i] = {-1, i+1};
        for ( s = j = 0 ; j < 5 ; j ++ ){
            cin >> b[j]; s+= b[j];
        }
        for ( j = 0 ; j < 5 ; j ++ ) {
            for ( k = j + 1 ; k < 5 ; k ++ ) {
                t = (s - b[j] - b[k])%10;
                if ( A[i].first < 0 || A[i].first < t )
                    A[i].first = t;
            }
        }
    }

    std::sort(A.begin(), A.end(), [](pii &a, pii &b){
        return ( a.first != b.first ) ? a.first > b.first : a.second > b.second;
    });
    cout << A[0].second;
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
