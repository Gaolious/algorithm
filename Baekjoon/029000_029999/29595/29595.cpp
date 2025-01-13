#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll D[2001]={0,1, 1};
void init(){}

void process(int Case) {
    ll N, M ;
    int i ;
    cin >> N >> M ;
    for ( i = 3 ; i <= N ; i ++ )
        D[i] = (D[i-1]*(i-1) % M + D[i-2]*(i-2) % M)%M;
    cout << D[N] << '\n';
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
