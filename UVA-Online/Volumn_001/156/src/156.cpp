#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *_a, const void *_b)
{
    char a = *(char *)_a ;
    char b = *(char *)_b ;

    if ( a < b ) return -1;
    else if (a > b ) return 1;
    return 0;
}
typedef struct _word
{
    char word[20 + 1 ] ;
    char sorted[20 + 1 ] ;    
    int len;
} WORD ;

int comp2(const void *_a, const void *_b)
{
    WORD *a = (WORD *)_a; 
    WORD *b = (WORD *)_b;
    
    return strcmp( a->word, b->word );
}

void process(FILE *fp)
{
    WORD word[15000];
    int i, j, n;
    for ( n = 0 ; fscanf(fp, "%s ", word[n].word) == 1 ; n ++ )
    {
        if (word[n].word[0] == '#' )
            break;
        word[n].len = strlen(word[n].word);
        for ( i = 0 ; i < word[n].len ; i ++ )
            word[n].sorted[ i ] = ( word[n].word [ i ] >= 'A' && word[n].word [ i ] <= 'Z' ) ?
                word[n].word [ i ] - 'A' + 'a' : word[n].word [ i ];

        qsort(word[n].sorted, word[n].len, sizeof(char), comp );

    }

    qsort(word, n, sizeof(WORD), comp2);

    for ( i = 0 ; i < n ; i ++ )
    if ( word[i].len > 0 )
    {
        int is_ananagrams =  0 ;

        for ( j = i+1 ; j < n ; j ++)
        if ( word[j].len > 0 && i != j )
        {
            if ( strcmp(word[i].sorted, word[j].sorted) == 0 )
            {
                is_ananagrams = 1 ;
                word[i].len = word[j].len = -1;
            }
        }
    }

    for ( i = 0 ; i < n; i ++ )
    if ( word[i].len > 0 )
        printf("%s\n", word[i].word);
}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}