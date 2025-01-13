#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){}
void process(int Case) {
    ll a, b, c;
    cin >> a >> b >> c ;
    cout << a+b - (a+b>=c*2 ? c*2 : 0);
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
