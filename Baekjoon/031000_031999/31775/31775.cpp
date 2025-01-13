#include <bits/stdc++.h>
using namespace std;

void init(){
}
char A[256]={0,};
void process(int Case) {
    string s;
    for ( int i = 0 ; i < 3 ; i ++ ) {
        cin >> s ;
        A[s[0]]++;
    }
    if ( A['k'] && A['l'] && A['p'] )
        cout << "GLOBAL\n";
    else
        cout << "PONIX\n";
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
