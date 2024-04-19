#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, i, n ;
    cin >> N ;

    vector<int> F(1000001);
    vector<int> A(N);
    vector<int> NGF(N, -1);
    stack<int> S;

    for (auto &n: A) {
        cin >> n;
        F[n]++;
    }
    // for (auto n: A) cout << n << ' '; cout << '\n';
    // for (auto n: A) cout << F[n] << ' '; cout << '\n';

    for (i = N-1 ; i >= 0 ; i -- ) {
        n = A[i];
        while( !S.empty() && F[n] >= F[S.top()] ) S.pop();
        if ( !S.empty() ) NGF[ i ] = S.top();
        S.push(n);
    }
    for (auto n : NGF) cout << n << ' ';
    return 0;
}


