#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, M, i, j, maxJ, maxB;
    cin >> N >> M ;
    vector<int> Jun(N), Bee(M);
    maxJ = maxB = -1;
    for (auto &n: Jun) {
        cin >> n;
        maxJ = max(maxJ, n);
    }
    for (auto &n: Bee) {
        cin >> n;
        maxB = max(maxB, n);
    }
    if ( maxJ >= maxB) cout << "S\n";
    else cout << "B\n";
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
