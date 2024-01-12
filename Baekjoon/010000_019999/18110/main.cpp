#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int n;
    int i;
    int S;
    int k ;

    cin >> n ;
    vector<int> A(n);

    S = 0;
    for (auto &a: A) {
        cin >> a;
        S += a;
    }
    sort(A.begin(), A.end());
    k = (int)( (double)n * 0.15L + 0.5L);
    for ( i = 0 ; i < k ; i ++ )
        S -= A[i] + A[n-1-i];

    if ( n - k * 2 > 0 ) {
        cout << (int)( (double)S / (n-k*2.0) + 0.5) << '\n';
    }
    else {
        cout << "0\n";
    }
    return 0;
}


