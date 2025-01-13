#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
ll D[46];

char F(ll N, ll kth) {

    if ( N == 0 ) return 'a';
    if ( N == 1 ) return 'b';
    if ( kth <= D[N-2] )
        return F(N-2, kth);
    else
        return F(N-1, kth - D[N-2]);

}
void process(int Case) {
    int i ;
    D[0] = D[1] = 1;
    for(i=2 ; i <= 45 ; i ++ )
        D[i] = D[i-2] + D[i-1];

    int N ;
    cin >> N ;
    while ( N -- ) {
        ll n, kth;
        cin >> n >> kth ;
        cout << F(n, kth) << '\n';
    }

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
