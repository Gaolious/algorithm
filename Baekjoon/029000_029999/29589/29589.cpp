#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, M, K;
    int h, m;
    char c;

    cin >> N >> M >> K ;
    vector<int> Train(N), Customer(M);
    for (auto &t : Train ) {
        cin >> h >> c >> m ;
        t = h * 60 + m ;
    }
    for (auto &t : Customer ) {
        cin >> h >> c >> m ;
        t = h * 60 + m ;
    }
    vector<int> ans(M, -1);
    int i, j, cnt=0 ;
    for (j=0, i = 0 ; i < M ; i ++ ) {
        while ( j < N && ( cnt >= K || Customer[i] > Train[j]) ) { j ++, cnt=0; }
        if ( j < N ) {
            ans[i] = j+1;
            cnt++;
        }
    }
    for (auto n: ans ) cout << n << '\n';
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
