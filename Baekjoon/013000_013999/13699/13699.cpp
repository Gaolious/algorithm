#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll A[35+1];
void init(){
}
ll F(int n)
{
	if ( n == 0 ) return 1;
	auto &ret = A[n];
	if ( ret == 0 )
	{
		int l, r ;
		for ( l = 0, r = n-1 ; l < r ; l ++, r -- )
			ret += F(l) * F(r) * 2;
		if ( l == r ) ret += F(l) * F(r);
	}
	return ret;
}
void process(int Case) {
	int i, n;
	cin >> n ;
	cout << F(n) << '\n';
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
