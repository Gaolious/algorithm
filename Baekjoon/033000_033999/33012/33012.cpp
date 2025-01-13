#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
	int i, N, l, r ;
	cin >> N ;
	vector<int> A(N);
	for ( i = 1, l=0, r=N-1 ; i <= N ; i ++ )
	{
		if ( i % 2 == 1 ) A[l++] = i;
		else A[r--] = i;
	}
	for (auto n : A) cout << n << ' ';
	cout << '\n';

	vector D(2, vector<ll>(N, 0));
	for ( i = 0 ; i < N ; i ++ )
	{
		D[0][i] = A[i] + max( i>=2 ? D[0][i-2] : 0, i>=1 ? D[1][i-1]: 0 );
		D[1][i] = i > 0 ? max(D[0][i-1], D[1][i-1]) : 0;
	}
	cout << max(D[0][N-1], D[1][N-1]) << '\n';
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
