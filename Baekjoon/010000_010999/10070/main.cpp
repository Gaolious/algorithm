#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;

using namespace std;

const ll INF = 1e16;
struct Node {
    ll lo, hi;
};
vector<ll> A;
vector<Node> Tree;

Node merge(Node a, Node b){
    return Node{
        min(a.lo, b.lo),
        max(a.hi, b.hi),
    };
}
void update(int idx, int o, ll value){
    if ( o == 1 ) {
        Tree[idx].lo = max(Tree[idx].lo, value);
        Tree[idx].hi = max(Tree[idx].hi, value);
    } else {
        Tree[idx].lo = min(Tree[idx].lo, value);
        Tree[idx].hi = min(Tree[idx].hi, value);
    }
}
void update_query(int idx, int s, int e, int l, int r, int o, ll value ) {
    if (s > r || e < l) return;
    if (l <= s && e <= r )
    {
        update(idx, o, value);
        A[l] = Tree[idx].lo;
        return ;
    }
    int m ;
    m = ( s + e ) / 2 ;
    for ( auto i : {idx*2, idx*2+1}){
        update(i, 1, Tree[idx].lo);
        update(i, 2, Tree[idx].hi);
    }
    update_query(idx * 2, s, m, l, r, o, value);
    update_query(idx * 2 + 1, m + 1, e, l, r, o, value);
    Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
}
void print(int idx, int s, int e) {
    if ( s == e ) {
        cout << Tree[idx].lo << '\n';
        return;
    }
    for ( auto i : {idx*2, idx*2+1}){
        update(i, 1, Tree[idx].lo);
        update(i, 2, Tree[idx].hi);
    }
    int m = ( s + e ) / 2 ;
    print(idx * 2, s, m);
    print(idx * 2 + 1, m + 1, e);

}
void process() {
    fastio;
    int N, M;
    int a, b, c, d;
    int treeSize;

    cin >> N >> M ;
    A.resize(N+1);
    for ( treeSize=1 ; treeSize <= N ; treeSize *= 2 );
    Tree.resize(treeSize * 2 + 1);

    while ( M -- ) {
        cin >> a >> b >> c >> d ;
        b++, c++;
        if ( b > c ) swap(b, c);
        update_query(1, 1, N, b, c, a, d);

    }
    print(1, 1, N);

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


