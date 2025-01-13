#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int i, j;
    vector<pair<char, string>> A= {
        {'A', "000000"},
        {'B', "001111"},
        {'C', "010011"},
        {'D', "011100"},
        {'E', "100110"},
        {'F', "101001"},
        {'G', "110101"},
        {'H', "111010"},
    };
    unordered_map<string, char> M;
    for (auto &[c,s]: A) {
        M[s] = c;
        for ( i = 0 ; i < 6 ; i ++ ) {
            s[i] = ('1' - s[i]) + '0';
            M[s] = c;
            s[i] = ('1' - s[i]) + '0';
        }
    }
    int N;
    char c;
    string ans;
    cin >> N ;
    for ( i = 1 ; i <= N ; i ++ ) {
        string s;
        for (j = 0 ; j < 6 ;j ++ ) {
            cin >> c ;
            s.push_back(c);
        }
        if ( M.find(s) == M.end() ) {
            cout << i << '\n';
            return;
        }
        ans.push_back(M[s]);
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
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
