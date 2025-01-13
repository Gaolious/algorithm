#include <bits/stdc++.h>
using namespace std;

void init(){}
bool isWin(int a, int b) {
    if ( a != b ) {
        if (a == 2) return b != 0;
        if (a == 5) return b != 2;
        if (a == 0) return b != 5;
    }
    return false;
}
void process(int Case) {
    int a, b;
    cin >> a >> b;
    if (isWin(a, b) ) cout << ">" ;
    else if (isWin(b, a) ) cout << "<" ;
    else cout << "=";
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
