#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

int sqrtN;
const int MaxN = 100000;

struct Query {
    int l, r, idx;
    bool operator<(const Query &o) const {
        int s1 = l/sqrtN, s2 = o.l/sqrtN;
        return s1 != s2 ? s1 < s2 : r < o.r ;
    }
};
vector<int> A;
vector<int> ans;
vector<Query> Q;
int C[MaxN + 1];
int R[MaxN + 1];
int cnt ;

// WA
void F(int idx, bool add) {
    if ( add ) {
        if (C[idx] != 0)
            R[C[idx]]--;
        C[idx]++;
        cnt = max(cnt, C[idx]);
    }
    else {
        R[ C[idx] ] --;
        if (C[idx] == cnt && !R[ C[idx] ]) cnt --;
        C[idx]--;
    };
    R[C[idx]]++;
}
void process() {
    int N, M, i;

    cin >> N ;
    sqrtN = sqrt(N);
    A.resize(N);
    for ( i = 0 ; i < N ; i ++ ) cin >> A[i] ;

    cin >> M ;
    Q.resize(M);
    ans.resize(M, 0);
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--; Q[i].r--;
        Q[i].idx = i;
    }
    sort(Q.begin(), Q.end());

    int lo=Q[0].l, hi=Q[0].l-1;
    cnt=0 ;
    for (auto q : Q ) {
        while ( q.l > lo ) F(A[lo++], false);
        while ( q.l < lo ) F(A[--lo], true);
        while ( q.r > hi ) F(A[++hi], true);
        while ( q.r < hi ) F(A[hi--], false);

        ans[ q.idx ] = cnt;
    }

    for ( i = 0 ; i < M ; i ++ )
        cout << ans[ i ] << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


