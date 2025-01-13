#include <bits/stdc++.h>
using namespace std;

void init() {}

vector<int> A;
void process(int Case) {
    int N;
    cin >> N;
    A.resize(N);
    for (auto &n: A) {
        string s ;
        cin >> s ;
        n = s.size();
    }
    int ans = 1;
    for ( int i = 0 ; i + 1 < N ; i ++ )
        ans = max(ans, min(A[i], A[i+1]));
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
