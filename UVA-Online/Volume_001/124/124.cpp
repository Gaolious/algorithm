// 124 - Following Orders
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int order[26][26] = {0,};
int possible[26]={0,};
int visit[26]={0,};
char print_str[27]={0,};
int n;

void recursive( int depth )
{
    int i, j, flag;

    for ( i = 0 ; i < 26 ; i ++ )
        if ( possible[i] == 1 && visit[i] == 0 )
        {
            flag = 0 ;
            for (j=0 ; j<depth ; j ++ )
                if ( order[ print_str[j]-'a'][i] < 0 ) { flag=1; break; }
            if ( flag ) continue ;
            
            visit[i] = 1 ;
            print_str[ depth ] = 'a' + i ;
            if ( depth + 1 < n )
            {
                recursive( depth + 1 );
            }
            else
            {
                printf("%s\n", print_str);
            }            
            visit[i] = 0 ;
            print_str[depth] = 0x00;
        }
}

void process( FILE *fp )
{
    
    char in[1024]={0,}, in2[1024]={0,};
    for( int repeat = 0 ;  fgets(in, sizeof(in)-1, fp) && fgets(in2, sizeof(in2)-1, fp) ; repeat = 1 )
    {
        if ( repeat != 0 ) printf("\n");
        int i, j  ;
        int len;
        
        memset( order, 0x00, sizeof(order)  ) ;
        memset( possible, 0x00, sizeof(possible)  ) ;
        memset( visit, 0x00, sizeof(visit) )  ;
        memset( print_str, 0x00, sizeof(print_str) ) ;
        
        j = 0 ;
        i = 0 ;
        len = strlen(in);
        while ( i < len )
        {
            while ( i < len && !( 'a' <= in[i] && in[i] <= 'z' ) ) i++;
            if ( i >= len ) continue ;
            
            possible[ in[i++] - 'a' ] = 1;
            j++;
        }
        n = j;

        i = 0;
        len = strlen(in2);
        while ( i < len )
        {
            while ( i < len && !( 'a' <= in2[i] && in2[i] <= 'z' ) ) i++;
            if ( i >= len ) continue ;
            char a = in2[i++] ;
            while ( i < len && !( 'a' <= in2[i] && in2[i] <= 'z' ) ) i++;
            if ( i >= len ) continue ;
            char b = in2[i++] ;
            
            order[ a - 'a' ][ b - 'a' ] = 1;
            order[ b - 'a' ][ a - 'a' ] = -1;
        }
        
        recursive(0);
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