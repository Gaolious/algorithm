#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

typedef struct DATA DL;
struct DATA {
    int a, b;
    bool is_used{};

    DL *prev{}, *next{};

    DL * del() {
        DL *l = prev, *r = next;
        if ( l ) l->next = next ;
        if ( r ) r->prev = prev ;
        this->is_used = true;
        return l;
    }
    void add(DL *node) {
        DL *l = this, *r = next;
        if (l) l->next = node;
        if (r) r->prev = node ;
        node->prev = l;
        node->next = r;
        node->is_used = false;

    }
};
bool Row[9][9], Col[9][9], Box[3][3][9];
int T[9][9];

DL A[36+2], *root = A+0, *tail = A+37;

int dx[] {0, 1};
int dy[] {1, 0};

void init() {
    int i, j, n;
    for ( i = 1, n=1 ; i <= 9 ; i ++ )
        for ( j = i + 1 ; j <= 9 ; j ++ ) {
            A[n].a = i, A[n].b = j ;
            n++;
        }
    for ( i = 0 ; i < 38 ; i ++ ) {
        A[i].prev = i == 0 ? NULL : A + i - 1;
        A[i].next = i == 37 ? NULL : A + i + 1;
    }

    for ( i = 0 ; i < 9 ; i ++ ) {
        for ( j = 0 ; j < 9 ; j ++ ) {
            Row[i][j] = Col[i][j] = Box[i/3][i%3][j] = false;
            T[i][j] = -1;
        }
    }
}
void assign(int y, int x, int val, bool t) {
    Row[y][val-1] = t;
    Col[x][val-1] = t;
    Box[y/3][x/3][val-1] = t;
    T[y][x] = t ? val : -1;
}
bool can(int y, int x, int val) {
    if ( y < 0 || x < 0 || y >= 9 || x >= 9 ) return false ;
    if ( T[y][x] > 0 ) return false;
    return !Row[y][val-1] && !Col[x][val-1] && !Box[y/3][x/3][val-1];
}
void dump(int nth) {
    int i, j;
    cout << "Puzzle " << nth << '\n';
    for ( i = 0 ; i < 9 ; i ++ ) {
        for ( j = 0 ; j < 9 ; j ++ )
            cout << T[i][j];
        cout << '\n';
    }
}

bool F(int nth) {
    if ( nth >= 81 ) {
        return true;
    }
    int y, x, d, ty, tx;
    y = nth / 9 ;
    x = nth % 9 ;
    if ( T[y][x] > 0 )
        return F(nth+1);

    for ( auto i = root->next ; i != tail ; i = i->next ) {
        auto backup = i->del();
        for ( auto t : { i->a * 10 + i->b, i->a + i->b * 10}) {
            int v1 = t/10, v2 = t%10;
            for ( d = 0 ; d < 2 ; d ++ ) {
                ty = y + dy[d];
                tx = x + dx[d];
                if ( can(y, x, v1) && can(ty, tx, v2) ) {
                    assign(y, x, v1, true);
                    assign(ty, tx, v2, true);
                    if ( F(nth+1) )
                        return true;
                    assign(y, x, v1, false);
                    assign(ty, tx, v2, false);
                }
            }
        }
        backup->add(i);
    }

    return false;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, N, n, a, k, num[2];
    char p1, p2;

    for (k=1 ; cin >> N && N > 0 ; k ++) {
        init();
        while ( N -- ) {
            for ( i = 0 ; i < 2 ; i ++ ) {
                cin >> a >> p1 >> p2 ;
                assign(p1-'A', p2-'1', a, true);
                num[i] = a;
            }
            if ( num[0] > num[1] ) swap(num[0], num[1]);
            int idx = 36 - (9-num[0])*(10-num[0])/2 + num[1] - num[0] ;
            A[idx].del();
            // assert ( A[idx].a * 10 + A[idx].b == num[0]*10 + num[1]);
        }
        for ( i = 1 ; i <= 9 ; i ++ ) {
            cin >> p1 >> p2 ;
            assign(p1-'A', p2-'1', i, true);
        }
        F(0);
        dump(k);
    }

    return 0;
}


