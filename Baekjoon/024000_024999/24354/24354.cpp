#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, i, j;
    cin >> N ;
    vector<int> A(N+1, 0);

    int maxCnt=0, maxVal;
    for ( i = 1 ; i <= N ; i ++ ) {
        for ( j = i ; j <= N ; j += i )
            A[j]++;
        if ( A[i] > maxCnt) {
            maxCnt = A[i];
            maxVal = i;
        }
    }
    cout << maxVal << '\n' << maxCnt << '\n';
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
