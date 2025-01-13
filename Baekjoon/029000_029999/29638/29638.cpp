#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
vector<ll> A;
ll S;
vector<pair<pii, int>> ans ;
const int INF = 100000000;
struct SegmentTree {
    int base{};
    vector<ll> T{};
    int N{}, H{} ;
    void init(int n) {
        N = n;
        H = ceil( log2(n) );
        base = 1 << int( H );
        T.resize( base * 2, -1);
    }
    ll Merge(ll l, ll r) {
        return max(l, r);
    }
    void build() {
        for (int i = (base + N - 1) / 2 ; i >= 1 ; i -- )
            T[i] = Merge(T[i*2], T[i*2+1]);
    }
    void Update(int idx, ll diff) {
        if ( diff == 0 ) return;

        T[idx += base] += diff;
        for (idx /= 2 ; idx >= 1 ; idx /=2 )
            T[idx] = Merge(T[idx*2], T[idx*2+1]);
    }
    ll query(int l, int r) {
        ll left = -1;
        ll right = -1;
        for ( l += base, r+=base ; l <= r ; l/=2, r/=2 ) {
            if ( l % 2 == 1 ) left = Merge(left, T[l++]);
            if ( r % 2 == 0 ) right = Merge(T[r--], right);

        }
        return Merge(left, right) ;
    }
};
SegmentTree st;

void makePotion(int i, int j, ll cnt) {
    if ( cnt < 1 ) return;
    if ( i > j ) swap(i, j);

    st.Update(i, -cnt);
    st.Update(j, -cnt);

    ans.push_back({{i + 1, j + 1}, cnt});

    A[i] -= cnt;
    A[j] -= cnt;

    S -= cnt * 2 ;
}

void mergeAnswer() {
    int N = ans.size() ;
    int i, j;

    for ( i = 0, j=1 ; j < N ; j ++ ) {
        if ( ans[i].first == ans[j].first ) {
            ans[i].second += ans[j].second;
        }
        else i++;
    }
    ans.resize(i+1);
}
ll determine(int N, int i, int j) {
    ll lo, hi, m, cnt;

    lo = 0, hi = min(A[i], A[j]);
    cnt = 0;

    while (lo <= hi) {
        m = (lo + hi) / 2;
        st.Update(i, -m);
        st.Update(j, -m);

        auto ret = st.query(0, N - 1);
        if ( ret * 2 <= S - 2*m + 1 ) {
            cnt = m;
            lo = m + 1;
        }
        else
            hi = m - 1;

        st.Update(i, m);
        st.Update(j, m);
    }

    makePotion(i, j, cnt);
    return cnt;
}
void process(int Case) {

    int N, i, j, lastIndex;
    cin >> N ;
    A.resize(N);
    st.init(N);

    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[ i ] ;
        S += A[ i ] ;
        st.T[ st.base + i ] = A[ i ] ;
    }
    st.build();

    for ( i = 0, j = 1; j < N ; j ++ ) {
        while ( i < N && A[i] == 0 ) i++;
        if ( i >= j ) continue;

        determine(N, i, j) ;
    }

    for ( i = 0 ; i < N ; i ++ ) {
        if ( A[i] * 2 >= S ) {
            for ( j = 0 ; j < N && A[i] > 0 ; j ++ ) {
                if ( A[j] == 0 || i == j ) continue;
                int cnt = min(A[i], A[j]);
                makePotion(i, j, cnt);
            }
        }
    }

    std::sort(ans.begin(), ans.end());
    mergeAnswer();
    cout << ans.size() << '\n';
    for ( auto [p, c]: ans ) {
        cout << p.first << ' ' << p.second << ' ' << c << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
