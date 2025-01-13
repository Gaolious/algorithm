#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	int a, w, v ;
	cin >> a >> w >> v ;
	cout << ( a*v <= w ) << '\n';
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
