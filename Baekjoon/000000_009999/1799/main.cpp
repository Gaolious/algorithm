#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define DU(y,x) ( (x) + (y) )
#define DD(y,x) ( (x) + (N-1) - (y) )

int Board[10][10];
int N ;
bool DiagUp[20];
bool DiagDown[20];
//int nDU, nDD;
int best ;

//int dy[] = {1, 1, -1, -1};
//int dx[] = {1, -1, 1, -1};
void dump() {
#ifdef AJAVA_DEBUG
    int i, j ;
    printf("\n");
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            if ( Board[i][j] == 0 )
                printf(" - ");
            else if ( Board[i][j] == 1 )
                printf(" ? ");
            else if ( Board[i][j] < 0 )
                printf(" B ");
            else
                printf(" ! ");
        }
        printf("\n");
    }
#endif
}
void setXY(int y, int x, int depth){
    DiagDown[ DD(y, x) ] = false;
    DiagUp[ DU(y, x) ] = false;
    Board[y][x] = 0;
}

void unsetXY(int y, int x, int depth) {
    DiagDown[ DD(y, x) ] = true;
    DiagUp[ DU(y, x) ] = true;
    Board[y][x] = 1;
}

void dfs(int depth, int pos, int cnt, int c) {
    int x, y;
    for ( ; pos < N*N ; pos ++){
        y = pos / N ;
        x = pos % N ;
        if ( ( x + y ) % 2 != c ) continue;
        if (!DiagUp[DU(y, x)]) continue;
        if (!DiagDown[DD(y, x)]) continue;
        if ( Board[ pos / N ][ pos % N ] != 1 ) continue;

        break;
    }
    y = pos / N ;
    x = pos % N ;
    if ( y >= N ) {
        best = max(best, cnt);
        return ;
    }
    int c1, c2 ;
    c1 = c2 = 0 ;
    for ( int i = 0 ; i < 2*N - 1 ; i ++ ){
        if ( DiagUp[i] ) c1 ++;
        if ( DiagDown[i] ) c2 ++;
    }
    if ( cnt + min(c1,c2) <= best ) return ;

    setXY(y, x, depth);
    dump();
    dfs(depth+1, pos + 1, cnt+1, c);
    unsetXY(y, x, depth);
    dfs(depth+1, pos + 2, cnt, c);
}
void process() {
    fastio;
    int i, j ;

    cin >> N ;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            cin >> Board[i][j] ;

    for ( i = 0 ; i < N ; i ++ )
        for ( j = 0 ; j < N ; j ++ )
            if ( Board[i][j] ) {
                DiagDown[DD(i,j)] = true ;
                DiagUp[DU(i,j)] = true ;
            }

    int ret = 0 ;
    best = 0 ;
    dfs(1, 0, 0, 0);
    ret += best ;
    best = 0 ;
    dfs(1, 0, 0, 1);
    ret += best ;

    cout << ret << endl ;
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


