#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int S[] = {
        1600,894,1327,1311,1004,
        1178,1357,837,1055,556,773,689,800,264
    };
    int A[] = {
            12,11,11, 10,9,
            9,9,8,7,6,6,5,5,4
    };
    int N;
    cin >> N;
    cout << A[N-1] << ' ' << S[N-1];
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


