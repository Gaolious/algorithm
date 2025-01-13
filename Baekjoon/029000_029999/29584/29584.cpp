#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int K, N ;
    int S=0, SUM;
    int M=0;
    string s;
    cin >> K >> N >> s ;
    for (auto c: s ) {
        int t = c < 'A' ? c - '0' : c - 'A' + 10;
        S += t;
        M = M * K + t ;
    }

    int k;
    while ( ++M <= 100000 ) {
        SUM = 0 ;
        for ( k = M ; k > 0 ; k /= K ) SUM += k%K;

        if ( SUM == S) {
            string ans  ;
            for ( k = M ; k > 0 ; k /= K )
                ans.push_back( k%K < 10 ? '0' + k%K : 'A' + k%K-10 );
            if ( ans.size() == s.size() ) {
                std::reverse(ans.begin(), ans.end());
                cout << ans << '\n';
                return;
            }
            else break;
        }
    }
    cout << "Impossible\n";
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
