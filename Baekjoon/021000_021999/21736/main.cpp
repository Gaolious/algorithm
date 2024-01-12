#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    fastio;
    int N, M ;
    int x, y, tx, ty, i;
    int ret;

    cin >> N >> M ;
    vector<string> A(N);
    queue<pair<int,int>> Q;
    y = 0;
    for (auto &s : A) {
        cin >> s ;
        for (x=0 ; x < M ; x++)
            if ( s[x] == 'I') {
                Q.emplace(y, x);
                s[x] = 'X';
            }
        y++;
    }

    ret = 0;

    while (!Q.empty()) {
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();
        for (i=0 ; i < 4 ; i ++ ) {
            ty = y + dy[i];
            tx = x + dx[i];
            if ( ty < 0 || ty >= N || tx < 0 || tx >= M) continue;
            if ( A[ty][tx] == 'X' ) continue;
            if ( A[ty][tx] == 'P' ) ret++;
            A[ty][tx] = 'X';
            Q.emplace(ty, tx);
        }
    }
    if ( ret > 0 ) cout << ret << "\n";
    else cout << "TT\n";

    return 0;
}


