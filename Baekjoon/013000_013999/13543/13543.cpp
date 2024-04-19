#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

const ll INF = (1ll << 33);

using namespace std;
struct NODE {
    NODE *l, *r, *p ;
    ll val, cnt;
    ll minVal, maxVal, sumVal ;
    bool flip;
    bool dummy;

    NODE (NODE *parent, ll value) {
        dummy = false;
        flip = false;
        cnt = 1ll;
        minVal = maxVal = sumVal = 0ll;
        this->val = value ;
        this->p = parent ;
        this->l = this->r = nullptr ;
    }
    ~NODE() {
        delete l;
        delete r;
    }
}  ;
struct SplayTree {
    NODE *root;
    NODE *data[1'000'000];
    SplayTree() {
        memset(data, 0, sizeof(data));
    }
    ~SplayTree(){
        delete root;
    }
    void update(NODE *x) {
        x->cnt = 1;
        x->minVal = x->maxVal = x->sumVal = x->val;
        for (auto p : {x->l, x->r}) {
            if ( !p ) continue;
            x->cnt += p->cnt;
            x->sumVal += p->sumVal;
            x->minVal = min(x->minVal, p->minVal);
            x->maxVal = max(x->maxVal, p->maxVal);
        }
    }
    void push( NODE *x ) {
        if ( ! x->flip ) return ;
        swap(x->l, x->r);
        for (auto p : {x->l, x->r, x}) {
            if ( !p ) continue;
            p->flip = !p->flip;
        }
    }
    void rotate(NODE *x) {
        NODE *p = x->p, *y;
        push(p);
        push(x);

        if (p->l == x) {
            p->l = y = x->r;
            x->r = p;
        }
        else {
            p->r = y = x->l;
            x->l = p;
        }
        x->p = p->p;
        p->p = x;
        if(y) y->p = p;
        if(x->p) {
            if (p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else {
            root = x;
        }
        update(p);
        update(x);
    }
    void splay(NODE *x, NODE *g = nullptr) {
        NODE *y ;
        while (x->p != g) {
            NODE* p = x->p;
            if ( p->p == g ) {
                rotate(x);
                break;
            }
            auto pp = p->p ;
            if ( (p->l == x ) == (pp->l ==p) ) {
                rotate(p);
                rotate(x);
            } else {
                rotate(x);
                rotate(x);
            }
        }
        if ( !g) root = x;
    }
    void insert(ll key) {
        NODE *p, **pp;
        for ( pp=&root, p=*pp ; *pp && p->val != key ; p=*pp)
            pp = (key < p->val) ? &(p->l) : &(p->r);
        *pp = new NODE(p, key);
        splay(*pp);
    }
    void kth(ll k) {
        NODE *x = root ;
        push(x);

        while ( 1 ) {
            while ( x->l && x->l->cnt > k ) {
                x = x->l ;
                push(x);
            }
            if ( x->l ) k -= x->l->cnt ;
            if ( !k ) break;
            k--;
            x = x->r ;
            push(x);
        }
        splay(x);
    }
    void dump(NODE *p = nullptr, int depth=0) {
        if ( !p ) p = root;
        int i;
        for ( i = 0 ; i < depth ; i ++ ) cout << "  ";
        cout << p->val ;

        if ( p->l && !p->l->dummy ) cout << "[ " << p->l->val << ", " ;
        else cout << "[ null, " ;

        if ( p->r && !p->r->dummy ) cout  << p->r->val << " ]" ;
        else cout << "null ]" ;
        cout << '\n';
        if ( p->l && !p->l->dummy ) dump(p->l, depth+1);
        if ( p->r && !p->r->dummy ) dump(p->r, depth+1);
    }
    NODE *setRoot(ll s, ll e) {
#ifdef AJAVA_DEBUG
        cout << "[setRoot before] :" ; print(root); cout << '\n';
        dump();
#endif

        kth(e+1);
#ifdef AJAVA_DEBUG
        cout << "[kth(e+1)] :" ; print(root); cout << '\n';
        dump();
#endif
        NODE *t = root ;
        kth(s-1);

#ifdef AJAVA_DEBUG
        cout << "[kth(s-1)] :" ; print(root); cout << '\n';
        dump();
#endif

        splay(t, root);

#ifdef AJAVA_DEBUG
        cout << "[splay(t, root)] :" ; print(root); cout << '\n';
        dump();
#endif
        return root->r->l;
    }
    void flip(ll s, ll e) {
        NODE *x = setRoot(s, e);
        x->flip = !x->flip;
    }

    void init(vector<ll> A) {
        int i ;
        root = new NODE(nullptr, -INF);
        root->dummy = true ;

        auto now = root ;
        for ( auto a: A) {
            data[i] = now->r = new NODE(now, a);
            now = now->r;
        }
        now->r = new NODE(now, INF);
        now->r->dummy = true ;
        for ( i = A.size() ; i >= 1 ; i-- ) update(data[i]);
        splay(data[A.size()/2]);
    }
    void shift(int s, int e, int k) {
        if (k >= 0) {
            k %= (e - s + 1);
            if (!k) return;
            flip(s, e);
            flip(s, s + k - 1);
            flip(s + k, e);
        } else {
            k *= -1;
            k %= (e - s + 1);
            if (!k) return;
            flip(s, e);
            flip(s, e - k);
            flip(e - k + 1, e);
        }
    }
    void getidx(int k)
    {
        splay(data[k]);
        cout << root->l->cnt << "\n";
    }

    void print(NODE *x){
        push(x);
        if(x->l) print(x->l);
        if(!x->dummy) cout << x->val << " ";
        if(x->r) print(x->r);
    }
};

void process() {
    fastio;
    SplayTree tree;

    int N, Q, c, l, r, i, x ;
    cin >> N  ;
    vector<ll> A(N);
    for ( auto &a : A)
        cin >> a;
    tree.init(A);


#ifdef AJAVA_DEBUG
    cout << "[init] :" ; tree.print(tree.root);
    cout << '\n';
#endif

    while ( Q -- ) {
        cin >> c;
        if ( c == 1 ) {
            // 1 p v: Ap의 앞에 v를 추가한다. p가 A의 길이와 같은 경우에는 가장 마지막에 추가하는 것이다. (0 ≤ p ≤ A의 길이, 0 ≤ v < 232)
            cin >> l >> r ;
#ifdef AJAVA_DEBUG
            cout << "\n[cmd]  :" << 1 << ' ' << l << ' ' << r << '\n';
#endif
            tree.flip(l, r);
            NODE *node = tree.setRoot(l, r);
            cout << node->minVal << ' ' << node->maxVal << ' ' << node->sumVal << '\n';
        } else if ( c == 2 ) {
            // 2 p: Ap를 제거한다. (0 ≤ p < A의 길이)
            cin >> l >> r >> x;
#ifdef AJAVA_DEBUG
            cout << "\n[cmd]  :" << 2 << ' ' << l << ' ' << r << ' ' << x << '\n';
#endif
            NODE *node = tree.setRoot(l, r);
            cout << node->minVal << ' ' << node->maxVal << ' ' << node->sumVal << '\n';
            tree.shift(l, r, x);
        } else if ( c == 3 ) {
            // 3 p v: Ap를 v로 바꾼다. (0 ≤ p < A의 길이, 0 ≤ v < 232)
            cin >> x;

#ifdef AJAVA_DEBUG
            cout << "\n[cmd]  :" << 3 << ' ' << x << '\n';
#endif
            tree.kth(x);
            cout << tree.root->val << '\n';
        } else if ( c == 4 ) {
            // 4 l r k: l ≤ i ≤ r에 대해서 (ΣAi × (i - l + 1)k) mod 232를 구한 다음 출력한다. (0 ≤ k ≤ 10)
            cin >> x;
#ifdef AJAVA_DEBUG
            cout << "\n[cmd]  :" << 4 << ' ' << x << '\n';
#endif
            tree.getidx(x);
        }

#ifdef AJAVA_DEBUG
        cout << "[debug] :" ; tree.print(tree.root);
        cout << '\n';
#endif
    }
    tree.print(tree.root);
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


