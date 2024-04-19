#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int N, M, K;
int A[10][10]; // 현재 영양분
int B[10][10]; // 추가 영양분
deque<int> T[10][10];
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = { 1, 0, -1, -1, -1, 0, 1, 1};

void spring_and_summer() {
    int i, j, cnt;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cnt = 0 ;
            for ( auto &curr : T[i][j] ) {
                if ( A[i][j] < curr )
                    break;
                A[i][j] -= curr++;
                cnt++;
            }
            while ( T[i][j].size() > cnt ) {
                A[i][j] += T[i][j].back() / 2 ;
                T[i][j].pop_back();
            }
        }
    }
}

void autumn_and_winter() {
    int d, ty, tx;
    int i, j;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            for ( auto curr = T[i][j].begin() ; curr != T[i][j].end() ; curr ++ ) {
                if ( *curr % 5 != 0 ) continue;

                for (d = 0 ; d < 8 ; d ++ ) {
                    ty = i + dy[d];
                    tx = j + dx[d];
                    if ( ty < 0 || tx < 0 || ty >= N || tx >= N ) continue;
                    T[ty][tx].push_front(1);
                }
            }
            A[i][j] += B[i][j];
        }
    }

}
void dump() {
    int i, j;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            for (auto curr : T[i][j]) {
                cout << i << ' ' << j << ' ' << curr << '\n';
            }
        }
    }
    cout << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j;
    int x, y, z;

    cin >> N >> M >> K;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> B[j][i];
            A[i][j] = 5;
        }
    }
    for ( i = 0 ; i < M ; i ++ ) {
        cin >> x >> y >> z;
        T[y-1][x-1].push_back(z);
    }
    // dump();

    for ( i = 0 ; i < K ; i ++ ) {
        spring_and_summer();
        autumn_and_winter();
        // cout << "After Autumn & Winter Year=" << i << '\n';
        // dump();
    }

    int ans = 0;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            ans += T[i][j].size();

    cout << ans << '\n';
    return 0;
}


