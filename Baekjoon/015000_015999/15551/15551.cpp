#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	int N;
	cin >> N ;
	string A(N, 'a');
	string B = "bB" + string(N-2, 'a');

	cout << A << '\n' << B << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
