#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
    int a, b, c;
	cin >> a >> b >> c;
	cout << (a+b+c<=21);
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
