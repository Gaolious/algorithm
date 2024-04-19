#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

void process() {
    int N, K;
    int i, j ;
    int ans ;

    cin >> N >> K ;
    vector<int> A(N);
    for (auto &n: A) cin >> n;
    queue<int> Q[2];

    for ( i = 0; Q[0].size() + Q[1].size() < K && i < N ; i ++ )
        Q[ A[i] - 1 ].push(i);
    ans = 0 ;
    for ( ans = 0 ; !Q[0].empty() || !Q[1].empty() || i < N; ans ++) {
        for ( ; Q[0].size() + Q[1].size() < K && i < N ; i ++ )
            Q[ A[i] - 1 ].push(i);
#ifdef AJAVA_DEBUG
        cout << "Q 1 : " << Q[0].size() << '\n' ;
        cout << "Q 2 : " << Q[1].size() << '\n' ;
#endif

        for (auto &q: Q) {
            if ( !q.empty() ) {
#ifdef AJAVA_DEBUG
                cout << "Pop : " << q.front() << "-th element : " << A[ q.front() ] << '\n';
#endif
                q.pop();
            }
        }
    }

    ans += Q[0].size() + Q[1].size();
    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


