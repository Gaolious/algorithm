#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, i, j ;
    cin >> N ;
    vector<string> A(3, string(4*N,'.'));
    for ( i = 0 ; i < N ; i ++ ) {
        A[0][i] = 'G';
        A[1][N + i] = 'I';
        A[1][3*N + i] = 'T';
        A[2][2*N + i] = 'S';
    }
    for ( i = 0 ; i < 3 ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ )
            cout << A[i] << '\n';
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
