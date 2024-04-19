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

struct Fenwick { // 1-index
    vector<ll> T;
    Fenwick(int n = 1000) {
        T.resize(n+1);
    }
    ll sum(int i) {
        ll ans = 0;
        while (i > 0) {
            ans += T[i];
            i -= (i & -i);
        }
        return ans;
    }
    void update(int i, ll diff) {
        while (i < T.size()) {
            T[i] += diff;
            i += (i & -i);
        }
    }
    ll sum(int l, int r) {
        ll ret = r > 0 ? sum(r) : 0;
        if ( l > 1 ) ret -= sum(l-1);
        return ret;
    }
    void clear() {
        std::fill(T.begin(), T.end(), 0);
    }
};

vector<int> A;
int Del[11];
deque<int> Pos[11];
Fenwick Count[11];
int TotalDelCount;
int N ;

void Input(){
    int n, i;
    string s ;
    cin >> s ;
    N = s.size();
    A.resize(s.size() + 1);

    for ( i = 1 ; i <= s.size() ; i ++ ) {
        n = s[ i-1 ] - '0';
        A[ i ] = n ;
        Pos[ n ].push_back(i);
        Count[ n ].update(i, 1);
    }
    cin >> s ;
    TotalDelCount = s.size();
    for (auto c: s ) {
        n = c - '0';
        Del[n] ++;
    }
}
bool isPossible(int l, int currPos) {
    for ( int i = 0 ; i < 10 ; i ++ ) {
        auto cnt = Count[i].sum(l, currPos-1);
        if ( cnt > Del[i])
            return false;
    }
    return true;
}
int FindNumber(int l, int r) {
    int n;
    for (n = 9; n >= 0; n--) {
        if (Del[n] > 0 && Del[n] == Count[n].sum(l, r))
            continue;
        if (Pos[n].empty())
            continue;
        auto currPos = Pos[n].front();
        if (!isPossible(l, currPos))
            continue;
        return n;
    }
    return -1;
}

void process() {
    Input();
    int i, j, n;
    int s;
    vector<int> ans;

    for ( s = 1, i = TotalDelCount ; i < N ; i ++) {
        n = FindNumber(s, N);
        if ( n < 0 )
            continue;
        auto currPos = Pos[ n ].front();

        for (j = s; j < currPos; j++) {
            auto currN = A[ j ] ;
            Del[currN]--;
            Count[currN].update( j, -1);
            Pos[ currN ].pop_front();
        }
        ans.push_back(n);
        Pos[ n ].pop_front();
        s = currPos + 1;
    }
    for (auto n: ans ) cout << n ;
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


