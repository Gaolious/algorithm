// 133 - The Dole Queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
 * Every day all dole applicants will be placed in a large circle, facing inwards. 
 * 
 * Someone is arbitrarily chosen as number 1, 
 * and the rest are numbered counterclockwise up to N (who will be standing on 1’s left). 
 * 
 * Starting from 1 and moving counter-clockwise, one labour official counts off k applicants, 
 * while another official starts from N and moves clockwise, counting m applicants. 
 * 
 * EX> N=10 k=4 m=3
 * 
 * 10 9 8 7 6 5 4 3 2 1 
 * 
 * 1's k-th(4) left : 4 , next start 5
 * 10's m-th(3) right : 8, next start 7
 * 
 * 10 9 7 6 5 3 2 1 
 * 5's k-th(4) left : 9 , next start 10
 * 7's m-th(3) right : 5, next start 3
 * 
 * 10 7 6 3 2 1 
 * 10's k-th(4) left : 3 , next start 6
 * 3's m-th(3) right : 1, next start 10
 * 
 * 10 7 6 2
 * 6's k-th(4) left : 2, next start 6, but 7
 * 10's m-th(3) right : 6 , next start 2, but 10
 * 
 * 10 7
 * 7's k-th(4) left : 10, next start 7
 * 10's m-th(3) right : 10 , next start 7

 * 7
 * 
 *  * output : 
 * ␣␣4␣␣8,␣␣9␣␣5,␣␣3␣␣1,␣␣2␣␣6,␣10,␣␣7
 * 
 * The two who are chosen are then sent off for retraining; 
 * 
 * if both officials pick the same person she (he) is sent off to become a politician. 
 * 
 * Each official then starts counting again at the next available person and the process continues until no-one is left. 
 * 
 * Note that the two victims (sorry, trainees) leave the ring simultaneously, 
 * 
 * so it is possible for one official to count a person already selected by the other official.
 */

struct NODE
{
    int num;
    struct NODE *left, *right;
};
/*
 * 
 * @param fp
 */
#define MAX_NODE (20)

NODE *GetLeftNode( NODE *root, int k, int node_size )
{
    int i ;
    
    k--;
    k %= node_size;
    
    if ( node_size/2 >= k )
    {
        for ( i = 0 ; i < k ; i ++ )
            root = root->left;
    }
    else
    {
        for ( i = 0 ; i < node_size - k ; i ++ )
            root = root->right;        
    }
    return root;
}

NODE *GetRightNode( NODE *root, int m, int node_size )
{
    int i ;
    m--;
    m %= node_size;
    if ( node_size / 2 >= m )
    {
        for ( i = 0 ; i < m ; i ++ )
            root = root->right;
    }
    else
    {
        for ( i = 0 ; i < node_size - m ; i ++ )
            root = root->left;        
    }
    return root;
}
void del_node( NODE *node )
{
    NODE *left, *right;
    
    if ( node == NULL )
        return;
    left = node->left ;
    right = node->right;
    if ( left ) left->right = right;
    if ( right ) right->left = left;
}

int pick_node( NODE *left, NODE *right, int node_count, int N )
{
    if ( N != node_count )
        printf(",");
    
    if ( left == right )
    {
        del_node(left);
        printf("%3d", left->num);
        return node_count - 1;
    }
    else
    {
        del_node(left);
        del_node(right);
        printf("%3d%3d", left->num, right->num);
        return node_count-2;
    }
}
void print_node( NODE *root, int node_count)
{
    printf("\n-----------------------------------\n");
    for ( int i = 0 ; i < node_count ; i ++, root=root->right)
        printf("%d->", root->num);
    printf("\n");
}
void process(FILE *fp)
{
    int N, k, m;
    
    while ( fscanf(fp, "%d %d %d ", &N, &k, &m) == 3 && ( N || k || m ) )
    {
        NODE node[MAX_NODE]={0,};
        int i;
        int node_count = N ;
        
        for ( i = 0 ; i < N ; i ++ )
        {
            node[ i ].num = N - i ;
            node[ i ].left = node + ( i - 1 + N ) % N ;
            node[ i ].right = node + ( i + 1 + N ) % N ;
        }
        
        NODE *left_root = node+N-1;
        NODE *right_root= node;
        
        while ( node_count > 0 )
        {
            //print_node(node, node_count);
            if ( node_count == 1 )
            {
                node_count = pick_node( left_root, right_root, node_count, N );
                continue;
            }
            
            NODE *left = GetLeftNode( left_root, k, node_count );
            NODE *right = GetRightNode( right_root, m, node_count );
            
            //printf("Pick Left(%d), Right(%d)\n", left->num, right->num);
            NODE *next_left = left->left;
            NODE *next_right = right->right;
            //printf("next Left(%d), Right(%d)\n", next_left->num, next_right->num);
            
            while ( next_left == right || next_right == left )
            {
                if ( next_left == right )
                    next_left = next_left->left;
                if ( next_right == left )
                    next_right = next_right->right;
                // printf("next Left(%d), Right(%d)\n", next_left->num, next_right->num);
            }
            
            node_count = pick_node( left, right, node_count, N );
            
            left_root = next_left;
            right_root = next_right;
        }
        printf("\n");
        
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