#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, L, D;
    int i, x ;
    // 총 노래가 N곡이 들어있고,
    // 모든 노래의 길이는 L초이다
    // 노래와 노래 사이 5초
    // 0초부터 D초마다 1초씩 한번씩 울림
    // 0~5, 10~15 20~25
    cin >> N >> L >> D ;
    vector<int> A = {0, L};
    for ( i = 1 ; i < N ; i ++ ) {
        A.emplace_back(A.back() + 5);
        A.emplace_back(A.back() + L);
    }
    x = 0;
    for ( i = 2 ; i < A.size() ; i += 2 ) {
        if ( x < A[i-1] ) {
            x += D * ceil((double)(A[i-1]-x) / (double) D);
        }
        if ( A[i-1] < x && x < A[i] ) {
            cout << x ;
            return;
        }
    }
    if ( x <= A.back() ) {
        x += D * ceil((double)(A.back()+1-x) / (double) D);
    }
    cout << x ;

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
