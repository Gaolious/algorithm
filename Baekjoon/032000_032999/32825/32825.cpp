#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

unordered_map<int, vector<array<int, 3>>> A3;
unordered_map<int, vector<array<int, 2>>> A2;
void init(){
	int i, j, k;
	for ( i = 1 ; i <= 13 ; i ++ )
		for ( j = i+1 ; j <= 13 ; j ++ )
		{
			A2[i+j].push_back({i,j});
			for ( k = j + 1 ; k <= 13 ; k ++ )
				A3[i+j+k].push_back({i,j,k});
		}
}
int ColSum[4];
int RowSum[4];
bool Used[14];
int ans = 0;

int getMinSum(int cnt)
{
	int ret = 0;
	for ( int i = 1 ; i <= 13 && cnt ; i ++ )
	{
		if ( Used[i] ) continue;
		cnt --;
		ret += i;
	}
	return ret;
}
void col2()
{
	int minSum = getMinSum(2) ;

	if ( RowSum[0] < minSum || RowSum[1] < minSum || RowSum[2] < minSum )
		return;

	for (auto &[a, b, c]: A3[ ColSum[ 1 ] ] )
	{
		if ( Used[ a ] || Used[ b ] || Used[ c ] ) continue;
		Used[ a ] = Used[ b ] = Used[c] = true;
		int V[] = {a, b, c};
		do {

			RowSum[0] -= V[0]; RowSum[1] -= V[1]; RowSum[2] -= V[2];
			if ( RowSum[0] > 0 && RowSum[1] > 0 && RowSum[2] > 0 )
			{
				if ( RowSum[0] != RowSum[1] && RowSum[0] != RowSum[2] && RowSum[1] != RowSum[2] )
				{
					if ( !Used[RowSum[0] ] && !Used[RowSum[1]] && !Used[RowSum[2]] )
						ans ++;
				}
			}

			RowSum[0] += V[0]; RowSum[1] += V[1]; RowSum[2] += V[2];
		} while (std::next_permutation(V, V + 3));

		Used[ a ] = Used[ b ] = Used[c] = false;
	}
}
void col3()
{
	int minSum = getMinSum(2) ;
	if ( ColSum[0] < minSum || ColSum[1] < minSum ) return;

	for (auto [a, b, c]: A3[ ColSum[ 2 ] ] )
	{
		if ( Used[ a ] || Used[ b ] || Used[ c ] ) continue;
		Used[ a ] = Used[ b ] = Used[c] = true;

		int V[] = {a, b, c};

		do {
			RowSum[0] -= V[0]; RowSum[1] -= V[1]; RowSum[2] -= V[2];
			col2();
			RowSum[0] += V[0]; RowSum[1] += V[1]; RowSum[2] += V[2];
		} while (std::next_permutation(V, V + 3));

		Used[ a ] = Used[ b ] = Used[c] = false;
	}
}
void row4()
{
	int minSum = getMinSum(3) ;
	if ( RowSum[0] < minSum || RowSum[1] < minSum ) return;

	for (auto [a, b]: A2[ RowSum[ 3 ] ] )
	{
		if ( Used[ a ] || Used[ b ] ) continue;

		Used[ a ] = Used[ b ] = true;
		int V[] = {a, b};
		do {
			ColSum[0] -= V[0]; ColSum[1] -= V[1];
			col3();
			ColSum[0] += V[0]; ColSum[1] += V[1];
		} while (std::next_permutation(V, V + 2));

		Used[ a ] = Used[ b ] = false;
	}
}
void col4()
{
	for (auto [a, b]: A2[ ColSum[ 3 ] ] )
	{
		Used[ a ] = Used[ b ] = true;

		int V[] = {a, b};
		do {
			RowSum[0] -= V[0]; RowSum[1] -= V[1];
			row4();
			RowSum[0] += V[0]; RowSum[1] += V[1];
		} while (std::next_permutation(V, V + 2));

		Used[ a ] = Used[ b ] = false;
	}
}
void process(int Case) {
	for (auto &n: ColSum) cin >> n;
	for (auto &n: RowSum) cin >> n;
	col4();
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
