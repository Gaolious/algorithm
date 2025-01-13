#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){
}
void process(int Case) {
    int N;
    char prev = 0;
    vector<ll> A;
    string S;
    cin >> N >> S ;

    for (auto c: S) {
        if ( c == '2' ) {
            if (prev != c) A.emplace_back(1);
            else A.back()++;
        }
        prev = c;
    }
    ll ans = 0 ;
    for (auto n: A)
        ans += n * (n+1) / 2 * (n+2) / 3;
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
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
