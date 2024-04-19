#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MaxN = 500000;
int AddTime(int t) {
    return ( t ) * ( t + 1 ) / 2 ;
}
bool Find(int N, int K ) {
    int i, k = K;

    queue<pair<int, int>> Q;

    if ( N == K ) {
        cout << "0\n";
        return true;
    }

    vector C(2, vector(MaxN + 1, -1));
    Q.emplace(N, 0);
    C[0][N] = 0;

    while ( !Q.empty() ) {
        auto [curr, t] = Q.front(); Q.pop();
        t++;
        for (auto nxt : {curr-1, curr+1, curr*2} ) {
            if ( nxt < 0 || nxt > MaxN ) continue;
            if ( C[t%2][nxt] < 0 ) {
                C[t%2][nxt] = t;
                Q.emplace(nxt, t);
            }
        }
    }
    int best = -1;

    for ( i = 0, K = k ; K <= MaxN ; K += ++i ) {
        if ( C[i%2][ K ] >= 0 && C[i%2][ K ] <= i ) {
            if ( best < 0 || best > i ) best = i;
        }
    }
    if ( best >= 0 ) {
        cout << best << '\n';
        return true;
    }
    return false;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, K, i ;
    cin >> N >> K ;
    if ( !Find(N, K) ) {
        cout << "-1\n";
    }
    return 0;
}


