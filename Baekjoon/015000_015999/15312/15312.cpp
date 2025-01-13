#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int i, j;
    char C[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    string s1, s2;
    int N ;
    cin >> s1 >> s2;
    N = s1.size();
    vector<int> A(N*2);
    for (i = 0 ; i < N ; i++) A[i*2] = C[ s1[i]-'A' ];
    for (i = 0 ; i < N ; i++) A[i*2+1] = C[ s2[i]-'A' ];

    for ( i = 0 ; i < (N-1)*2 ; i ++ ) {
        for ( j = 1 ; j < N*2-i  ; j ++ ) {
            A[j-1] = (A[j-1]+A[j])%10;
        }
    }
    cout << A[0] << A[1];
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
