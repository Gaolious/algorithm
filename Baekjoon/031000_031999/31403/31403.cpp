#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	string A, B, C;
	cin >> A >> B >> C ;
	cout << stoi(A)+stoi(B)-stoi(C) << '\n';
	cout << stoi(A+B)-stoi(C)<<'\n';
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
