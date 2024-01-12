#include <bits/stdc++.h>
using namespace std;

int A[5][5]={0,};
int Check[25+1]={0,};
int matrix[25+1][25+1]; // matrix[ from ][ to ], from: number, to=y,x
bool visited[25+1];
int partner[25+1];
bool fixed_number[25 + 1];
void dump() {
    int i, j ;
    printf("\n");
    for ( i = 0 ; i < 5 ; i ++ ) {
        for ( j = 0 ; j < 5 ; j ++ ) {
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }
}

void dump_matrix() {
    int i, j, s, e, k, c, idx ;
    printf("\n");
    for ( i = 0 ; i < 5 ; i ++ ) {
        for ( j = 0 ; j < 5 ; j ++ ) {
            char str[100]={0,};

            s = 99, e =0, c= 0;

            idx=0;
            for ( k = 1 ; k <= 25 ; k ++ )
                if ( matrix[k][i*5+j+1] > 0 )
                    idx+= sprintf(str+idx, "%d,", k);
            printf("[%d,%d]:%20s|", i,j,str);
        }
        printf("\n");
    }
}


bool dfs(int from) {
    if (visited[from]) return false;
    visited[from] = true;
    for (int to = 1; to <= 25; to++) {
        if (matrix[from][to] > 0) {
            if (partner[to] == -1 || dfs(partner[to])) {
                partner[to] = from;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    int ret = 0;
    int i, j ;
    for (i = 1; i <= 25; i++) {
        partner[i] = -1;
    }
    for (i = 1; i <= 25; i++) {
        for (j=1 ; j<=25 ; j++ )
            visited[j] = fixed_number[j];

        if (dfs(i)) ret++;
    }
    return ret;
}

void set_fix(int i, int j, int n) {
    int x, y;
    int k, from, to ;

    to = i*5 + j + 1 ;
    for ( k = 1 ; k <= 25 ; k ++ )
    {
        matrix[ n ][ k ] = 0;
        matrix[ k ][ to ] = 0;
    }

    for ( x=0 ; x < j ; x ++ )
    {
        for ( from = n - (j-x) + 1 ; from <= 25 ; from ++ )
        {
            to = i*5+x+1;
            matrix[from][to] = 0;
        }
    }

    for ( x=j+1 ; x < 5 ; x ++ )
    {
        for ( from = A[i][j] - (j-x) -1 ; from >= 1 ; from -- )
        {
            to = i*5+x+1;
            matrix[from][to] = 0;
        }
    }

}

bool set_matrix(int idx, int remain) {

    int i, j, num ;
    int y, x ;

    while ( idx < 25 && A[ idx / 5 ][ idx % 5 ] > 0 ) idx ++;
    if ( idx >= 25 )
        return true ;

    y = idx / 5 ;
    x = idx % 5 ;

    for ( i = 1 ; i <= 25 ; i ++ ) {
        if ( fixed_number[i] ) continue;

        if ( matrix[ i ][ idx + 1 ] != 1 )
            continue;

        int tmp[25+1][25+1];
        memcpy(tmp, matrix, sizeof(matrix));

        set_fix(y, x, i);
        if ( bipartiteMatch() == remain -1 ) {
            A[y][x] = i;
            fixed_number[ i ] = true ;
            if ( set_matrix(idx+1, remain-1) )
                return true ;
            fixed_number[ i ] = false ;
            A[y][x] = 0;
        }

        memcpy(matrix, tmp, sizeof(matrix));
    }
    return false ;
}

void process() {

    int i, j;
    int fixed = 0, remain;

    for ( i = 1 ; i <= 25 ; i ++ )
        for ( j = 1 ; j <= 25 ; j ++ )
            matrix[i][j] = ( ( (j-1) % 5)+1 <= i && i-1 + (5 - (j-1)%5) <= 25 ) ? 1 : 0;

    for ( i = 0 ; i < 5 ; i ++ ) {
        for (j = 0; j < 5; j++) {
            scanf("%d ", &A[i][j]);
            if ( A[i][j] > 0 ) {
                fixed++;
                fixed_number[ A[i][j] ] = true ;
                set_fix(i, j, A[i][j]);
            }
        }
    }
    remain = 25 - fixed ;

    if( bipartiteMatch() != remain || ! set_matrix(0, remain)  ){
        printf("-1\n");
    } else {

        for ( i = 0 ; i < 5 ; i ++ ) {
            for (j = 0; j < 5; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
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


