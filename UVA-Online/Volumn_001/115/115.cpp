// 115 - Climbing Trees

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Input :
	[ child - parent ]
	e d
	d c
	c b
	b a
	i h
	h g
	g f
	f a

	=> parent - child relations

	a +-- b -- c -- d -- e
	  |
	  +-- f -- g -- h -- i
	  


OUtput : 
	[ query ]
	b a => child
	a b => parent
	c a => grand child
	a c => grand parent
	a d => great grand parent
	a e => great great grand parent
	e f => 0 cousin removed 3  ( common ancestor : a / a-e : 3-descendent, a-f : 0-descendent / min(3,0), |3-0| )
	e g => 1 cousin removed 2  ( common ancestor : a / a-e : 3-descendent, a-g : 1-descendent / min(3,1), |3-1|  )
	e h => 2 cousin removed 1  ( common ancestor : a / a-e : 3-descendent, a-h : 2-descendent / min(3,2), |3-2|  )
	e i => 3 cousin ( common ancestor : a / a-e : 3-descendent, a-i : 3-descendent / min(3,2), |3-3|   )

 */

#define MAX_NAME_LENGTH (31)
#define MAX_NODE (300)

typedef struct _115_{
    char name [ MAX_NAME_LENGTH + 1 ];
    int parent_idx ;
    int depth ;
} NODE, *PNODE ;
NODE node[ MAX_NODE ] = {0, };
int nNode = 0;

int GetNode( char *name )
{
    for ( int i = 0 ; i < nNode ; i ++ )
    {
        if ( strcmp( node[ i ].name, name ) == 0 )
            return i ;
    }
    
    return -1 ;
}
int AddNode( char *name, int parentIdx = -1)
{
    strcpy( node[ nNode ].name, name );
    node[ nNode ].parent_idx = parentIdx;
    node[ nNode ].depth = -1;
    return nNode++;
}

int GetDepth( int idx )
{
    if ( idx < 0 )
        return 0 ;
    else if ( node[ idx ].depth < 0 )
        node[ idx ].depth = GetDepth( node[ idx ].parent_idx ) + 1 ;
    
    return node[ idx ].depth;
}
void process( FILE *fp )
{
    NODE child, parent ;
    int i, parent_idx;
    
    while ( fscanf(fp, "%s %s ", child.name, parent.name ) == 2 && strcmp( child.name, "no.child") && strcmp( parent.name, "no.parent") )
    {
        int child_idx = GetNode( child.name );
        int parent_idx = GetNode( parent.name );
        
        if ( parent_idx < 0 )  parent_idx = AddNode( parent.name, -1 );
        
        if ( child_idx < 0 )  
            child_idx = AddNode( child.name, parent_idx );
        else
            node[ child_idx ].parent_idx = parent_idx ;
    }

    for ( i = 0 ; i < nNode ; i ++ )
    if ( node[ i ].depth < 0 )
        node[ i ].depth = GetDepth( i );
    
    while ( fscanf(fp, "%s %s ", parent.name, child.name ) == 2 )
    {
        int child_idx = GetNode( child.name );
        int parent_idx = GetNode( parent.name );
        int n, m ;
        
        if ( child_idx < 0 || parent_idx < 0  || child_idx == parent_idx)
        {
            printf("no relation\n");
            continue ;
        }        

#ifndef ONLINE_JUDGE 
//        printf("--------------------------------------------------------------\n");
//        printf("Lookup : %s\n", child.name);
//        for ( loop = child_idx ; loop >= 0 ; loop = node_idx[ loop ] )
//            printf("Node[%d] : name[%s], parent : %d\n", loop, node[loop].name, node[loop].parent_idx );
//        printf("Lookup : %s\n", parent.name);
//        for ( loop = parent_idx ; loop >= 0 ; loop = node_idx[ loop ] )
//            printf("Node[%d] : name[%s], parent : %d\n", loop, node[loop].name, node[loop].parent_idx );
#endif        
        int c = child_idx, p=parent_idx ;
        while ( node[c].depth >= 0 && node[p].depth >=0 && c != p )
        {
            if ( node[c].depth < node[p].depth ) p = node[p].parent_idx;
            else c = node[c].parent_idx;
        }
        
        if ( c != p )
        {
            printf("no relation\n");
            continue ;
        }

        n = node[child_idx].depth - node[c].depth ;
        m = node[parent_idx].depth - node[p].depth ;
        
        if ( n <= 0 )
        {
            for ( i = 0 ; i < m - 2 ; i ++ )
                printf("great ");
            if ( m >= 2 ) printf("grand ");
            printf("child\n");
        }
        else if ( m <= 0 )
        {
            for ( i = 0 ; i < n - 2 ; i ++ )
                printf("great ");
            if ( n >= 2 ) printf("grand ");
            printf("parent\n");
        }
        else if ( n == 1 && m == 1 )
        {
            printf("sibling\n");
        }
        else 
        {
            int a, b ;
            n--;
            m--;
            a = n < m ? n : m ;
            b = n < m ? m - n : n - m ;
            
            printf("%d cousin", a);
            if ( b >= 1 )
                printf(" removed %d", b);
            printf("\n");
        }
        
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
