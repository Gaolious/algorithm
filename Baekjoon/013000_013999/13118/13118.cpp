#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int x;
    vector<int> A(4);
    for (auto &n: A) cin >> n ;
    cin >> x;

    for ( int i = 0 ; i < 4 ; i ++ ) {
        if ( A[i] == x ) {
            cout << i+1 ;
            return;
        }
    }
    cout << 0;
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
