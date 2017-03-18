// 112. Tree Summing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ReadNode(FILE *fp, int sum, int found_num, int *found )
{
    int num = 0 ;
    char c = 0 ;
    int sign = 1;
    int is_leaf = 1 ;
    
    int left_leaf = -1;
    int right_leaf = -1;
    
    while ( !feof(fp) && fscanf(fp, "%c ", &c ) )
    {
        if ( c == ')') 
        {
            return is_leaf ;
        }
        else if ( '-' == c )
        {
            sign = -1;
        }
        else if ( '0' <= c && c <= '9' )
        {
            is_leaf = 0;
            num = num * 10 + ( c - '0');
        }
        else if ( c == '(' )
        {
            if ( left_leaf == -1 )
                left_leaf = ReadNode(fp, sum + num*sign, found_num, found ) ;
            else 
                right_leaf = ReadNode(fp, sum + num*sign, found_num, found ) ;
            
            if ( left_leaf == 1 && right_leaf == 1 )
            {
                if ( sum+num*sign == found_num )
                {
                    *found = 1;
                }
            }
        }
    }
    
    return 0;
}

void process( FILE *fp )
{
    int sum = 0 ;
    char c;
    while ( !feof(fp) && fscanf(fp, "%d (", &sum ) == 1 )
    {
        int found = 0;
        
        ReadNode(fp, 0, sum, &found );
        
        if ( found )
            printf("yes\n");
        else
            printf("no\n");
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
