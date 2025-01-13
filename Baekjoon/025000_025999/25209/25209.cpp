#include <bits/stdc++.h>
using namespace std;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};
void init(){
}
struct BLOCK {
    int type=0;
    int num=-1;
};
void parse(vector<string> &S, int y, int x, BLOCK &b) {
    bool lt, rt, lb, rb;
    lt = S[y][x] == '#';
    rt = S[y][x+2] == '#';
    lb = S[y+2][x] == '#';
    rb = S[y+2][x+2] == '#';
    if ( lt && rt && lb && rb ) b.type = 1;
    else if ( lt && !rt && lb && rb ) b.type = 2;
    else if ( lt && rt && !lb && rb ) b.type = 3;
    else if ( lt && rt && lb && !rb ) b.type = 4;
    else if ( !lt && rt && lb && rb ) b.type = 5;
    else b.type = 0;
    if ( S[y+1][x+1] - '0' >= 0  ) b.num = S[y+1][x+1] - '0';
}
void process(int Case) {
    int W, H;
    int i, j, k, d, ty, tx, cnt;
    cin >> H >> W ;
    vector<string> S(3*H);
    vector A(H, vector<BLOCK>(W));

    for (auto &s: S) cin >> s;

    for ( i = 0 ; i < H ; i ++ )
        for ( j = 0 ; j < W ; j ++ )
            parse(S, i*3, j*3, A[i][j]);

    for ( i = 0 ; i < H ; i ++ ) {
        for (j = 0; j < W; j++) {
            if ( A[i][j].num >= 0 ) {
                cnt = 0;
                for ( d = 0 ; d < 4 ; d ++ ) {
                    ty = i + dy[d];
                    tx = j + dx[d];
                    if ( ty < 0 || ty >= H || tx < 0 || tx >= W ) continue;
                    if ( A[ty][tx].type >= 2 ) cnt ++ ;
                }
                if ( A[i][j].num != cnt ) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
