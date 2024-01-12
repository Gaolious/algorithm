#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

// #define MaxN (1'000'000)
#define MaxN (10)

vector<int> E[MaxN + 1];
int D[MaxN+1][2];
char flag[MaxN+1];

void F(int curr) {
    flag[curr] = 1;
    D[curr][0] = 1;
    for(auto child : E[curr]) {
        if ( flag[child] ) continue;
        F(child);
        D[curr][1] += D[child][0];
        D[curr][0] += min(D[child][1], D[child][0]);
    }
}
int main()
{
    fastio;
    int i, N, a, b ;
    cin >> N ;

    for (i = 0 ; i < N ; i ++ ) {
        cin >> a >> b ;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    F(1);
    cout << min(D[1][0], D[1][1]) << '\n';
    return 0;
}


