#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
struct Data {
    int finishTime{};
    int totalV{};
};
void process(int Case) {
    int M; // 주문수
    int t, v, z[2];
    Data A[2]={0,};
    int i ;

    cin >> M ;
    while ( M -- ) {
        cin >> t >> v >> z[0] >> z[1];
        int minIndex = -1, minValue;
        for ( i = 0 ; i < 2 ; i ++ ) {
            if (A[i].finishTime <= t) {
                if (minIndex < 0 || minValue > z[i])
                    minIndex = i, minValue = z[i];
            }
        }
        if ( minIndex >= 0 ) {
            A[minIndex].finishTime = t + z[minIndex];
            A[minIndex].totalV += v;
        }
    }
    cout << A[0].totalV << ' ' << A[1].totalV << '\n';
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
