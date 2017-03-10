#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
The valid commands for the robot arm that manipulates blocks are:
• move a onto b
where a and b are block numbers, puts block a onto block b after returning any blocks that are
stacked on top of blocks a and b to their initial positions.
• move a over b
where a and b are block numbers, puts block a onto the top of the stack containing block b, after
returning any blocks that are stacked on top of block a to their initial positions.
• pile a onto b
where a and b are block numbers, moves the pile of blocks consisting of block a, and any blocks
that are stacked above block a, onto block b. All blocks on top of block b are moved to their
initial positions prior to the pile taking place. The blocks stacked above block a retain their order
when moved.
• pile a over b
where a and b are block numbers, puts the pile of blocks consisting of block a, and any blocks
that are stacked above block a, onto the top of the stack containing block b. The blocks stacked
above block a retain their original order when moved.
 */

typedef struct _DLinkedList_ DLIST, *PDLIST, **PPDLIST;

struct _DLinkedList_
{
    PDLIST current_root ;
    PDLIST init_root ;
    
    int block_number ;
    PDLIST prev, next ;
};

void delete_node( PDLIST node )
{
    PDLIST prev, next ;
    
    if ( node != NULL && ( node->prev != NULL || node->next != NULL ) )
    {
        prev = node->prev;
        next = node->next;
        
        node->current_root = NULL;
        if ( prev != NULL ) prev->next = next;
        if ( next != NULL ) next->prev = prev;
        
        node->prev = node->next = NULL ;
    }
}
void append_node_next_of( PDLIST node, PDLIST new_node )
{
    PDLIST next ;
    
    if ( node != NULL && new_node != NULL && node)
    {
        delete_node( new_node );
        
        next = node->next ;
        
        new_node->prev = node ;
        new_node->next = next;

        node->next = new_node ;
        if ( next != NULL ) next->prev = new_node;
        
        new_node->current_root = node->current_root;
    }
}

void print( PDLIST root )
{
    PDLIST i = NULL ;
    
    if ( root != NULL )
    {
        printf("%d:", root->block_number );
        
        for ( i = root->next ; i != NULL && i != root ; i = i->next )
            printf( " %d", i->block_number );
	printf("\n");
    }
}

int is_root( PDLIST block )
{
    if ( block != NULL && block->init_root == NULL )
        return 1;
    return 0;
}
void returning_block( PDLIST block)
{
    if ( block == NULL || block->init_root == NULL )
        return ;
    
    PDLIST init_root = block->init_root;
    
    if ( init_root->prev != NULL )
        append_node_next_of( init_root->prev, block );
}
/**
 * • move a onto b
 * where a and b are block numbers, puts block a onto block b after returning any blocks that are
 * stacked on top of blocks a and b to their initial positions.
 */
void move_onto(PDLIST a, PDLIST b)
{
    if ( a != NULL && b != NULL )
    {
        while ( !is_root(a->next) && a->next != a )
            returning_block( a->next );

        while ( !is_root(b->next) && b->next != b )
            returning_block( b->next );

        append_node_next_of( b, a );
    }
}

/**
 * • move a over b
 * where a and b are block numbers, puts block a onto the top of the stack containing block b, after
 * returning any blocks that are stacked on top of block a to their initial positions.
 */
void move_over(PDLIST a, PDLIST b)
{
    if ( a != NULL && b != NULL )
    {
        while ( !is_root(a->next) && a->next != a )
            returning_block( a->next );

        append_node_next_of( b->current_root->prev, a );
    }
}

/**
• pile a onto b
 * where a and b are block numbers, moves the pile of blocks consisting of block a, and any blocks
 * that are stacked above block a, onto block b. All blocks on top of block b are moved to their
 * initial positions prior to the pile taking place. The blocks stacked above block a retain their order
 * when moved.
 */
void pile_onto(PDLIST a, PDLIST b)
{
    if ( a != NULL && b != NULL )
    {
        while ( !is_root(b->next) && b->next != b )
            returning_block( b->next );
        
        PDLIST curr_node = a ;
        PDLIST end_node = a->current_root->prev ;
        PDLIST target = b ;
        PDLIST target_root_node = b->current_root ;
        
        for ( PDLIST next_node = curr_node->next ;
                !is_root(curr_node) && end_node->current_root != target_root_node ;
                target=curr_node, curr_node = next_node, next_node=next_node->next )
        {
            append_node_next_of( target, curr_node );
        }
    }    
}

