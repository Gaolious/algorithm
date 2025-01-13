#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int a1, a2, b1,  b2;
    char e;
    cin >> a1 >> e >> b1 >> b2 >> e >> a2 ;
    cout << ( b1 >= a2 && a1 >= b2 ? "YES" : "NO") << '\n';
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
