#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void process(int Case) {
    ll a, b;
    cin >> a >> b;
	cout << a*1000 + b*10000;
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
