#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll INF = 1'000'000'000'000'000'000ll;

struct Node {
	ll A, B, C;
	ll addX, setMaxY, setMinY;
	ll minLeftA, minRightA;
	ll minLeftB, minRightB;
	ll maxLeftC, maxRightC;
};
const Node DefaultNode = {-INF,-INF, -INF, -INF, -INF, -INF, -INF, -INF, -INF, -INF, -INF, -INF};
struct SegmentTree {
	int base{};
	vector<Node> T{};
	int N{}, H{} ;
	void init(int n) {
		N = n;
		H = ceil( log2(n) );
		base = 1 << int( H );
		T.resize( base * 2, DefaultNode);
	}
	void Push(int idx, int s, int e)
	{
		// if ( T[idx].lazy ) {
		// 	T[idx].sum += T[idx].lazy;
		// 	if ( s != e ) {
		// 		T[idx*2].lazy += T[idx].lazy;
		// 		T[idx*2+1].lazy += T[idx].lazy;
		// 	}
		// 	T[idx].lazy = 0;
		// }
	}
	Node Merge(Node l, Node r) {
		Node ret{} ;
		// ret.LmaxSum = max(l.LmaxSum , l.AllSum + r.LmaxSum);
		// ret.RmaxSum = max(l.RmaxSum + r.AllSum, r.RmaxSum);
		// ret.maxSum = max(max(l.maxSum, r.maxSum), l.RmaxSum + r.LmaxSum);
		// ret.AllSum = l.AllSum + r.AllSum;
		return ret;
	}
	void build() {
		for (int i = (base + N - 1) / 2 ; i >= 1 ; i -- )
			T[i] = Merge(T[i*2], T[i*2+1]);
	}
	Node Query(int idx, int s, int e, int l, int r ) {
		Push(idx, s, e);
		if (s > r || e < l ) return DefaultNode;
		if (l <= s && e <= r) return T[idx];
		int m = ( s + e ) / 2 ;
		return Merge(Query(idx * 2, s, m, l, r), Query(idx * 2 + 1, m + 1, e, l, r));
	}

	void Update(int idx, int s, int e, int l, int r, int cmd, ll v ) {
		Push(idx, s, e);
		if (s > r || e < l ) return;
		if (l <= s && e <= r )
		{
			if ( cmd == 1 ) T[idx].addX += v;
			else if ( cmd == 2 ) T[idx].setMaxY += v;
			else if ( cmd == 3 ) T[idx].setMinY += v;
			if ( s != e ) Push(idx, s, e);
		}
		else {
			int m = ( s + e ) / 2 ;
			Update(idx * 2, s, m, l, r, cmd, v);
			Update(idx * 2 + 1, m + 1, e, l, r, cmd, v);
			T[idx] = Merge(T[idx * 2], T[idx * 2 + 1]);
		}
	}

	// void dump() {
	// 	int width = 5, prevW;
	// 	queue<pii> Q[2];
	// 	int turn = 0;
	// 	Q[turn].emplace(1, (1<<H)*width );
	// 	for ( int i = 0 ; i <= H ; i ++, turn = 1 - turn ) {
	// 		prevW = 0;
	// 		while (!Q[turn].empty()) {
	// 			auto [idx, w] = Q[turn].front();
	// 			Q[turn].pop();
	// 			cout << setw(w - prevW) << ' ';
	// 			cout << setw(2) << T[idx].m1 << '/' << setw(2) << T[idx].m2 ;
	// 			Q[1-turn].emplace(idx*2, w -  ( 1 << (H-i-1) ) * width );
	// 			Q[1-turn].emplace(idx*2+1, w + ( 1 << (H-i-1) ) * width);
	// 			prevW = w + width;
	// 		}
	// 		cout << endl;
	// 	}
	// }
};

void process(int Case) {
	int i, N, M, cmd, L, R, X, Y;
	SegmentTree tree;

	cin >> N ;
	tree.init(N);
	for (i = 0 ; i < N ; i ++ )
	{
		auto &t = tree.T[ tree.base + i ];
		cin >> t.A ;
		t.B = t.C = t.A ;
	}
	tree.build();
	cin >> M ;
	while ( M -- )
	{
		// 1 L R X: 모든 L ≤ i ≤ R에 대해서 Ai = Ai + X를 적용한다.
		// 2 L R Y: 모든 L ≤ i ≤ R에 대해서 Ai = max(Ai, Y)를 적용한다.
		// 3 L R Y: 모든 L ≤ i ≤ R에 대해서 Ai = min(Ai, Y)를 적용한다.
		// 4 L R: min(AL, AL+1, ...,AR)을 출력한다.
		// 5 L R: min(BL, BL+1, ...,BR)을 출력한다.
		// 6 L R: max(CL, CL+1, ...,CR)을 출력한다.
		cin >> cmd >> L >> R ;
		switch ( cmd )
		{
		case 1:
			cin >> X;
			break;
		case 2:
			cin >> Y;
			break;
		case 3:
			cin >> Y;
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
