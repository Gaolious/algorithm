#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, M ;
    string s;
    vector<string> A;
    unordered_map<string, int> C;

    cin >> N >> M ;
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        if ( s.size() < M ) continue;
        if ( C[s]++ == 0 )
            A.push_back(s);
    }
    std::sort(A.begin(), A.end(), [&C](string &a, string &b){
        int c1, c2;
        c1 = C[a];
        c2 = C[b];
        if ( c1 != c2 ) return c1 > c2;
        if ( a.size() != b.size() ) return a.size() > b.size() ;
        return a < b;
    });
    for (auto &s: A)
        cout << s << '\n';
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
