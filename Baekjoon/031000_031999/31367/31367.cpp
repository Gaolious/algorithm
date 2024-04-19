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

const int MaxCount = 100'001;
vector<int> P;
int N ;
struct SegmentTree {
    struct Node {
        ll maxSwimmer;
        ll cnt;
    };
    Node Default = {0, 0};
    int base{};
    vector<Node> T{};
    int N{}, H{} ;
    void init(int n) {
        N = n;
        H = ceil( log2(n) );
        base = 1 << int( H );
        T.resize( base * 2, Default);
    }
    Node Merge(Node l, Node r) {
        Node ret{} ;
        if ( l.maxSwimmer > r.maxSwimmer ) ret = l;
        else if ( l.maxSwimmer < r.maxSwimmer ) ret = r;
        else ret = { l.maxSwimmer, l.cnt + r.cnt };
        return ret;
    }
    void update(int idx, int add) {
        idx += base;
        T[idx].maxSwimmer += add;
        T[idx].cnt = 1;
        for ( idx /= 2 ; idx >= 1 ; idx /= 2 )
            T[idx] = Merge(T[idx*2], T[idx*2+1]);
    }
    Node query(int l, int r) {
        Node left = Default;
        Node right = Default;
        for ( l += base, r+=base ; l <= r ; l/=2, r/=2 ) {
            if ( l % 2 == 1 ) left = Merge(left, T[l++]);
            if ( r % 2 == 0 ) right = Merge(T[r--], right);

        }
        return Merge(left, right) ;
    }
};

void process() {
    int i, j;
    SegmentTree st;
    SegmentTree::Node ret;

    cin >> N ;
    P.resize(N);
    st.init(N);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> P[i];
        st.update(i, P[i]);
    }
    ll ans = -1 ;

    ret = st.query(0, N-1);
    ans = ret.maxSwimmer * ret.cnt;

    for ( i = 0 ; i < N ; i ++ )
    {
        for ( j = -1 ; j <= 1 ; j += 2 ) {
            if ( i + j < 0 || i + j >= N ) continue;
            if ( P[i+j] < 1 ) continue;

            st.update(i, 1);
            st.update(i+j, -1);
            ret = st.query(0, N-1);
            if ( ret.cnt == 1 ) {
                ans = min(ans, ret.maxSwimmer * ret.cnt);
            }
            st.update(i+j, +1);
            st.update(i, -1);
        }
        if ( i > 0 && i < N-1 && P[i-1] > 0 && P[i+1] > 0 ) {
            st.update(i-1, -1);
            st.update(i+1, -1);
            st.update(i, 2);
            ret = st.query(0, N-1);
            if ( ret.cnt == 1 ) {
                if ( ans < 0 || ans > ret.maxSwimmer )
                    ans = ret.maxSwimmer;
            }
            st.update(i, -2);
            st.update(i-1, 1);
            st.update(i+1, 1);
        }
    }
    cout << ans << '\n';
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


