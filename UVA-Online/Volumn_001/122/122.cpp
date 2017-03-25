// 122 Trees on the level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _node NODE, *PNODE;
struct _node
{
    int num;
    PNODE left, right;
};

PNODE CreateNode()
{
    PNODE node = new NODE;
    
    node->num = 0;
    node->left = node->right = NULL;
    return node;
}

PNODE CreateOrGet_Left( PNODE node )
{
    if ( node == NULL )
        return NULL;
    else if ( node->left == NULL )
        node->left = CreateNode();
    
    return node->left ;
}
PNODE CreateOrGet_Right( PNODE node )
{
    if ( node == NULL )
        return NULL;
    else if ( node->right == NULL )
        node->right = CreateNode();
    
    return node->right ;
}

void delete_node( PNODE node )
{
    if ( node== NULL) return;
    
    if ( node->left != NULL ) delete_node(node->left);
    if ( node->right != NULL ) delete_node(node->right);
    
    delete node;
}
void process(FILE *fp)
{
    while ( !feof(fp) )
    {
        PNODE root = NULL ;
        char in[1024]={0,};

        while ( fscanf(fp, "%s ", in) == 1 )
        {
            if ( strcmp(in, "()" ) == 0 )
            {
                PNODE node_list[ 1000 ] ={ 0,} ;
                int head, tail ;
                int is_not_complete = 0 ;
                head = 0 ; tail =0;
                
                node_list[tail++] = root;
                
                while ( head < tail )
                {
                    PNODE curr = node_list[ head ++ ];
                    if ( curr != NULL )
                    {
                        if ( curr->num <= 0 ) is_not_complete = 1;
                        if ( curr->left != NULL ) node_list[ tail ++ ] = curr->left ;
                        if ( curr->right != NULL ) node_list[ tail ++ ] = curr->right ;
                        
                    }
                }
                
                if ( root == NULL || is_not_complete ) 
                    printf("not complete\n");
                else
                {
                    for ( head = 0 ; head < tail ; head ++)
                        if ( node_list[ head ] != NULL )
                        {
                            printf("%d", node_list[head]->num);
                            if ( head < tail - 1 ) printf(" ");
                        }
                    printf("\n");
                }
                
                break;
            }
            else 
            {
                int len = strlen(in);
                int i = 0 ;

                // skip '('
                for ( ; i < len && in[ i ] != '(' ; i ++ ){}
                for ( ; i < len && in[ i ] == '(' ; i ++ ){}
                
                int num = -1 ;
                // parse number
                for ( ; i < len && in[ i ] != ',' ; i ++ )
                {
                    if ( num < 0 ) num = 0 ;
                    num = num * 10 + in[i]-'0';
                }
                
                // skip ','
                for ( ; i < len && in[ i ] == ',' ; i ++ ) {}

                                
                if ( root == NULL )
                    root = CreateNode();
                PNODE curr = root ;
                
                for ( ; i < len && in[ i ] != ')' ; i ++ )
                {
                    if ( in[ i ] == 'L') curr = CreateOrGet_Left(curr);
                    else if ( in[ i ] == 'R') curr = CreateOrGet_Right(curr);                    
                }   
                
                if ( curr->num == 0 )
                    curr->num = num;
                else
                    curr->num = -1;
            }
        }
        
        delete_node(root);
        root = NULL ;        
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
