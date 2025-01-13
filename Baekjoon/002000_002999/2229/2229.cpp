#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000 ;

int D[MaxN][MaxN];
int Min[MaxN][MaxN];
int Max[MaxN][MaxN];
int A[MaxN];
int N;


int F(int s, int e)
{
	if ( s >= e ) return 0;
	auto &ret = D[s][e] ;
	if ( ret < 0 )
	{
		ret = 0 ;
		for ( int i = e ; i >= s ; i -- )
			ret = max( ret, F(s, i-1) + Max[i][e] - Min[i][e]);
	}
	return ret;
}
void process(int Case) {
	int i, j;

	memset(D,-1,sizeof(D));
	memset(Min,-1,sizeof(Min));
	memset(Max,-1,sizeof(Max));

	cin >> N;
	for ( i = 0 ; i < N ; i ++ )
		cin >> A[i];

	for ( i = 0 ; i < N ; i ++ )
		for ( j = i ; j < N ; j ++ )
		{
			if ( j == i ) Min[i][j] = Max[i][j] = A[j];
			else
			{
				Min[i][j] = min(Min[i][j-1], A[j]);
				Max[i][j] = max(Max[i][j-1], A[j]);
			}
		}
	cout << F(0, N-1) << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
