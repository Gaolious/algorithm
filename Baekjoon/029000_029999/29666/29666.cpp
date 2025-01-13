#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void init(){
}
void process(int Case) {
    int i;
    string s;
    bool v, h;
    vector<pii> A(3);
    cin >> s ;
    for ( i = 0 ; i < 3 ; i ++ ) {
        if ( s[i] == '0' ) A[i] = { 3, 1 };
        else A[i] = {(s[i]-'1')/3, (s[i]-'1')%3};
    }
    std::sort(A.begin(), A.end());
    v = h = true;
    for ( i = 1 ; i < 3 ; i ++ ) {
        v = v && ( A[i].first == A[i-1].first && A[i].second == 1 + A[i-1].second );
        h = h && ( A[i].second == A[i-1].second && A[i].first == 1 + A[i-1].first );
    }
    if ( h || v )
        cout << "Unlocked\n";
    else
        cout << "Locked\n";
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
