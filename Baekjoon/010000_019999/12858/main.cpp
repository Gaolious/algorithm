#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
//int N ;
//Node merge(Node a, Node b){
//    return Node{ gcd(a.val, b.val), 0 };
//}
//ll query_val(int idx, int s, int e) {
//
//}

//
//void update(int idx, int s, int e, int l, int r, ll val ) {
//    _update_lazy(idx, s, e);
//
//    if (s > r || e < l ) return;
//
//    if (l <= s && e <= r )
//    {
//        Tree[idx].lazy += val ;
//        _update_lazy(idx, s, e);
//    }
//    else
//    {
//        int m ;
//        m = ( s + e ) / 2 ;
//        update(idx * 2, s, m, l, r, val);
//        update(idx * 2 + 1, m + 1, e, l, r, val);
//        Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
//    }
//}
//

struct Node {
    ll val ;
    ll lazy;
};
vector<Node> Tree ;
Node merge( Node a, Node b){
    return Node{a.val, 0 };
}
Node init(int idx, int s, int e, ll val) {
    if ( s == e )
        return Tree[idx] = Node{val, 0};
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m, val), init(idx*2+1, m+1, e, val) );
}
void propagation(int idx, int s, int e) {
    if ( s == e ) {
        Tree[idx].val += Tree[idx].lazy;
    } else {
        Tree[idx*2].lazy += Tree[idx].lazy ;
        Tree[idx*2+1].lazy += Tree[idx].lazy ;
    }
    Tree[idx].lazy = 0;
}
void update(int idx, int s, int e, int l, int r, ll val ) {
    propagation(idx, s, e);

    if (s > r || e < l ) return;

    if (l <= s && e <= r )
    {
        Tree[idx].lazy += val ;
        propagation(idx, s, e);
    }
    else
    {
        int m ;
        m = ( s + e ) / 2 ;
        update(idx * 2, s, m, l, r, val);
        update(idx * 2 + 1, m + 1, e, l, r, val);
        Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
    }
}
int main()
{
    int treeSize ;
    int N, M, T, l, r ;
    int i, n ;

    fastio;

    cin >> N ;

    for ( treeSize=1 ; treeSize<N ; treeSize *= 2 );
    Tree.resize(treeSize * 2 + 1, {0, 0});

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n ;
        init(1, 1, N, n);
    }

    cin >> M ;
    while ( M -- ) {
        cin >> T >> l >> r ;
        if ( T == 0 ) {

        } else {

        }
    }
    return 0;
}


