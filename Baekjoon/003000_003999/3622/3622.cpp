#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}

void process(int Case) {
    ll A, B, a, b, P;
    cin >> A >> a >> B >> b >> P ;
    if ( ( A <= P && B <= P ) && ( P >= A+B || a >= B || b >= A ) )
        cout << "Yes\n";
    else
        cout << "No\n";
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
