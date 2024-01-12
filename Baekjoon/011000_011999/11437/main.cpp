#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#ifdef AJAVA_DEBUG
#define MAXN (20)
#else
#define MAXN (50'000)
#endif

vector<int> E[MAXN+1];
int Depth[MAXN+1];
char flag[MAXN+1];
int Parent[MAXN+1][20];

void makeTree(int curr, int depth) {
    flag[curr] = 1;
    Depth[curr] = depth ;

    for (auto idx: E[curr]) {
        if (flag[idx]) continue;
        Parent[idx][0] = curr;
        makeTree(idx, depth+1);
    }
}

int lca(int a, int b) {
    if ( Depth[a] > Depth[b]) swap(a, b);
    int diff = Depth[b] - Depth[a];
    int i;
    for ( i = 0 ; diff ; i++, diff /=2 )
        if ( diff % 2 )
            b = Parent[b][i];

    if ( a != b ) {
        for ( i = 19 ; i >= 0 ; i -- )
            if (Parent[a][i] != Parent[b][i])
                a = Parent[a][i], b = Parent[b][i];
    }
    return a == b ? a : Parent[a][0];
}

int main()
{
    fastio;
    int N, M;
    int a, b, c;
    int i ;

    cin >> N ;
    for ( i = 0 ; i < N - 1; i ++ ) {
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    makeTree(1, 0);
    for ( int d = 1 ; d < 20 ; d ++ )
        for ( i = 1 ; i <= N ; i ++ )
            Parent[i][d] = Parent[ Parent[i][d-1] ][d-1];

    cin >> M ;
    while ( M -- ) {
        cin >> a >> b ;
        c = lca(a,b);

#ifdef AJAVA_DEBUG
        cout << " A : " << a << " / B : " << b << " LCA : " << c << "\n";
#endif
        cout << c << '\n';
    }
    return 0;
}


