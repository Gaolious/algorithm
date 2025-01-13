#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    vector<ll> F(45+1);
    F[0] = F[1] = 1;
    for ( int i = 2 ; i <= 45 ; i ++ )
        F[i] = F[i-1] + F[i-2];
    int n, a;
    cin >> n;
    while ( n-- ) {
        cin >> a ;
        cout << F[a] <<'\n';
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
