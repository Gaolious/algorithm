#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int i, j, N, ret;
    cin >> N ;
    vector<int>D(N+1, 0);
    for ( i = 2 ; i <= N ; i ++ ) {
        ret = 0 ;
        for ( j = 1 ; j+j <= i ; j ++ )
            ret = max(ret, j * (i-j) + D[j] + D[i-j]);
        D[i] = ret;
    }
    cout << D[N] << '\n';
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
