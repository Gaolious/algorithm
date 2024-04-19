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

const ll INF = 100000000000ll;
struct SegmentTree {
    struct Node {
        int minIndex;
        char c;
    };
    Node Default = {-1, 'z'+1};
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
        if ( l.c <= r.c)
            return l;
        else
            return r;
    }
    void remove(int idx) {
        T[ idx += base ] = Default;

        for ( idx /=2 ; idx >= 1 ; idx /=2 ) {
            T[idx] = Merge(T[idx * 2], T[idx * 2 + 1]);
        }
    }
    void build() {
        for (int i = (base + N - 1) / 2 ; i >= 1 ; i -- )
            T[i] = Merge(T[i*2], T[i*2+1]);
    }
    int query(int l, int r) {
        Node left = Default;
        Node right = Default;
        for ( l += base, r+=base ; l <= r ; l/=2, r/=2 ) {
            if ( l % 2 == 1 ) left = Merge(left, T[l++]);
            if ( r % 2 == 0 ) right = Merge(T[r--], right);

        }
        return Merge(left, right).minIndex ;
    }
     void dump() {
     	int width = 5, prevW;
     	queue<pii> Q[2];
     	int turn = 0;
     	Q[turn].emplace(1, (1<<H)*width );
     	for ( int i = 0 ; i <= H ; i ++, turn = 1 - turn ) {
     		prevW = 0;
     		while (!Q[turn].empty()) {
     			auto [idx, w] = Q[turn].front();
     			Q[turn].pop();
     			cout << setw(w - prevW) << ' ';
     			cout << setw(2) << T[idx].minIndex << '/' << setw(2) << T[idx].c ;
     			Q[1-turn].emplace(idx*2, w -  ( 1 << (H-i-1) ) * width );
     			Q[1-turn].emplace(idx*2+1, w + ( 1 << (H-i-1) ) * width);
     			prevW = w + width;
     		}
     		cout << endl;
     	}
     }
};
vector<bool> D;
int cnt ;
SegmentTree st;
string S;

void F(int l, int r) {
    if ( l > r ) return;

    int idx = st.query(l, r);
    if ( idx < 0 ) return;

    st.remove(idx);
//    st.dump();

    D[idx] = true;
    cnt++;
    string ans ;
    for ( int i = 0 ; i < S.size(); i ++ )
        if ( D[i] ) ans.push_back(S[i]);
    cout << ans << '\n';

    F(idx+1, r);
    F(l, idx-1);
}

void process() {
    int i, N ;
    cin >> S;
    N = S.size();

    st.init(N);
    D.resize(N);
    for ( i = 0 ; i < S.size() ; i ++ )
        st.T[ st.base + i ] = {i, S[i] };
    st.build();
//    st.dump();

    F(0, N-1);
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


