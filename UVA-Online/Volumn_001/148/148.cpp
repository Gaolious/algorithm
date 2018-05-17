#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DICTIONARY ( 2000 )

typedef struct _dictionary_
{
    char word[ 20 + 1 ];
    int count[127+1] ;
    unsigned char possible ;
} DICTIONARY ;


DICTIONARY Dictionary[ MAX_DICTIONARY ] ;
int nDictionary = 0 ;
char sentense[50000]={0,};
int path[1024] = {0, };

void setCountWord(char str[], int count[])
{
    for ( int i = 0 ; str[i] ; i++)
    if ( str[i] != ' ' )
        count[ str[ i ] ] ++;
}
void initialize_dictionary( DICTIONARY *pDict, char str[] )
{
    int i ;

    if ( ! pDict ) 
        return;
    
    memset( pDict, 0x00, sizeof(DICTIONARY));
    strcpy( pDict->word, str);
    
    setCountWord( pDict->word, pDict->count );
}
void strip(char *p)
{
    for ( int idx = strlen(p) - 1 ; idx >= 0; idx -- )
    {
        if ( p[ idx ] == '\n' )
            p[idx] = 0x00;
        else
            break;
    }
}

void setPossibleDictionary(char *pStr )
{
    char *p, *t;
    int i;
    char backup;

    for ( i = 0 ; i < nDictionary ; i ++)
        Dictionary[ i ].possible = 1;

    for ( p = pStr ; *p ; p = t )
    {
        for ( t = p+1 ; *t && *t != ' ' ; t ++ )
        {}

        if ( p >= t )
            continue;
        
        backup = *t ;

        *t = 0x00;

        for ( i = 0 ; i < nDictionary ; i ++)
            if ( strcmp(p, Dictionary[i].word) == 0 )
                Dictionary[ i ].possible = 0 ;

        *t = backup;

        if ( backup == ' ' )
            t++;
    }
}

int is_possible(int sentense_count[], int dictionary_count[])
{
    int i ; 

    for (  i = 0 ; i < 128 ; i ++ )
    if ( dictionary_count[ i ] > 0 && sentense_count[ i ] < dictionary_count[ i ] )
        return 0;

    return 1;
}

void find(int depth, int count[], int sum, int start_index = 0 )
{

    int i, j;
    int subtract = 0;

    if ( sum <= 0 )
    {
        printf("%s = ", sentense);
        for ( i = 0 ; i < depth ; i ++ )
        {
            if ( i != 0 ) printf(" ");
            printf("%s", Dictionary[ path[i] ].word );
        }
        printf("\n");
        return;
    }

    for (  i = start_index ; i < nDictionary ; i ++ )
    {
        if ( Dictionary[ i ].possible == 0 )
            continue;
        if ( is_possible( count, Dictionary[i].count ) == 0 )
            continue;

        subtract = 0;
        for ( j = 0 ; j < 128 ; j++ )
        {
            subtract += Dictionary[ i ].count[ j ];
            count[ j ] -= Dictionary[ i ].count[ j ] ;
        }
        path[ depth ] = i ;
        Dictionary[ i ].possible = 0;

        find(depth + 1, count, sum - subtract , i + 1);

        Dictionary[ i ].possible = 1;
        path[ depth ] = 0 ;

        for ( j = 0 ; j < 128 ; j++ )
            count[ j ] += Dictionary[ i ].count[ j ] ;

    }
}

void process(FILE *fp)
{
    int i ;
    int count[127+1] ;
    int sum ;

    for (nDictionary = 0 ; fscanf(fp, "%s ", sentense) == 1 && sentense[0] != '#' ; nDictionary ++ )
        initialize_dictionary( Dictionary + nDictionary, sentense);

    
    while ( fgets(sentense, sizeof(sentense)-1, fp ) && sentense[0] != '#' )
    {
        strip(sentense);
        
        memset( count, 0x00, sizeof(count) );
        setCountWord( sentense, count);
        setPossibleDictionary(sentense);

        for ( i = 0, sum = 0 ; i < sizeof(count)/sizeof(count[0]) ; i ++ )
            sum += count[ i ];

        find(0, count, sum);
    }
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