/**
 * • pile a over b
 * where a and b are block numbers, puts the pile of blocks consisting of block a, and any blocks
 * that are stacked above block a, onto the top of the stack containing block b. The blocks stacked
 * above block a retain their original order when moved.
 */
void pile_over(PDLIST a, PDLIST b)
{
    if ( a != NULL && b != NULL )
    {
        PDLIST curr_node = a ;
        PDLIST end_node = a->current_root->prev ;
        PDLIST target = b->current_root->prev ;
        PDLIST target_root_node = b->current_root ;
        
        for ( PDLIST next_node = curr_node->next ;
                !is_root(curr_node) && end_node->current_root != target_root_node ;
                target=curr_node, curr_node = next_node, next_node=next_node->next )
        {
            append_node_next_of( target, curr_node );
        }
        
    }   
}

void process( FILE *fp )
{
    int i, n;
    
    i=fscanf(fp, "%d", &n);
    
    PPDLIST Root = new PDLIST[ n + 1 ];
    PPDLIST Node = new PDLIST[ n + 1 ];
    
    for (  i = 0 ; i < n ; i ++ )
    {
        PDLIST root_node = new DLIST;
        root_node->block_number = i;
        root_node->current_root = root_node ;
        root_node->prev = root_node;
        root_node->next = root_node;
        root_node->init_root = NULL;
        Root[ i ] = root_node; 
        
        PDLIST node = new DLIST;
        node->block_number = i;
        node->init_root = root_node;
        node->prev = NULL;
        node->next = NULL;
        Node[ i ] = node ;
        
        append_node_next_of( root_node, node );
    }
    
    char cmd1[1024], cmd2[1024];
    int a, b ;
    while ( fscanf(fp, "%s", cmd1) == 1 && strcmp( cmd1, "quit" ) != 0 )
    {
        i=fscanf(fp, "%d %s %d", &a, cmd2, &b);
        
#ifndef ONLINE_JUDGE        
        printf("\n%s %d %s %d\n", cmd1, a, cmd2, b);
#endif        
        if ( a == b ) continue ;
        if ( Node[a]->current_root == Node[b]->current_root ) continue ;
        
        if ( strcmp( cmd1, "move") == 0 )
        {
            if ( strcmp( cmd2, "onto") == 0 )
                move_onto( Node[a], Node[b] );
            else if ( strcmp(cmd2, "over" ) == 0 )
                move_over( Node[a], Node[b] );
        }
        else if ( strcmp(cmd1, "pile" ) == 0 )
        {
            if ( strcmp( cmd2, "onto") == 0 )
                pile_onto( Node[a], Node[b] );
            else if ( strcmp(cmd2, "over" ) == 0 )
                pile_over( Node[a], Node[b] );
        }
#ifndef ONLINE_JUDGE        
    for (  i = 0 ; i < n ; i ++ )
    {
        if ( i != 0 ) printf("\n");
        print( Root[ i ] );
    }
#endif        
    }

    for (  i = 0 ; i < n ; i ++ )
    {
        print( Root[ i ] );
    }
    
    if ( Root != NULL )
    {
        for (  i = 0 ; i < n ; i ++ )
        {
            if ( Root[ i ] != NULL )
            {
                delete Root[ i ] ;
                Root [ i ] = NULL;
            }
        }
        
        delete [] Root;
        Root = NULL ;
    }
    
    
    if ( Node != NULL )
    {
        for (  i = 0 ; i < n ; i ++ )
        {
            if ( Node[ i ] != NULL )
            {
                delete Node[ i ] ;
                Node [ i ] = NULL;
            }
        }
        
        delete [] Node;
        Node = NULL ;
    }
}
int main(int argc, char** argv) 
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin ;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif    

    process(fp);

#ifdef ONLINE_JUDGE
#else
    fclose(fp);
#endif    

    return 0;
}

