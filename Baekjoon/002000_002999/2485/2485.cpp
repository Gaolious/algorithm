#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int main()
{
    fastio;
    int N, g ;
    cin >> N ;
    vector<int> A(N);
    for (auto &n : A) cin >> n ;

    g = A[1] - A[0];
    for ( int i = 2 ; i < N ; i ++ )
        g = gcd(g, A[i] - A[i-1]);

    cout << (A.back() - A.front()) / g - A.size() + 1 << '\n';

    return 0;
}


