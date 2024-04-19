#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<int> tree;
vector<int> A;
const int INF = 2'000'000'000;

int init( int idx, int s, int e){
    if ( s == e )
        return tree[idx] = A[s];
    else
    {
        int m = (s+e)/2;
        return tree[idx] = min( init(idx*2, s, m), init(idx*2+1, m+1, e));
    }
}
int update(int idx, int s, int e, int l, int r, int v) {
    if ( s > r || e < l ) return INF;
    if ( l <= s && e <= r ) {
        return tree[idx] = v;
    } else {
        int m = (s+e)/2;
        update(idx*2, s, m, l, r, v);
        update(idx*2+1, m+1, e, l, r, v);
        return tree[idx] = min(tree[idx*2], tree[idx*2+1]);
    }
}
int query(int idx, int s, int e, int l, int r) {
    if ( s > r || e < l ) return INF;
    if ( l <= s && e <= r ) {
        return tree[idx];
    } else {
        int m = (s+e)/2;
        return min(query(idx*2, s, m, l, r ), query(idx*2+1, m+1, e, l, r));
    }
}

void process() {
    fastio;
    int N, treeHeight ;
    int i;
    int M, a, b, c ;

    cin >> N ;
    A.resize(N+1);

    for ( treeHeight=1 ; treeHeight < N ; treeHeight *= 2 );
    tree.resize(treeHeight*2+1);

    for (i = 1 ; i <= N ; i ++ )
        cin >> A[i];

    init(1, 1, N);

    cin >> M ;
    while ( M -- ) {
        cin >> a >> b >> c ;
        if ( a == 1 ) {
            update(1, 1, N, b, b, c);
        } else {
            cout << query(1, 1, N, b, c) << '\n';
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


