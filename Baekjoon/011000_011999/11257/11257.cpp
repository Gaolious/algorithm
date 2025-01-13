#include <bits/stdc++.h>
using namespace std;
void init(){}
void process(int Case) {
    string s;
    int a, b, c;
    cin >> s >> a >> b >> c ;
    cout << s << ' ' << a+b+c << ' ';
    if ( a < 11 || b < 8 || c < 12 || a + b + c < 55 ) cout << "FAIL\n";
    else cout << "PASS\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
