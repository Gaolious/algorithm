#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    vector<bitset<35>> A;
    int N, i, j, k;
    string s;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        auto &d = A.emplace_back();
        for ( j = 0 ; j < 5 ; j ++ ){
            cin >> s ;
            for ( k = 0 ; k < 7 ; k ++ )
                d[j*7+k] = s[k] == '.' ? 0 : 1 ;
        }
    }
    pii ans = {-1, -1};
    int minDiff = -1;
    for ( i = 0 ; i < N-1 ; i ++ ) {
        for ( j = i+1 ; j < N ; j ++ ) {
            k = (A[i]^A[j]).count();
            if ( minDiff < 0 || minDiff > k ) {
                ans = {i+1, j+1};
                minDiff = k;
            }
        }
    }
    cout << ans.first << ' ' << ans.second;
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
