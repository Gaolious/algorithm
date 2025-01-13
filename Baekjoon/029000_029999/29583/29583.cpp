#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){}
void process(int Case) {
    int N;
    int i;

    cin >> N ;
    vector<int> Page(N);
    vector<int> Limit(N-1);
    vector<int> perm(N);
    for (auto &n: Page ) cin >> n ;
    for (auto &n: Limit ) cin >> n ;
    for ( i = 0 ; i < N ; i ++) perm[ i ] = i ;

    int ans = 0 ;
    do {
        bool f = true;

        for ( i = 0 ; i < N-1 ; i ++ ) {
            if (Page[perm[i]] + Page[perm[i + 1]] > Limit[i]) {
                f = false;
                break;
            }
        }
        if (f) ans ++;
    } while (std::next_permutation(perm.begin(), perm.end()));
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
