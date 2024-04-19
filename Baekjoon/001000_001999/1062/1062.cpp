#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
// vector<int> A;
int N ;
int best = 0;
int Count[30]{};
typedef struct DATA DL;
struct DATA {
    int mask;

    DL *prev{}, *next{};

    DL * del() {
        DL *l = prev, *r = next;
        if ( l ) l->next = next ;
        if ( r ) r->prev = prev ;
        return l;
    }
    void add(DL *node) {
        DL *l = this, *r = next;
        if (l) l->next = node;
        if (r) r->prev = node ;
        node->prev = l;
        node->next = r;
    }
};
DATA A[30]{}, *root = NULL;

string NtoS(int mask) {
    int i ;
    string ret ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        if ( (( mask >> i ) & 1) == 1)
            ret += (char)('a' + i);
    }
    return ret;
}
int StoN(string &s) {
    int len = s.length();
    int ret = 0 ;
    for ( int i = 0 ; i < len ; i ++ )
        ret |= 1 << ( s[i] - 'a');
    return ret;
}

void F(int bit, int mask, int k ) {
    if ( k < 0 || bit > 26)
        return ;

    int cnt = 0;

    DATA backup{}, *i, *nxt;
    for ( i = root->next ; i ; i = nxt ) {
        nxt = i->next;
        if ( (mask & i->mask) == i->mask ) {
            backup.add(i);
            i->del();
            cnt ++;
        }
    }

    best = max(cnt, best);

    // cout << NtoS(mask) << " : " << best << '\n';
    if ( !( (mask>>bit)&1 )) {
        F(bit+1, mask | (1<<bit) , k-1);
    }

    F(bit+1, mask , k);

    for ( i = backup.next ; i ; i = i->next ) {
        root->next->add(i);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int K, t, i;
    string s ;

    cin >> N >> K ;

    int cnt = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s ;
        t = StoN(s);
        if ( t > 0 && __builtin_popcount(t) <= K ) A[++cnt].mask = t ;
    }
    N = cnt;
    for ( i = 1 ; i < 27 ; i ++ ) {
        A[i].prev = A + i - 1;
        A[i].next = A + i + 1;
    }
    root = A+0;
    A[0].next = A+1;
    A[N].next = NULL;

    for ( i = 1 ; i <= N ; i ++ ) {
        for (t = A[i].mask, i=0 ; t ; t >>=1, i++ ) {
            if ( t&1 ) Count[i]++;
        }
    }

    string antic = string("antic");
    int mask = StoN(antic) ;

    F(0, mask, K-5);
    cout << best << '\n';
    return 0;
}


