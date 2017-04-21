// 138 - Street Numbers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * International (IDD) 
 *      numbers start with two zeroes (00) 
 *      followed by a country code (1–3 digits)
 *      followed by a subscriber’s number (4–10 digits). 
 * 
 * National (STD) calls 
 *      start with one zero (0) followed by an 
 *      area code (1–5 digits) followed by 
 *      the subscriber’s number (4–7 digits). 
 * 
 * The price of a call is determined by its destination and its duration. 
 * Local calls start with any digit other than 0 and are free.
 * 
*/
#define MAX_DIGIT (15)
#define MAX_LOCALITY_NAME (25)

typedef struct _number_
{
    char digit[ MAX_DIGIT + 1 ];
    int nDigits;
    char locality_name[ MAX_LOCALITY_NAME + 1 ] ;
    double cent ;
} IDD, STD, LOCAL;

bool IsIdd( char *str )
{
    int len = strlen(str);
    return ( 2 <= len && str[0] == '0' && str[1] == '0' ) ;
}
bool IsStd( char *str )
{
    int len = strlen(str);
    return ( 1 <= len && str[0] == '0' ) ;
}
bool IsLocal( char *str )
{
    int len = strlen(str);
    return (  1 <= len && str[0] != '0' ) ;    
}

void concat_at_front( char *src, char *desc, int at)
{
    int len = strlen(desc);
    for (int i = 0 ; i < len ; i ++ )
        *(src + at + i ) = *(desc+i);
}
void concat_at_end( char *src, char *desc, int at)
{
    int len = strlen(desc);
    for (int i = 0 ; i < len ; i ++ )
        *(src + at - i ) = *(desc+ len - 1 - i);
}
int cmp( const void *_a, const void *_b)
{
    IDD *a = (IDD *)_a;
    IDD *b = (IDD *)_b;
    
    int len_a = strlen( a->digit );
    int len_b = strlen( b->digit );
    
    if ( len_a < len_b ) return 1;
    if ( len_a > len_b ) return -1;
    return strcmp( a->digit, b->digit );
}
IDD *Find( IDD *arr, int nCount, char *Number , int min, int max)
{
    int len = strlen(Number);
    
    for ( int i = 0 ; i < nCount ; i ++)
    if ( arr[i].nDigits + min <= len && len <= arr[i].nDigits + max )
    {
        if ( strncmp( arr[i].digit, Number, arr[i].nDigits ) == 0 ) 
            return arr+i;
    }
    return NULL;
}

void process(FILE *fp)
{    
    IDD arrIdds[1000]={0,};
    STD arrStds[1000]={0,};
    LOCAL local = { 
        "", 0, "Local", 0.0L
    };
    int nIdds, nStds ;
    
    nIdds = nStds = 0;
    while ( !feof(fp) )
    {
        IDD data={0, };
        if ( fscanf(fp, "%s ", data.digit ) == 1 )
        {
            if ( strcmp( data.digit, "000000" ) == 0 )
                break;
            char c ;
            int i;
            for ( i = 0 ; !feof(fp) && ( c = fgetc(fp) ) != '$' ; i ++)
                data.locality_name[ i ] = c ;
            fscanf(fp, "%lf ", &(data.cent) );
        }
        else
            break;
        
        data.nDigits = strlen(data.digit);
        if ( data.nDigits >= 2 && data.digit[0] == '0' && data.digit[1] == '0' ) 
            arrIdds[ nIdds ++ ] = data;
        else if ( data.nDigits >= 1 && data.digit[0] == '0' )
            arrStds[ nStds ++ ] = data;
    }
    
    qsort( arrIdds, nIdds, sizeof(IDD), cmp);
    qsort( arrStds, nStds, sizeof(STD), cmp);
    
    char number[MAX_DIGIT+1];
    double duration;
//    for ( int j=0 ; j<80 ; j++)
//        printf("%c", (j+1)%10 == 0 ? '*' : (j+1)%10+'0');
//    printf("\n");
    while ( fscanf(fp, "%s ", number ) == 1 && strcmp(number, "#" ) ) 
    {
        if ( fscanf(fp, "%lf ", &duration ) != 1 ) break;
        
        IDD *pNumber = NULL ;
        if ( IsIdd(number) ) pNumber = Find( arrIdds, nIdds, number , 4, 10);
        else if ( IsStd(number) ) pNumber = Find( arrStds, nStds, number, 4, 7 );
        else if ( IsLocal(number) ) pNumber = &local;
        else pNumber = NULL;
        
        char output[70]={0,};
        char str[70]={0,};
        
        for ( int i = 0 ; i < 69 ; i ++) output[ i ] = ' ';
        
        // Local calls are costed at zero. If the number has an invalid code, list the area as ‘Unknown’ and the cost as −1.00.

        // 1) Output will consist of the called number, 
        concat_at_front( output, number, 1-1);
        
        // 2) the country or area called, 
        sprintf(str, "%s", pNumber == NULL ? "Unknown" : pNumber->locality_name );        
        concat_at_front( output, str, 17 - 1 );
        
        // 3) the subscriber’s number, 
        if ( pNumber != NULL )
        {
            sprintf(str, "%s", number + pNumber->nDigits );
            concat_at_end( output, str, 51 - 1 );
        }
        
        // 4) the duration, 
        sprintf(str, "%.0lf", duration );
        concat_at_end( output, str, 56 - 1 );
        
        // 5) the cost per minute and 
        str[0]=0x00;
        if ( pNumber == NULL )
            str[0]=0x00;
        else
            sprintf(str, "%.2lf", pNumber->cent / 100.0 );
        concat_at_end( output, str, 62 - 1);
        
        // 6) the total cost of the call
        sprintf(str, "%.2lf", pNumber == NULL ? (double)(-1.0L) : (double)(pNumber->cent / 100.0 * duration)  );
        concat_at_end( output, str, 69 - 1);
        
        printf("%s\n", output);
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
