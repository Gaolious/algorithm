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

int sign(ll v) {
	if ( v > 0 ) return 1;
	if ( v < 0 ) return -1;
	return 0;
}

struct SegmentTree {
	int base;
	vector<ll> T;
	int N, H ;
	SegmentTree(int n) {
		N = n;
		H = ceil( log2(n) );
		base = 1 << int( H );
		T.resize( base * 2);
	}
	void update(int idx, int s, int e, int l, int r, ll val) {
		if ( s > r || e < l ) return;
		if ( l <= s && e <= r ) {
			T[idx] = val;
			return;
		}
		int m = (s+e)/2;
		update(idx*2, s, m, l, r, val);
		update(idx*2+1, m+1, e, l, r, val);
		T[idx] = T[idx*2] * T[idx*2+1];
	}
	ll query(int idx, int s, int e, int l, int r) {
		if ( s > r || e < l ) return 1;
		if ( l <= s && e <= r ) {
			return T[idx];
		}
		int m = (s+e)/2;
		return query(idx*2, s, m, l, r) * query(idx*2+1, m+1, e, l, r);
	}
	void dump() {
		int width = 2, prevW;
		queue<pii> Q[2];
		int turn = 0;
		Q[turn].emplace(1, (1<<H)*width );
		for ( int i = 0 ; i <= H ; i ++, turn = 1 - turn ) {
			prevW = 0;
			while (!Q[turn].empty()) {
				auto [idx, w] = Q[turn].front();
				Q[turn].pop();
				cout << setw(w - prevW) << ' ';
				cout << setw(width) << T[idx] ;
				Q[1-turn].emplace(idx*2, w -  ( 1 << (H-i-1) ) * width );
				Q[1-turn].emplace(idx*2+1, w + ( 1 << (H-i-1) ) * width);
				prevW = w + width;
			}
			cout << endl;
		}
	}
};

void process() {
	int N, K, a, b ;
	int i;
	char c;

	while ( cin >> N >> K ) {
		SegmentTree st(N);

		for ( i = 1 ; i <= N ; i ++ ) {
			cin >> a ;
			st.update(1, 1, N, i, i, sign(a));
		}
		st.dump();
		while ( K -- ) {
			cin >> c >> a >> b;
			if ( c == 'C' ) {
				st.update(1, 1, N, a, a, sign(b));
			}
			else if ( c == 'P' ) {
				switch ( st.query(1, 1, N, a, b) ) {
					case -1 : cout << '-'; break;
					case 0 : cout << '0'; break;
					case 1 : cout << '+'; break;
				}
			}
		}
		cout << '\n';
	}
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    // freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


