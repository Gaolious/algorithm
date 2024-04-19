#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    int i;
    ll ret, ans;
    int N;
    fastio;
    cin >> N ;
    vector<ll> A(N);
    for ( auto &a : A ) cin >> a;

    ans = ret = A[0];
    for ( i = 1 ; i < N ; i ++ ) {
        ans = ( ans < 0 ) ? A[i] : ans + A[i];
        ret = max(ret, ans);
    }
    cout << ret << '\n';
    return 0;
}


