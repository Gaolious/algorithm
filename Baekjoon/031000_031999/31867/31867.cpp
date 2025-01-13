#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N;
    int C[2]={0,};
    string s;
    cin >> N >> s ;
    for (auto c: s ) C[(c - '0') % 2 ]++;
    if (C[0] > C[1] ) cout << 0;
    else if (C[0] < C[1] ) cout << 1;
    else cout << -1;
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
