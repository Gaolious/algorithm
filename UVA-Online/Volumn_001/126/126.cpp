// 125 - Numbering Paths
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (80)

typedef struct _xy_ XY, *PXY;

struct _xy_
{
    int coefficient ;
    int exponential_x ;
    int exponential_y ;
    PXY prev, next ;
} ;


char *parse_positive_int(char *s, int *val)
{
    int num = 0 ;
    int is_set = 0 ;
    
    for ( ; *s != 0x00 &&  '0' <= *s && *s <= '9' ; s++) 
    {
        num = num * 10 + (*s) - '0' ;
        is_set = 1;
    }
    
    if ( is_set == 0 ) num = 1;
    
    *val = num ;
    
    return s;
}

char *parse_int(char *s, int *val)
{
    int sign = 1;
    int num = 0 ;
    int is_set = 0 ;
    
    if ( *s != 0x00 && *s == '-' ) 
    {
        sign = -1;
        s++;
    }
    else if ( *s != 0x00 && *s == '+' ) 
    {
        sign = 1;
        s++;
    }    
    
    for ( ; *s != 0x00 &&  '0' <= *s && *s <= '9' ; s++) 
    {
        num = num * 10 + (*s) - '0' ;
        is_set = 1;
    }
    
    if ( is_set == 0 ) num = 1;
    
    *val = sign * num ;
    
    return s;
}

int cmp( PXY a, PXY b)
{
    if ( a->exponential_x < b->exponential_x) return -1;
    if ( a->exponential_x > b->exponential_x) return 1;
    
    if ( a->exponential_y < b->exponential_y) return 1;
    if ( a->exponential_y > b->exponential_y) return -1;
    
    return 0;
}

void set( PXY node, PXY xy)
{
    memset( node, 0x00, sizeof(XY) );
    node->coefficient = xy->coefficient;
    node->exponential_x = xy->exponential_x;
    node->exponential_y = xy->exponential_y;
    node->prev = node->next = NULL ;    
}
PXY get_new_node()
{
    PXY node = new XY;
    return node;
}
void append_node( PXY node, PXY xy)
{
    PXY next = node ? node->next : NULL ;
    
    if ( node ) node->next = xy ;
    if ( xy ) xy->prev = node;
    if ( xy ) xy->next = next;
    if ( next ) next->prev = xy ;
        
}
void del_node( PXY node)
{
    PXY prev = node ? node->prev : NULL ;
    PXY next = node ? node->next : NULL ;
    if ( node )
        delete node;
    
    if ( prev ) prev->next = next;
    if ( next ) next->prev = prev;
}
void add( PXY root, PXY xy )
{
    if ( root == NULL )
        return;

    if ( root->next == NULL )
    {
        PXY node = get_new_node();
        set(node, xy);
        append_node( root, node );
    }
    else
    {
        PXY curr = root;
        PXY prev = root ;
        for ( curr = prev->next ; curr != NULL ; prev = curr, curr = curr->next )
        {
            int diff = cmp( curr, xy );
            
            if ( diff > 0 ) continue ;
            else if ( diff < 0 )
            {
                PXY node = get_new_node();
                set(node, xy);
                append_node( prev, node );                
                return;
            }
            else
            {
                curr->coefficient += xy->coefficient;
                if ( curr->coefficient == 0 )
                    del_node(curr);
                return;
            }
        }
        
        PXY node = get_new_node();
        set(node, xy);
        append_node( prev, node );                
    }
}

void parse_expression( PXY xy, char *s )
{
    while ( *s )
    {
        XY node ={0,};

        s = parse_int(s, &(node.coefficient) );

        while ( *s != 0x00 && !(*s == '+' || *s == '-' )  )
        {
            if ( *s != 0x00 && *s == 'x' )
            {
                s++;
                s = parse_positive_int(s, &(node.exponential_x) );
            }
            else if ( *s != 0x00 && *s == 'y' )
            {
                s++;
                s = parse_positive_int(s, &(node.exponential_y) );
            }
            else 
                break;
        }
        while ( *s == '\n' || *s == ' ' || *s == '\r' || *s == '\t' ) s++;

        if ( node.coefficient == 0 && node.exponential_x == 0 && node.exponential_y == 0 )
            continue ;
        add( xy, &node );
    }    
}

