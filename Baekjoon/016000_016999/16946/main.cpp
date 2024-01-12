#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int X, Y ;
int M[1'001][1'001]={0,};
char visited[1'000][1'000]={0,};
int C[1'000'000+1]={0,};
int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

void setGroupCount(int sy, int sx, int nGroup ) {
    int d ;
    int tx, ty;

    queue< pair<int, int> > Q ;
    Q.emplace(sy, sx);
    visited[sy][sx] = 1;

    while ( !Q.empty() ) {
        auto p = Q.front();
        Q.pop();
        auto y = p.first;
        auto x = p.second;
        C[nGroup]++;
        M[y][x] = -nGroup;

        for ( d = 0 ; d < 4 ; d ++ ) {
            ty = y + dy[d];
            tx = x + dx[d];
            if ( ty < 0 || ty >= Y || tx < 0 || tx >= X ) continue;
            if ( visited[ty][tx] == 1 ) continue;
            if ( M[ty][tx] != 0) continue;
            Q.emplace(ty, tx);
            visited[ty][tx] = 1;
        }
    }
}
void process() {
    fastio;
    int i, j, cnt=0, nGroup = 0 ;
    char c ;
    string s ;
    cin >> Y >> X ;
    for ( i = 0 ; i < Y ; i ++ ) {
        cin >> s;
        for (j = 0; j < X; j++) {
            M[i][j] = s[j] - '0';
        }
    }

    for ( i = 0 ; i < Y ; i ++ ) {
        for ( j = 0 ; j < X ; j ++ ) {
            if ( M[i][j] == 0 && visited[i][j] == 0) {
                setGroupCount(i, j, ++nGroup);
            }
        }
    }
//    for ( i = 1 ; i <=nGroup ; i ++ ) {
//        cout << "group " << i << " : " << C[i] << '\n';
//    }
//    cout <<" M : " << '\n';
//    for ( i = 0 ; i < Y ; i ++ ) {
//        for (j = 0; j < X; j++) {
//            cout << M[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';

    int d, tx, ty ;
    for ( i = 0 ; i < Y ; i ++ ) {
        for (j = 0; j < X; j++) {
            cnt = 0;
            if ( M[i][j] == 1)
            {
                set<int> tmp;
                for ( d = 0 ; d < 4 ; d ++ ) {
                    ty = i + dy[d];
                    tx = j + dx[d];
                    if ( ty < 0 || ty >= Y || tx < 0 || tx >= X ) continue;
                    if (M[ty][tx] >= 0 ) continue;
                    tmp.insert(-M[ty][tx]);
                }
                for ( auto idx: tmp) {
                    cnt += C[ idx ];
                }
                cnt ++;
            }
            cout << cnt % 10 ;
        }
        cout << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


