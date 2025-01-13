#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process(int Case) {
    char a, b, C;
    cin >> a >> C >> b ;
    string s = "RQZN";
    if ( a == 'N' && b == 'N' && C == '-' )
    {
        cout << "Z";
        return;
    }
    for (auto c: s) {
        if ( a == c || b == c ) {
            cout << c << '\n';
            return;
        }
    }
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
