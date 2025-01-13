#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;

void process(int Case) {
    int N, i ;
    cin >> N ;

    vector<int> A(N);
    vector<pii> P[2];
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i];
        if ( i > 0 )
            P[i%2].emplace_back(min(A[i-1], A[i]), max(A[i-1], A[i]));
    }
    for ( i = 0 ; i < 2 ; i ++ )
    {
        std::sort(P[i].begin(), P[i].end());
        stack<int> End;
        for ( auto [s, e]: P[i]) {
            while (!End.empty() && End.top() <= s ) End.pop();
            if (!End.empty() && End.top() < e ) {
                cout << "NO\n";
                return;
            }
            End.push(e);
        }
    }
    cout << "YES\n";
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
