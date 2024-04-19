#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;


void process() {
    int N, S;
    int i, j, idx;

    cin >> N;
    vector<int> A(N);
    for (auto &n: A) cin >> n ;
    cin >> S ;

    for ( i = 0 ; i < N ; i ++ ) {
        idx = i;
        for ( j = i+1 ; j < N && j-i <= S ; j ++ ) {
            if ( A[idx] < A[j] ) idx = j;
        }
        if ( idx != i ) {
            for ( j = idx ; j > i ; j--, S-- )
                swap(A[j], A[j-1]);
        }
    }
    for ( i = 0 ; i < N ; i ++ ) {
        if ( i > 0 ) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
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


