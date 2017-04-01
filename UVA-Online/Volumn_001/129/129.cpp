// 129 Krypton Factor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH (80)

int curr ;
int n, L;

int is_diff( char str[], int s1, int e1, int s2, int e2)
{
    if ( s1 >= 0 && s1 <= e1 && s2 >= 0 && s2 <= e2 )
    {
        for ( ; s1 < e1 && s2 < e2 ; s1++, s2++)
        {
            if ( str[s1] != str[s2] ) return 1;
        }
        
        if ( s1 == e1 && s2 == e2 )
            return 0;
    }
    return 1;
}

int gen_possibles( char str[], int len, char possibles[])
{
    int len_loop;
    char tmp[26]={0,};
    
    for ( len_loop = 0 ; len_loop*2 <= len ; len_loop ++)
    {
        int s1, e1, s2, e2 ;
        // 0 1 2 3 4 5 6 ?
        //             [][]
        // 0 1 2 3 4 5 6 ?
        //         [ ] [ ]
        // 0 1 2 3 4 5 6 ?
        //     [   ] [   ]
        e2 = len;
        s2 = e2 - len_loop ;
        
        e1 = s2 - 1 ;
        s1 = e1-len_loop;
            
        if ( e2 < 0 || s2 < 0 || s1 < 0 || e1 < 0 ) continue ;
        if ( tmp[ str[e1] - 'A' ] == 1 ) continue ;
        
        if ( is_diff(str, s1, e1, s2, e2) == 0 )
            tmp[ str[e1] - 'A' ] = 1 ;
    }
    
    int nPossibles = 0 ;
    for ( int i = 0 ; i < L ; i ++ )
        if ( tmp[i] == 0 ) possibles[ nPossibles ++ ] = i + 'A' ;
    
    return nPossibles;
}

int recur( char str[], int len)
{
    if ( curr == n )
    {
        int i, j;
        for ( i = 0 ; i < len ; i ++ )
        {
            printf("%c", str[i]);
            if ( (i+1)%4 == 0 && i != len-1)
            {
                if ( (i+1)%(16*4) == 0 )
                    printf("\n");
                else
                    printf(" ");
            }
        }
        printf("\n%d\n", len);
        return 1;
    }
    else 
        curr++;
    
    if ( len >= MAX_LENGTH ) return 0;

    char str_possibles[27];
    int nPossible = gen_possibles( str, len, str_possibles );
    int i, j ;
    
    
    for ( i = 0 ; i < nPossible ; i ++ )
    {
        str[len] = str_possibles[ i ] ;
        if ( recur( str, len+1 ) == 1 )
            return 1;
        str[len] = 0x00;
    }
    
    return 0;
}
void process( FILE *fp )
{
    while ( fscanf(fp, "%d %d ", &n, &L ) == 2 && ( n || L ) )
    {
        char str[ MAX_LENGTH + 1 ] = {0, };
        int len;
        
        curr = 0 ;
        recur(str, 0);
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