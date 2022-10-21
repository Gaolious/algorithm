#include <bits/stdc++.h>
using namespace std;

#ifndef BOJ_TREES_H
#define BOJ_TREES_H

namespace FENWICK {

long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}
}

namespace SEGMENT_TREE {

template <typename T>
class SegTree {
    vector<T> Tree;
    vector<T> Lazy;
    int N ;
    int size ;

    void _build(int idx, int s, int e) {
        for ( int i = this->size + this->N - 1 ; i > 1 ; i--)
            Tree[i/2] += Tree[i];
    }

    void _update_lazy(int idx, int s, int e) {
        if (this->Lazy[idx] != 0) {
            this->Tree[idx] += (e-s+1) * this->Lazy[idx];
            if (s != e ) {
                this->Lazy[idx * 2] += this->Lazy[idx];
                this->Lazy[idx * 2 + 1] += this->Lazy[idx];
            }
            this->Lazy[idx] = 0;
        }
    }

    void _update(int idx, int s, int e, int l, int r, T diff ) {
        this->_update_lazy(idx, s, e);

        if (s > r || e < l ) return;

        if (l <= s && e <= r )
        {
            this->Tree[idx] += (e - s + 1) * diff ;
            if ( s != e ) {
                this->Lazy[idx * 2] += diff;
                this->Lazy[idx * 2 + 1] += diff;
            }
        }
        else {
            int m = ( s + e ) / 2 ;
            this->_update(idx * 2, s, m, l, r, diff);
            this->_update(idx * 2 + 1, m + 1, e, l, r, diff);
            this->Tree[idx] = this->Tree[idx*2] + this->Tree[idx*2+1];
        }

    }

    T _query(int idx, int s, int e, int l, int r ) {
        this->_update_lazy(idx, s, e);
        if (s > r || e < l )
            return 0;
        if (l <= s && e <= r) {
            return this->Tree[idx];
        }
        int m = ( s + e ) / 2 ;
        return this->_query(idx * 2, s, m, l, r) + this->_query(idx * 2 + 1, m + 1, e, l, r);
    }

public :
    SegTree(int N) {
        this->N = N ;
        for ( this->size = 1 ; this->size < N ; this->size *= 2 ){}
        this->Tree.resize(this->size*2, 0);
        this->Lazy.resize(this->size*2, 0);
    }
    T &data(int idx) {
        return this->Tree[this->size + idx];
    }
    void init() {
        this->_build(1, 0, this->N - 1 );
    }
    void update(int rangeLeft, int rangeRight, T diff) {
        this->_update(1, 0, this->size-1, rangeLeft, rangeRight, diff);
    }
    T query(int rangeLeft, int rangeRight) {
        return this->_query(1, 0, this->size-1, rangeLeft, rangeRight);
    }
    void dump(){
#ifdef AJAVA_DEBUG
        int i, j ;
        printf("\n");
        for ( i = 1 ; i <= this->size ; i *= 2 ) {
            for ( j = 0 ; j < i ; j ++ )
                printf("%3lld ", this->Tree[i+j]);
            printf("\n");
        }
#endif
    }

};  
}


namespace SEG_TREE_LAZY {

struct Node {
    ll V;
    ll lazy;
};
ll A[100'000+1]={0,};
Node Tree[400'000]={0,};
int N ;

Node merge(Node a, Node b){
    return Node{ a.V ^ b.V, 0};
}

void _update_lazy(int idx, int s, int e) {

    if ( Tree[idx].lazy ) {
        if ( (e-s+1) % 2 == 1 )
            Tree[idx].V ^= Tree[idx].lazy;

        Tree[idx*2].lazy ^= Tree[idx].lazy ;
        Tree[idx*2+1].lazy ^= Tree[idx].lazy ;
        Tree[idx].lazy = 0;
    }
}

void update(int idx, int s, int e, int l, int r, ll minValue ) {
    _update_lazy(idx, s, e);

    if (s > r || e < l ) return;

    if (l <= s && e <= r )
    {
        Tree[idx].lazy ^= minValue ;
        _update_lazy(idx, s, e);
    }
    else
    {
        int m ;
        m = ( s + e ) / 2 ;
        update(idx * 2, s, m, l, r, minValue);
        update(idx * 2 + 1, m + 1, e, l, r, minValue);
        Tree[idx] = merge(Tree[idx*2], Tree[idx*2+1]);
    }
}

ll getXOR(int idx, int s, int e, int l, int r ) {
    _update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx].V;
    int m = ( s + e ) / 2 ;
    return getXOR(idx * 2, s, m, l, r) ^ getXOR(idx * 2 + 1, m + 1, e, l, r);
}

Node init(int idx, int s, int e) {
    if ( s == e ) {
        return Tree[idx] = Node{A[s], 0};
    }
    int m = ( s + e ) / 2 ;
    return Tree[idx] = merge( init(idx*2, s, m), init(idx*2+1, m+1, e) );
}

void process() {
    FIO fio;
    int N, M, Q ;
    int i ;
    int a, b, c, d;

    fio.Int(N, M, Q);
    for ( i = 1 ; i <= N ; i ++ )
        fio.Int(A[i]);

    init(1, 1, N);

    fio.Int(M);
    while ( M -- ) {
        fio.Int(a, b);
        b++;

        switch (a) {
            case 1:
                fio.Int(c, d);
                c++;
                if ( b > c ) swap(b, c);
                update(1, 1, N, b, c, d);
                break;
            case 2:
                fio.write_IntLn(getXOR(1, 1, N, b, b));
                break;
        }

    }

}
    
}

#endif //BOJ_TREES_H
