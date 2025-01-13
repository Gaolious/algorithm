#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){}
char A[2000 + 1]={0,};
void process(int Case) {
	int L, R, X;
	int i ;
	cin >> L >> R >> X;
	for ( i = L ; i <= R ; i ++ )
		A[ i | X ] = 1;
	for ( i = 0 ; i < 2000 ; i ++ )
	{
		if ( A[i] == 0 )
		{
			cout << i << '\n';
			return;
		}
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
