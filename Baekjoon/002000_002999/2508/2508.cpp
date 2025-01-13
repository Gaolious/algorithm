#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int Y, X, i, j;
    cin >> Y >> X ;
    vector<string> A(Y) ;
    for (auto &s: A) cin >> s;

    int ans =0 ;
    for (i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j< X ; j ++ ) {
            if ( A[i][j] == '>' && j < X-2 && A[i][j+1] == 'o' && A[i][j+2] == '<' )
                ans++;
            else if ( A[i][j] == 'v' && i < Y-2 && A[i+1][j] == 'o' && A[i+2][j] == '^' )
                ans++;
        }
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
