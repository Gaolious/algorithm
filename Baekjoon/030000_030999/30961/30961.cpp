#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    int N ;
    cin >> N ;

    vector<ll> A(N);
    for(auto &a: A) cin >> a ;

    ll ret = 0;
    sort(A.begin(), A.end());
    for ( auto a: A) ret ^= a*a;
    for ( int i = 0 ; i < N-1 ; i ++ ) ret ^= A[i]*A[i+1];
    cout << ret;

    return 0;
}


