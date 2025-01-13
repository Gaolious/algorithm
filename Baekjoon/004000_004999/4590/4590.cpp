#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, P, S, order;
    int i;

    while ( cin >> N >> P >> S ) {
        vector<pair<int, int>> DS(N + 1);
        for (i = 1; i <= N; i++) {
            cin >> DS[i].first;
            DS[i].second = 0;
        }

        vector<pair<int, string>> IS(P + 1);
        for (i = 1; i <= P; i++)
            cin >> IS[i].first >> IS[i].second;

        int ans = 0, usage=0;
        for (i = 0; i < S; i++) {
            cin >> order ;
            auto &info = IS[ abs(order) ];
            if ( order > 0 ) {
                usage += info.first ;
                for ( auto c: info.second )
                    if (DS[c - 'A' + 1 ].second++ == 0 )
                        usage += DS[c - 'A' + 1 ].first;
            }
            else {
                usage -= info.first ;
                for ( auto c: info.second )
                    if (--DS[c - 'A' + 1 ].second == 0 )
                        usage -= DS[c - 'A' + 1 ].first;
            }
            ans = max(ans, usage);
        }
        cout << ans << '\n';
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
