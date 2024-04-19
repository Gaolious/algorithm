#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int A[3][3]={0,};
int RED = 1;
int BLUE = 2;
int X=3, Y=3;
int dfs(int pos) {
    int y = pos / X ;
    int x = pos % X ;
    int ret = 0 ;
    int i, j ;
    if ( y >= Y ) {
        int row[3][3]={0,};
        int col[3][3]={0,};
        for ( i = 0 ; i < Y ; i ++ ) {
            for ( j = 0 ; j < X ; j ++ ) {
                row[i][ A[i][j] ] ++;
                col[j][ A[i][j] ] ++;
            }
        }
        for ( i = 0 ; i < Y ; i ++ )
            for ( j = 0 ; j < X ; j ++ ) {
                if ( row[i][1] * col[j][1] == 9 ) return 0 ;
                if ( row[i][2] * col[j][2] == 9 ) return 0 ;
            }

        for ( i = 0 ; i < Y ; i ++ ) {
            for (j = 0; j < X; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return 1 ;
    }
    A[y][x] = RED ;
    ret += dfs(pos+1);
    A[y][x] = BLUE ;
    ret += dfs(pos+1);
    return ret ;
}
void process() {
    fastio;
    cout << dfs(0) << endl;
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


