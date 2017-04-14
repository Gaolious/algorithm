#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr26[26+1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert_10_to_26(int n, char *str, int *len )
{
    while ( n > 0 )
    {
        str[ (*len) ++ ] = arr26[ (n-1) % 26 ];
        n = (n-1) / 26;
    }
    str[ *(len) ] = 0x00;
    
    for ( int i = 0 ; i * 2 < *len - 1 ; i ++ )
    {
        char c = str[ i ] ;
        str[ i ] = str[ *len - 1 - i ];
        str[ *len - 1 - i ] = c;
    }
}
void convert_26_to_10(char *str, int len, int *n )
{
    int num = 0 ;
    for ( int i = 0 ; i < len ; i ++ )
        num = num * 26 + ( str[i] - 'A' + 1 ) ;
    *n = num;
}

void process(FILE *fp)
{
    int n;

    while ( fscanf(fp, "%d ", &n ) == 1 )
    {
        char str[1024];
        int len ;
        for ( int i = 0 ; i < n ; i ++ )
        {
            if ( fscanf(fp, "%s ", str) == 1 )
            {
                int n1, n2 ;
                if ( sscanf(str, "R%dC%d", &n1, &n2 ) == 2 )
                {
                    char col[100];
                    int  nCol=0;
                    convert_10_to_26(n2, col, &nCol);
                    
                    printf("%s%d\n", col, n1);
                }
                else
                {
                    int len = strlen(str);
                    int row = 0 ;
                    for ( int i = 0 ; i <len ; i ++ )
                        if ( '0' <= str[i] && str[i] <= '9' )
                        {
                            row = row * 10 + str[i]-'0';
                            str[i]=0x00;
                        }
                    int col =0;
                    convert_26_to_10( str, strlen(str), &col);
                    
                    printf("R%dC%d\n", row, col);
                }
            }
        }
    }
}
int main()
{
#ifndef _AJAVA_ 
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif

    process(fp);

#ifndef _AJAVA_ 
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
