#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    ll X, K;
    ll tax=0, prev = 0;
    int i;
    cin >> X >> K ;

    vector<ll> U(K), P(K+1);
    for (auto &n: U) cin >> n ;
    U.push_back(X+1);
    for (auto &n: P) cin >> n ;

    for ( prev =0, tax=0, i = 0 ; i <= K ; i ++ ) {
        tax += max(0ll, min(U[i] - prev, X - prev)) * P[i] ;
        prev = U[i];
    }
    cout << setprecision(2) << fixed << tax / 100.0 << '\n';
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