void multi( PXY root, PXY a, PXY b)
{
    
    PXY i, j;
    
    for ( i = a->next ; i != NULL ; i = i->next )
        for ( j = b->next ; j != NULL ; j = j->next )
        {
            PXY node = get_new_node();
            node->coefficient = i->coefficient * j->coefficient ;
            node->exponential_x = i->exponential_x + j->exponential_x ;
            node->exponential_y = i->exponential_y + j->exponential_y ;
            
            add(root, node);
        }
}

void append(char str1[], int *len1, char str2[], int *len2, const char *append1, const char *append2 )
{
    if ( append1 != NULL )
    {
        while ( *append1 )
        {
            str1[ *len1 ] = *append1 ;
            str2[ *len2 ] = ' ';
            (*len1) ++;
            (*len2) ++;
            append1++;
        }
    }
    if ( append2 != NULL )
    {
        while ( *append2 )
        {
            str1[ *len1 ] = ' ';
            str2[ *len2 ] = *append2 ;
            (*len1) ++;
            (*len2) ++;
            append2++;
        }
    }    
}
void print_xy( PXY root)
{
    char output1[10240]={0,};
    char output2[10240]={0,};
    
    int pos1, pos2;
    int curr_pos;
    
    
    pos1 = pos2 = 0 ;
    PXY curr;
    for ( curr = root ; curr != NULL ; curr = curr->next)
    {        
        if ( curr->coefficient < 0 )
        {
            if ( curr == root )
            {
                append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    "-" );
            }
            else
            {
                append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    " - " );                
            }
            curr->coefficient *= -1;
        }
        else if ( curr->coefficient > 0 && curr != root ) 
        {
            append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    " + " );
        }
        
        if ( curr->exponential_x == 0 && curr->exponential_y == 0 )
        {
            char str[1024]={0,};
            sprintf(str, "%d", curr->coefficient);
            append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    str );
            continue ;
        }
        if ( curr->coefficient > 1 )
        {
            char str[1024]={0,};
            sprintf(str, "%d", curr->coefficient);
            append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    str );
        }
        
        if ( curr->exponential_x > 0 )
        {
            append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    "x" );            
            if ( curr->exponential_x > 1 )
            {
                char str[1024]={0,};
                sprintf(str, "%d", curr->exponential_x);
                
                append( output1, &pos1, output2, &pos2, 
                        str, 
                        NULL );            
            }
        }
        if ( curr->exponential_y > 0 )
        {
            append( output1, &pos1, output2, &pos2, 
                    NULL, 
                    "y" );            
            if ( curr->exponential_y > 1 )
            {
                char str[1024]={0,};
                sprintf(str, "%d", curr->exponential_y);
                
                append( output1, &pos1, output2, &pos2, 
                        str, 
                        NULL );            
            }
        }        
        
    }
    
    if ( root == NULL )
        printf("\n0\n");
    else
        printf("%s\n%s\n", output1, output2);
}
void process( FILE *fp )
{
    
    int mode = 0 ;
    XY xy1 = {0, };
    XY xy2 = {0, } ;
    XY result = {0, };
    
    char in1[MAX_SIZE+1]={0,};
    char in2[MAX_SIZE+1]={0,};
    
    while ( fgets(in1, sizeof(in1)-1, fp ) && strcmp(in1, "#") && fgets(in2, sizeof(in2)-1, fp ) )
    {
        char *s1 = &(in1[0]), *s2 = &(in2[0]);
        parse_expression( &xy1, s1 );
        parse_expression( &xy2, s2 );

        multi ( &result, &xy1, &xy2 );
        
        print_xy( result.next);
        
        while ( xy1.next ) del_node( xy1.next);
        while ( xy2.next ) del_node( xy2.next);        
        
        
        while ( result.next ) del_node( result.next);        
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