#include <bits/stdc++.h>
using namespace std;

void process() {
	int N, i, g;
	cin >> N ;
	vector<int> A(N), B;
	for (auto &n: A) cin >> n;
	sort(A.begin(), A.end());
	for ( i = 1 ; i < N ; i ++ )
		if ( A[i] - A[i-1] != 0 )
			B.push_back(A[i] - A[i-1]);
	for (g = B[0], i = 1 ; i < B.size() ; i ++ )
		g = gcd(g, B[i]);
	cout << g << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	process();
    return 0;
}
