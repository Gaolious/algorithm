// 127 “Accordian” Patience

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _card_ CARD, *PCARD;
struct _card_
{
    char face; // A=Ace, 2–9, T=10, J=Jack, Q=Queen, K=King
    char suit; // C=Clubs, D=Diamonds, H=Hearts, S=Spades
};
CARD card[53][53]={0,};
int stack_count[53]={0,};
int nCurrIndex = 0;

//void print( )
//{
//    for ( int i = 0 ; i <= nCurrIndex ; i ++ )
//    {
//        printf("%d[%2d] : ", i, stack_count[i] );
//        for ( int j = 0 ; j < stack_count[i] ; j ++ )
//            printf("%c%c ", card[i][j].face, card[i][j].suit );
//        printf("\n");
//    }
//    printf("\n");    
//}
PCARD getCard( int pos )
{
    if ( pos >= 0 && stack_count[ pos ] > 0 )
    {
        return &(card[ pos ][ stack_count[pos] - 1 ]);
    }
    return NULL ;
}
void addCard( PCARD new_card, int pos )
{
    if ( new_card && pos >= 0 )
    {
        card[ pos ][ stack_count[pos] ].face = new_card->face ;
        card[ pos ][ stack_count[pos] ].suit = new_card->suit ;
        stack_count[pos] ++;
    }
}
void delCard( int pos )
{
    PCARD card = getCard(pos);
    
    if ( card != NULL)
    {
        card->face = 0x00 ;
        card->suit = 0x00;
        stack_count[ pos ] --;
    }
}
int is_match( PCARD a, PCARD b)
{
    if ( a && b )
    {
        if ( a->face == b->face || a->suit == b->suit )
            return 1;
    }
    return 0;
}
void adjust_array()
{
    int i, j, k;
    
    for ( i = 0 ; i <=nCurrIndex ; i ++)
        if ( stack_count[ i ] == 0 )
        {
            for ( j = i + 1 ; j <= nCurrIndex ; j ++)
            {
                for ( k = 0 ; k < stack_count[j] ; k ++)
                {
                    card[j-1][k] = card[j][k];
                    memset( &(card[j][k]), 0x00, sizeof(CARD));
                }
                stack_count[j-1] = stack_count[j];
                stack_count[j]=0;
            }
            i--;
            nCurrIndex--;
        }
}

int move(int pos)
{
    PCARD third_left = getCard(pos-3);
    PCARD left = getCard(pos-1);
    PCARD curr = getCard(pos);
   
    /*
     * Situations can arise where more than one play is possible. 
     * [Condition #1] Where two cards may be moved, you should adopt the strategy of always moving the leftmost card possible. 
     * [Condition #2] Where a card may be moved either one position to the left or three positions to the left, move it three positions
     */

    if ( is_match(third_left, curr) )
    {
        addCard( curr, pos-3);
        delCard( pos );
        //print();
        adjust_array();
        return 1 ;
    }   
    
    if ( is_match(left, curr) )
    {
        addCard( curr, pos-1);
        delCard( pos );
        //print();
        adjust_array();
        return 1 ;
    }
   
    return 0;
}
void process( FILE *fp )
{

    while ( !feof(fp) )
    {
        memset( card, 0x00, sizeof(card) );
        memset( stack_count, 0x00, sizeof(stack_count));
        int nCard ;
        int i, j, k;
        
        for (nCurrIndex = 0 , nCard = 0 ; nCard < 52 ; nCard++, nCurrIndex++)
        {
            if ( fscanf(fp, "%c", &(card[nCurrIndex][0].face) ) != 1 ) return ;
            if ( card[nCurrIndex][0].face == '#' )
                    return;
            if ( fscanf(fp, "%c ", &(card[nCurrIndex][0].suit) ) != 1 ) return ;
            
            //printf("curr : Stack[%d] => %c%c\n", nCurrIndex, card[nCurrIndex][0].face, card[nCurrIndex][0].suit );
            
            stack_count[nCurrIndex]++;

            //print();
            
            /*
             * Situations can arise where more than one play is possible. 
             * [Condition #1] Where two cards may be moved, you should adopt the strategy of always moving the leftmost card possible. 
             * [Condition #2] Where a card may be moved either one position to the left or three positions to the left, move it three positions
             */
            for ( i = 0 ; i<=nCurrIndex ; i++)
            {
                if ( move( i) )
                    i=-1;
            }
        }
        
        adjust_array();
        printf("%d pile%s remaining:", 
                nCurrIndex+1, 
                nCurrIndex>0 ? "s":""
                );
        
        for ( i = 0 ; i <= nCurrIndex ; i ++)
            printf(" %d", stack_count[ i ]);
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