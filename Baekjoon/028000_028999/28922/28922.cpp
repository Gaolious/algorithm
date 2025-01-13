#include <bits/stdc++.h>
using namespace std;
void init(){
}
void process(int Case) {
    int N, K, n;
    cin >> N >> K ;
    while( true ) {
        cout << "Move" << endl;
        cin >> n ;
        if ( n*2 == K ) break;
    }
    cout << "Finish\n";
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
