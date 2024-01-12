#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
/*
#define MAX_SIZE (4'000'000)
// #define MAX_SIZE (4'0)
int Tree[MAX_SIZE]={0,};
bool Lazy[MAX_SIZE]={false,};
int N ;

void update_lazy(int idx, int s, int e) {
    if ( Lazy[idx] ) {
        Tree[idx] = (e-s+1);

        Lazy[idx*2] = Lazy[idx];
        Lazy[idx*2+1] = Lazy[idx];
        Lazy[idx] = false;
    }
}

void install(int idx, int s, int e, int l, int r ) {
    update_lazy(idx, s, e);

    if (s > r || e < l ) return ;
    if ( Tree[idx] == (e-s+1) ) return;

    if (l <= s && e <= r ) {
        Lazy[idx] = true;
        update_lazy(idx, s, e);
    }
    else {
        int m = ( s + e ) / 2 ;
        install(idx * 2, s, m, l, r);
        install(idx * 2 + 1, m + 1, e, l, r);
        Tree[idx] = Tree[idx*2] + Tree[idx*2+1];
    }
}

int query(int idx, int s, int e, int l, int r ) {
    update_lazy(idx, s, e);
    if (s > r || e < l ) return 0;
    if (l <= s && e <= r) return Tree[idx];
    int m = ( s + e ) / 2 ;
    return query(idx * 2, s, m, l, r) + query(idx * 2 + 1, m + 1, e, l, r);
}

int main()
{
    fastio;

    int N, M ;
    int a, b;
    int i, ret, cnt;
    int j ;
    int remain ;
    int installed ;
    int need;

    cin >> N >> M ;
    remain = installed = 0;

    for ( i = 1 ; i <= M ; i ++) {
        remain ++;

        cin >> a >> b;
        cnt = query(1, 1, N-1, a, b-1);
        if ( cnt < (b-a) ) {
            need = (b-a) - cnt ;
            if ( remain < need ) {
                installed += need - remain ;
                remain = 0;
            } else {
                remain -= need ;
            }
        }

        install(1, 1, N-1, a, b-1);
    }

    cout << installed << '\n';
    return 0;
}


/**/
#ifdef AJAVA_DEBUG
#define MAX_SIZE (40)
#else
#define MAX_SIZE (500'000)
#endif

int A[MAX_SIZE + 1];
int P[MAX_SIZE + 1];

int Find(int x) {
    if ( x == P[x] )
        return x;
    return P[x] = Find(x);
}
void merge(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    P[pa] = P[pb] = max(pa, pb);
}
int query(int l, int r) {
    int cnt = 0 ;
    while ( l <= r ) {
        if ( A[l] < 0 ) {
            cnt ++;
            A[l] = r;
            l++;
        }
        else {
            l = A[l] + 1;
        }
    }
    return cnt ;
}

int main() {
    fastio;
    int N, M ;
    int i, a, b ;
    int remain ;
    int installed ;
    int need;

    cin >> N >> M ;
    memset(A, -1, sizeof(A));
    memset(P, -1, sizeof(P));

    remain = installed = need = 0;

    for ( i = 1 ; i <= M ; i ++ ) {
        cin >> a >> b ;

        int cnt = query(a, b-1);
        if ( cnt < (b-a) ) {
            need = (b-a) - cnt ;
            if ( remain < need ) {
                installed += need - remain ;
                remain = 0;
            } else {
                remain -= need ;
            }
        }


    }
    return 0;
}