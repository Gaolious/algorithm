#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a: A) cin >> a;

    if ( next_permutation(A.begin(), A.end()) ) {
        for (auto a : A)
            cout << a << ' ';
    }
    else
        cout << "-1";
    return 0;
}


