#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 100000;
int N, K;
string S[2];
bitset<200000> Visited;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int row;

    cin >> N >> K ;
    cin >> S[0] >> S[1];

    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    Visited[0] = 1;

    while ( !Q.empty() ) {
        auto [step, curr] = Q.front();
        Q.pop();
        row = curr / MaxN;
        curr %= MaxN;

        for ( auto [r, d]: { make_pair(row, -1), make_pair(row, 1), make_pair(1-row, K) }) {
            if ( curr + d <= step ) continue;
            if ( curr + d >= N ) {
                cout << "1\n";
                return 0;
            }
            if ( S[r][curr + d] == '0' ) continue;
            int t = r * MaxN + curr + d ;
            if ( Visited[t] ) continue;
            Visited[t] = 1;
            Q.emplace(step+1, t );
        }
    }
    cout << "0\n";
    return 0;
}


