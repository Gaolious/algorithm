#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

char A[20][20];
bool Visited[20][20];
int Y, X;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
struct Data {
    vector<pair<int, int>> blank_pos;
    vector<pair<int, int>> near_stones;
    int size;
    int getCount() {
        int d, ty, tx;
        for (auto [y, x] : near_stones) {
            for ( d = 0 ; d < 4 ; d ++ ) {
                ty = y + dy[d];
                tx = x + dx[d];
                if ( ty < 0 || tx < 0 || tx >= X || ty >= Y ) continue;
                if ( A[ty][tx] == '0') return 0;
            }
        }
        return size;
    }

};
vector<Data> Possibles[3];

void bfs() {
    int i, j, d, ty, tx ;
    int cnt;

    for (i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( Visited[i][j] || A[i][j] != '2' ) continue;
            queue< pair<int, int> > Q;
            vector<pair<int,int>> B, Near;

            Q.emplace(i, j);
            Visited[i][j] = true;
            cnt = 0 ;

            while ( !Q.empty() ) {
                auto [y, x] = Q.front();
                cnt++;
                Q.pop();
                for ( d = 0 ; d < 4 ; d ++ ) {
                    ty = y + dy[d];
                    tx = x + dx[d];
                    if ( ty < 0 || tx < 0 || tx >= X || ty >= Y ) continue;
                    if ( Visited[ty][tx] ) continue;
                    if ( A[ty][tx] == '0') {
                        B.emplace_back(ty, tx);
                        Near.emplace_back(y, x);
                    }
                    if ( A[ty][tx] == '2' ) {
                        Visited[ty][tx] = true;
                        Q.emplace(ty, tx);
                    }
                }
            }
            sort(B.begin(), B.end());
            B.erase(unique(B.begin(), B.end()), B.end());

            sort(Near.begin(), Near.end());
            Near.erase(unique(Near.begin(), Near.end()), Near.end());

            if ( B.size() <= 2 )
                Possibles[B.size()].push_back({B, Near, cnt});
        }
    }
}

int calc2() {
    int ret = 0, cnt ;
    for (auto p: Possibles[2]) {
        cnt = 0 ;
        for (auto [y,x]: p.blank_pos ) A[y][x] = '1';
        for (auto o: Possibles[2]) cnt += o.getCount();
        for (auto o: Possibles[1]) cnt += o.getCount();
        for (auto [y,x]: p.blank_pos ) A[y][x] = '0';

        ret = max(ret, cnt);
    }
    return ret;
}
int calc1() {
    int ret = 0, cnt ;
    int len = Possibles[1].size();
    int i, j;

    for ( i = 0 ; i < len ; i ++ ) {
        auto &p1 = Possibles[1][i];

        for (auto [y,x]: p1.blank_pos ) A[y][x] = '1';

        cnt = 0;
        for (auto o: Possibles[2]) cnt += o.getCount();
        for (auto o: Possibles[1]) cnt += o.getCount();
        ret = max(ret, cnt);


        for ( j = i + 1 ; j < len ; j ++ ) {
            auto &p2 = Possibles[1][j];

            for (auto [y,x]: p2.blank_pos ) A[y][x] = '1';

            cnt = 0;
            for (auto o: Possibles[2]) cnt += o.getCount();
            for (auto o: Possibles[1]) cnt += o.getCount();
            ret = max(ret, cnt);

            for (auto [y,x]: p2.blank_pos ) A[y][x] = '0';
        }

        for (auto [y,x]: p1.blank_pos ) A[y][x] = '0';
    }
    return ret;
}
int calc0() {
    int ret = 0 ;
    for (auto p: Possibles[0]) ret += p.size;
    return ret;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int ret = 0 ;

    int i, j;
    cin >> Y >> X;
    for (i = 0 ; i < Y ; i ++ )
        for ( j = 0 ; j < X ; j ++ )
            cin >> A[i][j];
    bfs();
    cout << calc0() + max(calc1(), calc2());
    return 0;
}


