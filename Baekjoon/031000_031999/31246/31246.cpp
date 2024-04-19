#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    int N, K, i;

    fastio;

    cin >> N >> K ;
    vector<int> A(N), B(N);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i] >> B[i];
        B[i] -= A[i];
    }
    sort(B.begin(), B.end());
    cout << max(0, B[K-1]) << '\n';

    return 0;
}


