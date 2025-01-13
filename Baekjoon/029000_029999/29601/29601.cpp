#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    char C;
    int N;
    cin >> C >> N ;

    if (1<= N && N <= 36 )
        cout << (N-1)/4 + 1 << " 1 " << (N%2 == 0 ? 1 : -1) << '\n';
    else if ( C == 'R' && N<=54 )
        cout << (54-N)/2 + 1  << " 0 " << (N%2 == 0 ? 1 : -1) << '\n';
    else
        cout << "-1\n";
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
