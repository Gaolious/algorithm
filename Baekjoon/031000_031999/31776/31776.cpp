#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, ans, i, j ;
    int A[3];
    ans =0;
    cin >> N ;

    for ( i = 0 ; i < N ; i ++ ) {
        for (j=0 ; j < 3 ; j ++ ) {
            cin >> A[j];
            if (A[j] < 0) A[j] = 121;
        }
        if (A[0] <= 120 && A[0] <= A[1] && A[1] <= A[2] ) ans ++;
    }
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
