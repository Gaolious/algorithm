#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int a, b, N;
    int ans = 10000 ;
    cin >> a >> b >> N ;
    vector<int> A(N);
    for (auto &n: A) cin >> n;
    ans = min(ans, abs(a-b));
    for (auto n: A) ans = min(ans, 1 + abs(n-b));
    cout << ans;
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
