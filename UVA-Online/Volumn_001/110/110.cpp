// 110. Meta-Loopless Sorts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR (8)

char fixed[ MAX_CHAR + 1 ]={0,};
char variables[ MAX_CHAR + 1 ]={0,};


void join( const char *str, char arr[], int size )
{
    int i ;
    
    for ( i = 0 ; i < size; i ++)
    {
        if ( i != 0 ) printf("%s", str);
        printf("%c", arr[i]);
    }
}
void print_tab( int index )
{
    for ( int i = 0 ; i < index ; i ++)
        printf("  ");
}


/**
 * n=3
 *  1   2
 *      2   3       1   2   3
 *      1   3       1   3   2
 *      else        3   1   2
 * 
 *  else
 *      1   3       2   1   3
 *      2   3       2   3   1
 *      else        3   2   1
 * 
 *  [1,                                     0   
 *  
 *  1   2               [1, 2,                  1
 *      2   3           [1, 2, 3,                   2
 *          3   4       1   2   3   4                   3
 *          2   4       1   2   4   3                   3
 *          1   4       1   4   2   3                   3
 *          else        4   1   2   3                   3
 * 
 *      1   3           [1, 3, 2,                   2
 *          2   4       1   3   2   4
 *          3   4       1   3   4   2
 *          1   4       1   4   3   2
 *          else        4   1   3   2
 * 
 *      else            [3, 1, 2,
 *          2   4       3   1   2   4
 *          1   4       3   1   4   2
 *          3   4       3   4   1   2
 *          else        4   3   1   2
 * 
 * else                 [2, 1,
 *      1   3           [2, 1, 3,
 *          3   4       2   1   3   4
 *          1   4       2   1   4   3
 *          2   4       2   4   1   3
 *          else        4   2   1   3
 * 
 *      2   3           [2, 3, 1,
 *          1   4       2   3   1   4
 *          3   4       2   3   4   1
 *          2   4       2   4   3   1
 *          else        4   2   3   1
 * 
 *      else            [3, 2, 1,
 *          1   4       3   2   1   4
 *          2   4       3   2   4   1
 *          3   4       3   4   2   1
 *          else        4   3   2   1
 * 
 */

void print_sort( int index, int size)
{
    if ( index >= size  )
    {
        print_tab(index);
        printf("writeln(");
        join( ",", fixed, size);
        printf(")\n");
        return;
    }
    int i;

    fixed[ index ] = variables[ index ];  
    if ( index > 0 )
    {
        print_tab( index);
        printf("if %c < %c then\n", fixed[ index - 1 ], fixed[ index ]);
    }
    
    print_sort( index + 1 , size);
    
    for (i = index-1 ; i >= 0 ; i --)
    {
        print_tab( index);
        if ( i > 0 )
            printf("else if %c < %c then\n", fixed[ i - 1 ], fixed[ i + 1 ] );
        else
            printf("else\n");
        
        fixed[ i + 1 ] = fixed[ i ];
        fixed[ i ] = variables[ index ];
        
        print_sort( index + 1 , size);
    }
    for ( i = 0 ; i < index ; i ++)
        fixed[ i ] = fixed[ i + 1 ];
        
/*
 *  1   2               [1, 2,                  1
 *      2   3           [1, 2, 3,                   2
 *          3   4       1   2   3   4                   3
 *          2   4       1   2   4   3                   3
 *          1   4       1   4   2   3                   3
 *          else        4   1   2   3                   3
 * 
 *      1   3           [1, 3, 2,                   2
 *          2   4       1   3   2   4
 *          3   4       1   3   4   2
 *          1   4       1   4   3   2
 *          else        4   1   3   2
*/    
}

void print_codes( int n )
{
    int i;

    memset( variables, 0x00, sizeof(variables));
    memset( fixed , 0x00, sizeof(fixed));
    
    for ( i = 0 ; i < n ; i ++)
        variables[ i ] = 'a' + i ;
    
    printf("program sort(input,output);\n");
    printf("var\n");
    join(",", variables, n); printf(" : integer;\n");
    printf("begin\n");
        print_tab(1);printf("readln("); join(",", variables, n); printf(");\n");
    print_sort( 0, n);
    printf("end.\n");
}

void process( FILE *fp )
{
    int n, m;
    int i = 0 ;
    
    if ( fscanf(fp, "%d", &n ) != 1 )
        return;
    
    for ( i = 0 ; i < n ; i ++)
    {
        if ( fscanf(fp, "%d", &m) == 1 )
        {
            if ( i > 0 ) printf("\n");
            print_codes( m );
        }
    }
}


int main()
{
#ifdef ONLINE_JUDGE 
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif

    process(fp);

#ifdef ONLINE_JUDGE 
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
