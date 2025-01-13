#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    vector<string> A = {
            "`1234567890-=",
            "\tQWERTYUIOP[]\\",
            "ASDFGHJKL;'\n",
            "ZXCVBNM,./",
    };
    pii Map[256];
    int i, j;
    for ( i = 0 ; i < A.size() ; i ++ ) {
        for ( j = 0 ; j < A[i].size() ; j ++ ) {
            Map[ toupper(A[i][j]) ] = { i, j };
            Map[tolower(A[i][j]) ] = { i, j };
        }
    }
    string s ;
    while ( getline(cin, s) && !s.empty() ) {
        for (auto &c: s) {
            if (c == ' ') continue;
            else {
                auto pos = Map[c];
                c = A[pos.first][pos.second - 1];
            }
        }
        cout << s << '\n';
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
