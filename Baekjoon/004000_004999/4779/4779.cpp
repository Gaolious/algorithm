#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    vector<string> A = {"-"};
    for (int i = 1 ; i <= 12 ; i ++ )
        A.push_back( A.back() + string(A.back().size(), ' ') + A.back());
    int n;
    while (cin >> n ) {
        cout << A[n] << '\n';
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
