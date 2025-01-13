#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void process(int Case) {
	ll R, G, B;
	cin >> R >> G >> B;
	cout << R*3+G*4+B*5;
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
