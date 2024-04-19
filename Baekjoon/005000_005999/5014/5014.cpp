#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define MaxN (1000000)

int D[MaxN+1];

bool bfs(int minFloor, int maxFloor, int s, int e, int u, int d) {
    queue<int> Q;
    Q.push(s);
    D[s] = 0;

    while ( !Q.empty() ) {
        auto curr = Q.front();

        if ( D[e] > -1 && D[curr] > D[e] )
            break;
        Q.pop();

        for (auto a : {u, -d}) {
            auto t = curr + a ;
            if ( t < minFloor || t > maxFloor ) continue;
            if ( D[t] < 0 || D[t] > D[curr] + 1 ) {
                D[t] = D[curr] + 1;
                Q.push(t);
            }
        }
    }
    return D[e] > -1;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int F, S, G, Up, Dn;
    cin >> F >> S >> G >> Up >> Dn;
    memset(D, -1, sizeof(D));
    bfs(1, F, S, G, Up, Dn);

    if ( D[G] > -1 )
        cout << D[G] << '\n';
    else
        cout << "use the stairs\n";

    return 0;
}


