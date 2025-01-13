#include <bits/stdc++.h>
using namespace std;
void init(){}
void process(int Case) {
    int N, P, Q, i;
    cin >> N >> P >> Q;
    vector<int> A(N), B(N), ans(N);
    for( auto &n: A) cin >> n;
    for( auto &n: B) cin >> n;
    // A[i] + P*x == B[i] + Q*x
    for ( i = 0 ; i < N ; i ++ ) {
        if (A[i] == B[i])
            ans[i] = 0;
        else {
            if ( P == Q ) {
                cout << "NO\n";
                return;
            }
            else {
                int x = (A[i] - B[i]) / (Q-P);
                if ( x >= 0 && x < 10000 && A[i] + P*x == B[i] + Q*x) ans[i] = x;
                else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    for (auto n: ans)
        cout << n << ' ';
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
