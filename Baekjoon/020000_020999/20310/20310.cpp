#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int i, cnt[2]={0,}, C[2]={0,};
    string s ;
    cin >> s;
    for (auto c: s) C[ c-'0' ]++;
    for (auto &c: s ) {
        cnt[ c - '0' ] ++;
        if ( c == '0' ) {
            if ( cnt[0] * 2 > C[0] ) c = '.';
        }
        else if ( c == '1' ) {
            if ( cnt[1] * 2 <= C[1] ) c = '.';
        }
    }
    for (auto c: s) {
        if ( c != '.' ) cout << c;
    }
    cout << '\n';
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
