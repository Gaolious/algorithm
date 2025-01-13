#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
vector<ll> D;
void init(){
    ll i, j;
    for ( i = 1 ; i <= 11111111111111111ll ; i = i*10 + 1 )
        for ( j = 1; j <= 9 ; j ++ )
            D.push_back(i*j);
}
void process(int Case) {
    int K;
    vector<ll> ans;
    ll N;
    cin >> K >> N ;
    int i = D.size();
    while ( i-- > 0 ) {
        if (N >= D[i]) {
            N -= D[i];
            ans.push_back(D[i]);
        }
    }
    cout << ans.size() << '\n';
    for (auto n: ans ) cout << n << ' ';
    cout << '\n';
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
