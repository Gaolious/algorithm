#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

void process() {
    int N, i, j, total, win ;
    cin >> N ;
    vector<int> A(N);
    for ( auto &n: A) cin >> n ;

    for (total = 1, i = N ; i < 4 ; i ++ )
        total *= 6;

    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = i + 1 ; j < N ; j ++ ) {
            if ( A[ i ] == A[j] ) {
                cout << "0 " << total << "\n";
                return ;
            }
        }
    }

    for ( win=1, i = N ; i < 4 ; i ++ )
        win *= 6-i;
    cout << win << ' ' << total - win << '\n';
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


