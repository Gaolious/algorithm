#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    ll N, d, k ;
    while ( cin >> N ) {
        for (d = 10; N > d; d *= 10) {
            k = ((N / (d / 10)) % 10 >= 5) ? 1 : 0;
            N = ((N / d) + k) * d;
        }
        cout << N <<'\n';
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
