#include <bits/stdc++.h>
using namespace std;

void process(int Case) {
	int N, n, A=0, B=0;
	cin >> N ;
	while (N--)
	{
		cin >> n;
		(n % 2 ? A: B)++;
	}
	if ( A < B) swap(A, B);
	cout << ( A > B && A % 2 == 1 ? "amsminn\n" : "heeda0528\n");
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
