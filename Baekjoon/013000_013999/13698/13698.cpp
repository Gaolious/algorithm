#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
	int A[4] = {1, 2, 3, 4};
	string s ;
	cin >> s ;
	for (auto c: s)
	{
		if ( c <= 'C' ) swap(A[0], A[c - 'A' + 1]);
		else if ( c <= 'E' ) swap(A[1], A[c - 'D' + 2]);
		else swap(A[2], A[3]);
	}
	for ( auto n : {1, 4})
		for ( int i = 0 ; i < 4 ; i ++ )
			if ( A[i] == n ) cout << i + 1 << '\n';;
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
