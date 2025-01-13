#include <bits/stdc++.h>
using namespace std;
void init() {}


struct Data {
    int depth;
    string name;
};
struct solution {
    vector<int> Length;
    vector<string> A;
    vector<Data> Tree;
    vector<string> ans;
    int base;
    int N, H;

    solution(int N) : N(N) {}
    void input() {
        A.resize(N);
        for (auto &s: A) cin >> s;

        H = ceil( log2(N) );
        Length.resize(H);
        base = 1 << int( H );
        Tree.resize( base , {-1, ""});

        ans.resize(base+1, string(base + 7 * H + 1, ' '));
    }
    void dump(){
#ifdef AJAVA_DEBUG
        int width = 7, prevW;
//        int h = H - 1;
        queue<pair<int,int>> Q[2];
        int turn = 0, w;

        w = ( 1 << ( H - 1 ))*width ;
        Q[turn].emplace(1, w );
        for ( int i = 1 ; i <= H ; i ++, turn = 1 - turn, w/=2 ) {
            prevW = 0;
            while (!Q[turn].empty()) {
                auto [idx, pos] = Q[turn].front();
                Q[turn].pop();
                if ( prevW < pos )
                    cout << setw(pos - prevW) << ' ';
                cout << setw(width) << Tree[idx].name;

                Q[1-turn].emplace(idx*2, pos - w/2  );
                Q[1-turn].emplace(idx*2+1, pos + w/2 );
                prevW = pos + width;
            }
            cout << endl;
        }
#endif
    }
    void genTree() {
        unordered_map<string, int> M;

        M[A.back()] = 1;
        Tree[1].name = A.back();
        A.pop_back();

        while ( A.size() > 0 ) {
            auto dn = A.back(); A.pop_back();
            auto up = A.back(); A.pop_back();

            int treeIdx = -1;
            if( M.count(dn) ) treeIdx = M[dn];
            else if ( M.count(up)) treeIdx = M[up];

            if ( treeIdx < 0 ) continue;

            Tree[ treeIdx * 2 + 0].name = up;
            Tree[ treeIdx * 2 + 1].name = dn;
            M[up] = treeIdx * 2;
            M[dn] = treeIdx * 2 + 1;
        }
    }
    void updateDepth() {
        int i, j, cnt;

        for ( i = 1, cnt=1 ; i <= H ; i ++, cnt*=2) {
            for ( j = cnt ; j < 2*cnt ; j ++ ) {
                Tree[j].depth = i ;
                Length[H-i] = max(Length[H-i], (int)Tree[j].name.size() + 2);
            }
        }
    }
    void drawString(int y, int x, int width, char blank, string &s) {
        int padding2 = width - s.size() - 1;
        ans[y][x++] = '_';
        for (auto c: s) ans[y][x++] = c;
        for ( ; padding2 > 0 ; padding2--) ans[y][x++] = blank;
    }
    void drawString(int y, int x, int width, char blank, int num) {
        stringstream  ss ;
        ss << num ;
        auto ret = ss.str();
        return drawString(y, x, width, blank, ret);
    }
    void drawDiagnal(int treeIndex, int y, int x, int size) {
        int i ;
        for ( i = 0 ; i < size ; i ++ ) {
            if ( !Tree[treeIndex*2].name.empty())
                ans[y-i][x-i-1] = '\\';
            if ( !Tree[treeIndex*2+1].name.empty())
                ans[y+i+1][x-i-1] = '/';
        }
    }
    void run() {
        int i, j, y, x, start, cnt, offset, interval;
        input();
        genTree();

//        dump();

        updateDepth();

        cnt = base / 2;
        offset = 0;
        interval = 2;
        x = 0;
        y = 0;
        for (i = 0; i < H; i++, cnt /= 2, interval*=2) {
            y = interval/2;
            for (j = cnt; j < cnt * 2; j++, y += interval ) {
                if (Tree[j].name.empty()) continue;

                if ( i ) drawDiagnal(j, y, x, interval/4);

                drawString(y, x, Length[i], '_', Tree[j].name);
            }
            x += Length[i] + (1<<i);
        }

        for (auto &s: ans) {
            while (!s.empty() && s.back() == ' ') s.pop_back();
        }
        while ( ans.back().empty() ) ans.pop_back();

        for (i=0 ; i < ans.size() && ans[i].empty() ; i ++);
        for (; i <ans.size() ; i ++ )
            cout << ans[i] << '\n';
    }
};
bool process(int Case) {
    int i, N;
    cin >> N;
    if ( N < 0 ) return false;
    cout << "Tournament " << Case << '\n';
    solution sol(N);
    sol.run();
    return true;
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	init();
    for ( int i = 1 ; process(i) ; i ++ ) ;
    return 0;
}
