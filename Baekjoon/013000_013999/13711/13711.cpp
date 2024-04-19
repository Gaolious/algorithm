#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int i, n;
    int N;
    cin >> N;

    vector<int> A(N+1), B(N), LIS;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n ;
        A[n] = i ;
    }
    for ( int i = 0 ; i < N ; i ++ ) {
        cin >> B[i] ;
    }

    for (auto b: B) {
        n = A[b];
        if ( LIS.empty() || LIS.back() < n )
            LIS.push_back(n);
        else {
            *lower_bound(LIS.begin(), LIS.end(), n) = n;
        }
    }
    cout << LIS.size() << '\n';
    return 0;
}


