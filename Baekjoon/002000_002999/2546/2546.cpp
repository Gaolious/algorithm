#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, M, i;
    ll CS, ES, n;

    cin >> N >> M ;
    vector<ll> C(N);
    CS = ES = 0;
    for(auto &n: C) cin >> n, CS += n;
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> n, ES += n;
    }
    int ans = 0 ;
    for(auto n: C) {
        if ( n * (N-1) >= (CS-n) ) continue;
        if ( n * (M+1) <= (ES+n) ) continue;
        ans ++;
    }
    cout << ans << '\n';
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
