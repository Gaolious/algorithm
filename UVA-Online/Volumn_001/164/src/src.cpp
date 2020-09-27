#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (100)

int min( int a, int b )
{
    if ( a < b ) return a ;
    else return b ;
}
int min( int a, int b, int c )
{
    if ( a < min(b,c) ) return true ;
    else return false ;
}

int D[MAX+1][MAX+1]={0,};
int P[MAX+1][MAX+1]={0,};

char A[MAX+1]={0,};
char B[MAX+1]={0,};

void recur(int i, int j, int &lenA, int &lenB)
{
    int a ;

    switch ( P[i][j] )
    {
        case 1:
            recur(i-1, j-1, lenA, lenB);
            lenA ++;
            lenB ++;
            break;
        case 2:
            // replace
            recur(i-1, j-1, lenA, lenB);
            printf("C%1c%02d", B[j-1], lenA++);
            break;            
        case 3:
            // delete
            recur(i-1, j, lenA, lenB);
            printf("D%1c%02d", A[i-1], lenA);
            break;
        case 4: 
            // add
            recur(i, j-1, lenA, lenB);
            printf("I%1c%02d", B[j-1], lenA++);
            break;
    }
}

void process()
{
    int i, j ; 
    int lenA, lenB ;

    while ( scanf("%s ", A) == 1 && A[0] != '#' && scanf("%s ", B) == 1 )
    {
        lenA = strlen(A);
        lenB = strlen(B);
        for ( i = 0 ; i <= lenA+1 ; i ++ )
        for ( j = 0 ; j <= lenB+1 ; j ++ )
            D[i][j] = 99;
        D[ 0 ][ 0 ] = 0 ;

        for ( i = 0 ; i <= lenA ; i ++ )
        {
            for ( j = 0 ; j <= lenB ; j ++ )
            {
                if ( D[i][j] < D[i+1][j+1] && A[i] == B[j])
                {
                    D[i+1][j+1] = D[i][j] ; 
                    P[i+1][j+1] = 1 ;
                }
                if ( D[i][j] + 1 < D[i][j+1]) // insert
                {
                    D[i][j+1] = D[i][j]+1;
                    P[i][j+1] = 4 ;
                }
                if ( D[i][j] + 1 < D[i+1][j+1] ) // change
                {
                    D[i+1][j+1] = D[i][j] +1; 
                    P[i+1][j+1] = 2 ;
                }
                if ( D[i][j] + 1 < D[i+1][j] ) // delete
                {
                    D[i+1][j] = D[i][j]+1;
                    P[i+1][j] = 3 ;
                }
            }
        }
    

// #ifdef AJAVA_DEBUG
//         printf("%5s", "");
//         for ( j = 0 ; j <= lenB ; j ++ )
//             printf("%2c    ", j == 0 ? ' ' : B[j-1] );
//         printf("\n");
//         for ( i = 0 ; i <= lenA ; i ++ )
//         {
//             printf("%2c : ", i == 0 ? ' ' : A[i-1] );

//             for ( j = 0 ; j <= lenB ; j ++ )
//                 printf("%2d(%1d) ", D[i][j], P[i][j]);
//             printf("\n");
//         }
// #endif

        int a = 1, b = 0;
        recur(lenA, lenB, a, b);
        printf("E\n");
    }
}
int main() 
{
    process();     

    return 0;
}

