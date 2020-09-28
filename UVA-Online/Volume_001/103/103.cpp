
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIMENSIONS (10)
#define MAX_BOXES (30)

typedef struct _box_dimensions_
{
    int init_pos ;
    int dimensions[ MAX_DIMENSIONS ];
} BD ;

static int n_boxes, n_dimensions ;


int compare_dimension( const void *a, const void *b) 
{
    if (*(int*)a < *(int*)b) return -1; 
    else if (*(int*)a > *(int*)b) return 1; 
    else return 0;
}
int compare_boxes( const void *_a, const void *_b)
{
    BD *a = (BD *)_a;
    BD *b = (BD *)_b;
    int i ;
    
    for ( i = 0 ; i < n_dimensions ; i ++ )
    {
        if ( a->dimensions[ i ] > b->dimensions[ i ] )
        {
            return -1;
        }
        else if ( a->dimensions[ i ] < b->dimensions[ i ] )
        {
            return 1;
        }
    }
    
    return 0;
}

int is_inside( BD *larger, BD *smaller )
{
    int i ;
    for ( i = 0 ; i < n_dimensions ; i ++ )
    {
        if ( larger->dimensions[ i ] <= smaller->dimensions[ i ] )
            return 0;
    }
    return 1;
}
void print_path( BD *boxes, int path[], int curr, int depth )
{
    if ( curr < 0 )
    {
        printf("%d\n", depth );
        return ;
    }
    
    print_path( boxes, path, path[curr], depth+1);
    printf("%d", boxes[ curr ].init_pos);
    if ( depth != 0 ) printf(" ");    
}
void dp( BD *boxes )
{
    int table[ MAX_BOXES ] = {0,};
    int path[ MAX_BOXES ] = {0, };
    int i, j;
    int max_boxes = -1;
    int smallest_box = 0;
    
    for ( i = 0 ; i < n_boxes ; i ++ )
    {
        table[ i ] = 1;
        path[ i ] = -1 ;
    }
    
    for ( i = 1 ; i < n_boxes ; i ++ )
    {
        for ( j = 0 ; j < i; j ++ )
        {
            if ( is_inside( boxes + j, boxes + i ) )
            {
                if ( table[ i ] < table[ j ] + 1 )
                {
                    table[ i ] = table[ j ] + 1 ;
                    path[ i ] = j ;
                }
            }
        }
    }
    
    
    for ( i = 0 ; i < n_boxes ; i ++ )
    {
        if ( table[ i ] > max_boxes )
        {
            max_boxes = table[ i ] ;
            smallest_box = i ;
        }
    }
    
    if ( max_boxes >= 0 )
    {
        
        int nCnt ;
        int box_id ;
        
        for ( nCnt= 0 , box_id = smallest_box ;  box_id >= 0 ; )
        {            
            nCnt++;
            box_id = path[ box_id ];
        }
       
        printf("%d\n", nCnt);
        
        for ( nCnt = 1, box_id = smallest_box ;  box_id >= 0 ; nCnt++ )
        {
            printf("%d", boxes[ box_id ].init_pos );
            box_id = path[ box_id ];

            if ( box_id >= 0 ) printf(" ");
        }
        printf("\n");
    }
}

void process( FILE *fp )
{
    int i , j;
    BD box_dimensions[ MAX_BOXES ];
    
    while ( fscanf(fp, "%d %d", &n_boxes, &n_dimensions ) == 2 )
    {
        memset( (void *)box_dimensions, 0x00, sizeof(BD) * n_boxes ) ;
        
        for ( i = 0 ; i < n_boxes ; i ++ )
        {
            box_dimensions[i].init_pos = i+1;
            
            for ( j = 0 ; j < n_dimensions ; j ++ )
                fscanf(fp, "%d ", &(box_dimensions[i].dimensions[j]) );
            
            qsort( box_dimensions[i].dimensions, n_dimensions, sizeof(int), compare_dimension ) ;
        }
        qsort( box_dimensions, n_boxes, sizeof(BD), compare_boxes );
        
#ifndef ONLINE_JUDGE 

        for ( i = 0 ; i < n_boxes ; i ++ )
        {
            printf("%d, init[%d] : ", i, box_dimensions[ i].init_pos);
            
            for ( j = 0 ; j < n_dimensions ; j ++ )
                printf("%d ", box_dimensions[ i].dimensions[ j ]);
            printf("\n");
        }
#endif    
        dp( box_dimensions );
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
