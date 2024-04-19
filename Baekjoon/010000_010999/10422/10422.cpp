#include <fcntl.h>
#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
ll D[5001];
int N;
const ll MOD = 1000000007ll;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int T, L;
    int i, j;

    D[0] = 1;
    for (i = 2; i <= 5000; i += 2) {
        for (j = 2; j <= i; j += 2) {
            D[i] += D[j - 2] * D[i - j];
            D[i] %= MOD;
        }
    }

    cin >> T ;
    while ( T -- ) {
        cin >> L ;
        cout << D[L] << '\n';
    }
    return 0;
}


