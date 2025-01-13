#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N;
    int i, j;
    string s;
    cin >> N >> s ;
    for ( j = 0 ; j < N ; j ++ ) {
        for ( i = 0 ; i < s.size() / N ; i ++ ) {
            if ( (i+1)%2 )
                cout << s[ i * N + j ];
            else
                cout << s[ (i+1) * N - j - 1 ] ;
        }
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
