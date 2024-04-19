#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef struct DATA DL;
struct DATA {
    int val;
    DL *prev, *next;
    DL * del() {
        DL *l = prev, *r = next;
        if ( l ) l->next = next ;
        if ( r ) r->prev = prev ;
        return l;
    }
    void add(DL *node) {
        if ( node ) {
            DL *l = this, *r = next;
            l->next = r->prev = node ;
            node->prev = l;
            node->next = r;
        }
    }
    int score() {
        return prev->val * next->val;
    };
};

DL A[10]{};
DL *root, *tail;
int best = -1;
void F(int score) {
    if ( root->next == tail ) {
        best = max(best, score);
        return;
    }
    for ( auto i = root->next ; i != tail ; i = i->next ) {
        int s = i->score();
        auto backup = i->del();
        F(score + s);
        backup->add(i);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N ;
    int i, j ;
    cin >> N ;

    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ].val ;

    for ( i = 0 ; i < N ; i ++ ) {
        A[i].prev = i == 0 ? NULL : A + i - 1;
        A[i].next = i == N-1 ? NULL : A + i + 1;
    }
    root = A + 0;
    tail = A + N - 1 ;

    F(0);
    cout << best ;

    return 0;
}


