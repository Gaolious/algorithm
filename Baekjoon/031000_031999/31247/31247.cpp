#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll F(ll N, ll K) {
    K = min(60ll, K);
    return N >> K;
}
void divisors(ll N, vector<ll> &odd, vector<ll> &even) {

    odd.clear();
    even.clear();
    for ( ll i = 1 ; i * i <= N ; i ++ ) {
        if ( N % i != 0 ) continue;

        ( ( i % 2 == 0 ) ? even : odd ).push_back(i);
        if ( i * i == N ) break;
        ( ( (N/i) % 2 == 0 ) ? even : odd ).push_back((N/i));
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
}
int main()
{
    fastio;
    int T;
    ll N, K;
    cin >> T;

    vector<ll> odd, even;
    // for ( N = 1 ; N <=1000 ; N ++ ) {
    //     divisors(N, odd, even);
    //     if ( odd.size() * 7 != even.size() ) continue;;
    //     cout << "N = " << N << ", Odd : " ;
    //     for (auto n: odd) cout << n << ' ';
    //     cout << ", Even : ";
    //     for (auto n: even) cout << n << ' ';
    //     cout << '\n';
    // }
    while ( T-- ) {
        cin >> N >> K ;
        cout << F(N, K) - F(N, K+1) << '\n';
    }


    return 0;
}


