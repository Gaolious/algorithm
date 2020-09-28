#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ignore_word_array [50] ={0,};
int ignore_word_count = 0;

// to improve the performance 
// create reverse index to find quickly.
// store the title indexes for each the words.
// but following code is accept 0.00 sec.
char *word_array[10000] = {0, };
int word_count = 0 ;

typedef struct _title_
{
    char *word ;
    struct _title_ *next ;
} TITLE;
TITLE title[ 200 ] ={0,};
int  title_count = 0 ;

void tolower(char str[], int length )
{
    int i;
    for ( i = 0 ; i < length ; i ++)
        if ( 'A' <= str[ i ] && str[i] <= 'Z' )
            str[ i ] = str[i] - 'A' + 'a';
}


int find_ignore_word(char *str)
{
    int left = 0;
    int right = ignore_word_count - 1 ;
    
    while ( left <= right )
    {
        int mid = ( left + right + 1 ) / 2 ;
        
        int cmp = strcmp( str, ignore_word_array[mid]) ;
            
        if ( cmp == 0 )
            return mid ;
        else if ( cmp < 0 ) 
            right = mid - 1;
        else if ( cmp > 0 ) 
            left = mid + 1 ;
    }
    
    return -1;
}
int cmp_char_ptr( const void *a, const void *b )
{
    return strcmp( *(char **)a, *(char **)b);
}

void read_ignore_word(FILE *fp)
{
    char in[20001]={0,};
    
    while ( fscanf(fp, "%s ", in) == 1 && strcmp( in, "::") != 0 )
    {
        int len = strlen(in);
        tolower(in, len);
        
        ignore_word_array[ ignore_word_count ] = new char [ len + 1 ] ;
        memset( ignore_word_array[ ignore_word_count ], 0x00, sizeof(char)*(len+1) );
        strncpy( ignore_word_array[ ignore_word_count ], in, len );
        ignore_word_count++;
    }
    if ( ignore_word_count > 1 )
        qsort( ignore_word_array, ignore_word_count, sizeof(char *), cmp_char_ptr );
}


int find_word(char *str)
{
    int left = 0;
    int right = word_count - 1 ;
    
    while ( left <= right )
    {
        int mid = ( left + right + 1 ) / 2 ;
        
        int cmp = strcmp( str, word_array[mid]) ;
            
        if ( cmp == 0 )
            return mid ;
        else if ( cmp < 0 ) 
            right = mid - 1;
        else if ( cmp > 0 ) 
            left = mid + 1 ;
    }
    
    return -1;
}
int add_word(char *str)
{
    int i = 0 ;
    
    for ( i = word_count ; i>0 ; i -- )
    {
        int cmp = strcmp( word_array[ i - 1 ], str ) ;
            
        if ( cmp > 0 )
            word_array[ i ] = word_array[ i - 1 ] ;
        else
            break;
    }
    word_array[ i ] = str ;
    word_count++;
    return i;
}
void read_title(FILE *fp)
{
    char in[20001]={0,};
    int i, start, end, len ;
    
    while ( fgets(in, sizeof(in)-1, fp ) )
    {
        len = strlen(in);
        
        tolower(in, len);

        TITLE *current_title = title + title_count ;
        
        for ( i = 0 ; i < len ; )
        {
            while ( i < len && !('a' <= in[i] && in[i] <= 'z' ) ) i++;
            start = i ;
            while ( i < len && ('a' <= in[i] && in[i] <= 'z' ) ) i++;
            end = i ;
            
            if ( start < end )
            {
                char *new_word = new char[ end - start + 1 ] ;
                char *word_ptr = NULL ;
                memset( new_word, 0x00, end-start+1);
                strncpy( new_word, in+start, end-start);
                
                int word_idx;
                int ignore_idx = find_ignore_word(new_word) ;
                
                if ( ignore_idx < 0 )
                {
                    word_idx = find_word(new_word);
                    if ( word_idx < 0 )
                    {
                        int t = add_word( new_word );
                        word_ptr = word_array[ t ];
                    }
                    else 
                        word_ptr = word_array [ word_idx ] ;
                }
                else 
                    word_ptr = ignore_word_array [ ignore_idx ] ;
                
                if ( word_ptr != NULL )
                {
                    if ( current_title->word != NULL )
                    {
                        current_title->next = new TITLE;
                        current_title = current_title->next;
                        current_title->word = NULL ;
                        current_title->next = NULL ;
                    }
                    current_title->word = word_ptr ;
                }
                    
                if ( ignore_idx >= 0 || word_idx >= 0 )
                    delete [] new_word;
            }
        }
        if ( current_title != NULL )
        {
            if ( current_title != title + title_count || current_title->word != NULL )
                title_count++;
        }
    }

    if ( word_count > 1 )
    {
        qsort(word_array, word_count, sizeof(char*), cmp_char_ptr );
    }
        
}

void print_title( int title_idx, TITLE *upper_title )
{
    for ( TITLE *curr = title + title_idx ; curr != NULL ; curr = curr->next )
    {
        if ( upper_title == curr )
        {
            for (int i = 0 ;curr->word[i] != 0x00 ; i ++)
                printf("%c", curr->word[i] - 'a' + 'A');
        }
        else
            printf("%s", curr->word);
        
        if ( curr->next != NULL ) printf(" ");
    }
    printf("\n");
    
}
void print_output()
{
    int i, j;
    TITLE *curr ;
    
    for ( i = 0 ; i < word_count ; i ++ )
    {
        for ( j = 0 ; j < title_count ; j ++ )
        {
            for ( curr = title + j ; curr != NULL ; curr = curr->next )
            if ( word_array[ i ] == curr->word )
            {
                print_title( j, curr );
            }
        }
    }
}

void deallocation()
{
    int i;
    
    for ( i = 0 ; i < ignore_word_count ; i ++ )
    if ( ignore_word_array[i] != NULL )
    {
        delete [] ignore_word_array[ i ] ;
        ignore_word_array[ i ] = NULL;
    }
    
    for ( i = 0 ; i < word_count ; i ++ )
    if ( word_array[i] != NULL )
    {
        delete [] word_array[ i ] ;
        word_array[ i ] = NULL;
    }
    
    TITLE *curr = NULL ;
    for ( i = 0 ; i < title_count ; i ++)
    {
        curr = title[i].next; ;
        
        if ( curr != NULL )
        {
            TITLE *next = curr->next ;
            delete curr;
            curr = next ;
        }
    }
}

void process( FILE *fp )
{
    read_ignore_word(fp);
    read_title(fp);

    print_output();
    deallocation();
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