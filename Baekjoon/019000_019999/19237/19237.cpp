#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
pair<int, int> Smell[20][20]; // idx, time
int A[20][20]; // idx, time
string CharDir[] = {"↑", "↓","←","→"};
int RemainShark ;
int N, M, K;

bool invalid(int y, int x) {
    return ( y < 0 || x < 0 || y >= N || x >= N ) ;
}
struct Data {
    int no;
    int y, x;
    int currDir ;
    bool isDead;
    int dir[4][4];
    void addSmell() {
        if ( isDead ) return ;
        Smell[y][x] = { no, K};
    }
    void Move() {
        int i, d;
        int ty, tx;
        if ( isDead ) return ;

        for ( i = 0 ; i < 4 ; i ++ ) {
            ty = y + dy[dir[currDir][i]];
            tx = x + dx[dir[currDir][i]];
            if ( invalid(ty, tx) ) continue;
            if ( Smell[ty][tx].second > 0 ) continue;

            if (A[ty][tx] != -1 ) {
                isDead = true;
                RemainShark --;
                return;
            }
            A[ty][tx] = no;
            currDir = dir[currDir][i];
            y = ty, x = tx;
            return;
        }

        for ( i = 0 ; i < 4 ; i ++ ) {
            ty = y + dy[dir[currDir][i]];
            tx = x + dx[dir[currDir][i]];
            if ( invalid(ty, tx) ) continue;

            if ( Smell[ty][tx].first != no ) continue;
            Smell[ty][tx] = { no, K};
            A[ty][tx] = no;
            currDir = dir[currDir][i];
            y = ty, x = tx;
            return;
        }
    }
};
Data D[401]={0,};

void ReduceSmellTime() {
    int i, j;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( Smell[i][j].second > 0 ) {
                if ( --Smell[i][j].second == 0 ) {
                    Smell[i][j] = {-1, -1};
                }
            }
        }
    }
}

void Dump(int t) {
    int i, j, n, k;

    for ( i = 0 ; i < 30 ; i ++ ) cout << '-';
    cout << '\n';
    cout << "Time = " << t << " / Dir \n";
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( (n=A[i][j]) >= 0 )
                cout << n + 1 << CharDir[ D[n].currDir ] << ' ';
            else
                cout << " . ";
            cout << ' ';
        }
        cout << '\n';
    }
    cout << "Time = " << t << " / Smell \n";
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( Smell[i][j].second > 0 )
                cout << Smell[i][j].first+1 << '/' << Smell[i][j].second ;
            else
                cout << " . ";
            cout << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}


int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, n, t ;

    cin >> N >> M >> K ;

    RemainShark = M ;
    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> n;
            Smell[i][j] = {-1, -1};

            if ( n > 0 ) {
                n --;
                D[n].y = i, D[n].x = j ;
                D[n].isDead = false;
                D[n].no = n;
            }
        }

    for ( i = 0 ; i < M ; i ++ ) {
        cin >> D[i].currDir;
        D[i].currDir--;
    }

    for ( i = 0 ; i < M ; i ++ )
        for ( j = 0 ; j < 4 ; j ++ )
            for ( int k = 0 ; k < 4 ; k ++ ) {
                cin >> D[i].dir[j][k];
                D[i].dir[j][k]--;
            }

    for ( t = 0 ; t <= 1000 ; t ++ ) {
        // Dump(t);
        if ( RemainShark == 1 ) {
            cout << t << '\n';
            return 0;
        }

        memset(A, -1, sizeof(A));
        ReduceSmellTime();
        for ( i = 0 ; i < M ; i ++ ) D[i].addSmell();
        for ( i = 0 ; i < M ; i ++ ) D[i].Move();
    }
    cout << "-1\n";

    return 0;
}


