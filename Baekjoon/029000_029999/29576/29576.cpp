#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init() {}
void process(int Case) {
    int N, K;
    // next = 1 + (K-1)*t;
    cin >> N >> K ;
    if ( K == 1 )
        cout << (N == 1 ? 0 : -1) << '\n';
    else if ( (N-1)%(K-1) == 0 )
        cout << (N-1)/(K-1) << '\n';
    else
        cout << -1 << '\n';
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
