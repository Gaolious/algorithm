#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
// bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

struct Data {
    int sx, ex, h;
};

vector<int> Tree;
vector<int> C, Y, X;
int base;
void add(int idx, int addValue ) {
    C[idx]+= addValue;
    Tree[ idx = base + idx ] = C[idx] ? Y[idx] : 0;
    for ( idx = idx/2 ; idx > 0 ; idx /=2 )
        Tree[idx] = max( Tree[idx*2], Tree[idx*2+1] );
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, sx, ex, h, i ;
    vector<pair<int, int>> A;

    fastio;

    cin >> N ;
    Y.push_back(0);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> sx >> h >> ex;
        X.push_back(sx);
        X.push_back(ex);
        Y.push_back(h);
        A.emplace_back(sx, h);
        A.emplace_back(ex, -h);
    }
    sort(A.begin(), A.end());

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    for (auto &[a, b] : A) {
        if ( b < 0 )
            b = -(lower_bound(Y.begin(), Y.end(), -b) - Y.begin());
        else
            b = lower_bound(Y.begin(), Y.end(), b) - Y.begin();
    }

    sx = i = 0;
    N = Y.size() - 1;
    C.resize(Y.size(), 0);

    base = 1 << ( (int)ceil(log2(N+1)) );
    int treeSize = base * 2 + 1;

    Tree.resize(treeSize);
    int prevH = -1;
    i = 0;
    for (auto x : X ) {
        while ( i < A.size() && A[i].first <= x ) {
            add(abs(A[i].second), ( A[i].second > 0 ) ? 1 : -1 );
            i++;
        }
        if ( Tree[1] != prevH )
            cout << x << ' ' << (prevH = Tree[1]) << ' ';
    }

    return 0;
}


