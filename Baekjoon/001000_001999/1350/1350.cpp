#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    ll N, cs, ans;
    cin >> N;
    vector<ll> fs(N);
    for(auto &n: fs) cin >> n ;
    cin >> cs;

    ans = 0 ;
    for (auto n: fs ) {
        ans += n / cs ;
        ans += n % cs == 0 ? 0 : 1;
    }
    cout << cs * ans;
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
