#include <bits/stdc++.h>
using namespace std;
void init(){
}
void process(int Case) {
    int N, M ;
    int i, j, a, b, S, E ;
    string s;

    cin >> N >> M ;
    vector< vector<pair<string, int> > > C(N);
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> a >> b >> s ;
        C[a-1].emplace_back(s, b-1);
    }
    cin >> S >> E; S--; E--;
    for ( i = 0 ; i < N ; i ++ ) {
        std::sort(C[i].begin(), C[i].end(), [](pair<string,int> &a, pair<string,int> &b){
            if ( a.first.size() != b.first.size() )
                return a.first.size() < b.first.size();
            return a.first < b.first;
        });
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
