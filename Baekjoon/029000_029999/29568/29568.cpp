#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
using Pt = pair<int, int>;

int Y, X;
int dy[] = { 0, 1, 0, -1};
int dx[] = { 1, 0, -1, 0};

void init(){
}
pair<Pt, int> GetPos(vector<string> &A) {
    int i, j;
    for (i = 0; i < Y; i++) {
        for (j = 0; j < X; j++) {
            if (A[i][j] == '-') {
                if (j > 0) {
                    if (A[i][j - 1] == '/') return {{i, j}, 1};
                    if (A[i][j - 1] == '\\') return {{i, j}, 3};
                }
            } else if (A[i][j] == '|') {
                if (i > 0) {
                    if (A[i - 1][j] == '/') return {{i, j}, 0};
                    if (A[i - 1][j] == '\\') return {{i, j}, 2};
                }
            }
        }
    }
    return { {0,0}, -1};
}

struct Data {
    Pt p;
    int dir;
    int step;
};
bool validPos(vector<string> &A, int ty, int tx) {
    if ( ty < 0 || ty >= Y || tx < 0 || tx >= X )
        return false;
    if ( A[ty][tx] == '*' ) return false;
    return true;
}
void process(int Case) {
    int i, d, ty, tx;
    cin >> Y >> X ;
    vector<string> A(Y), B(Y);
    for (auto &s: A) cin >> s ;
    for (auto &s: B) cin >> s ;
    auto [sp, sd] = GetPos(A);
    auto [ep, ed] = GetPos(B);

    vector D(4, vector(Y, vector(X, -1)));
    D[sd][sp.first][sp.second] = 0;
    queue<Data> Q;
    Q.push({sp, sd, 0});

    while ( !Q.empty() ) {
        auto [cp, cd, step] = Q.front();
        Q.pop();

        for (d = 0 ; d < 4 ; d ++ ) {
            ty = cp.first;
            tx = cp.second;
            if ( d == cd ) {
                ty += dy[d];
                tx += dx[d];
            }
            if ( !validPos(A, ty,tx) ) continue;
            if ( !validPos(A, ty + dy[(d+3)%4],tx + dx[(d+3)%4]) ) continue;
            if ( !validPos(A, ty + dy[(d+1)%4],tx + dx[(d+1)%4]) ) continue;

            if ( D[d][ty][tx] < 0 || D[d][ty][tx] > step+1 ) {
                D[d][ty][tx] = step+1;
                Q.push({{ty,tx}, d, step+1});
            }
        }
    }

    cout << D[ed][ep.first][ep.second] << '\n';
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
