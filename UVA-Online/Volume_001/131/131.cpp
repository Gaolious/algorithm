// 131 The Psychic Poker Player

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _card_
{
    char face;
    char suit;
} CARD, *PCARD;

char Index[33][5]={
    {0,1,2,3,4}, {0,1,2,3,5}, {0,1,2,5,4}, {0,1,2,5,6}, {0,1,5,3,4}, 
    {0,1,5,3,6}, {0,1,5,6,4}, {0,1,5,6,7}, {0,5,2,3,4}, {0,5,2,3,6}, 
    {0,5,2,6,4}, {0,5,2,6,7}, {0,5,6,3,4}, {0,5,6,3,7}, {0,5,6,7,4}, 
    {0,5,6,7,8}, {5,1,2,3,4}, {5,1,2,3,6}, {5,1,2,6,4}, {5,1,2,6,7}, 
    {5,1,6,3,4}, {5,1,6,3,7}, {5,1,6,7,4}, {5,1,6,7,8}, {5,6,2,3,4}, 
    {5,6,2,3,7}, {5,6,2,7,4}, {5,6,2,7,8}, {5,6,7,3,4}, {5,6,7,3,8}, 
    {5,6,7,8,4}, {5,6,7,8,9},
    {-1,},
};
//int flag[5]={-1, -1, -1, -1, -1};
//
//void recursive(int depth, int deck_index)
//{
//    if ( depth == 5 )
//    {
//        printf("{");
//        for ( int i = 0 ; i < 5 ; i ++ )
//        {
//            if ( i != 0 ) printf(",");
//            printf("%d", flag[i]);        
//        }
//        printf("}, \n");
//        return;
//    }
//    else
//    {
//        flag[ depth ] = depth ;
//        recursive( depth + 1, deck_index );
//        flag[ depth ] = deck_index ;
//        recursive( depth + 1, deck_index+1 );
//    }
//
//}

typedef enum 
{ 
    highest_card,
    one_pair,
    two_pairs,
    three_of_a_kind,
    straight,
    flush,
    full_house,
    four_of_a_kind,
    straight_flush, 
} CARD_TYPE;
const char *GetScoreName( CARD_TYPE type)
{
    if ( type == highest_card ) return "highest-card";
    if ( type == one_pair ) return "one-pair";
    if ( type == two_pairs ) return "two-pairs";
    if ( type == three_of_a_kind ) return "three-of-a-kind";
    if ( type == straight ) return "straight";
    if ( type == flush ) return "flush";
    if ( type == full_house ) return "full-house";
    if ( type == four_of_a_kind ) return "four-of-a-kind";
    if ( type == straight_flush ) return "straight-flush";
    return "";
}
CARD_TYPE GetScore(int map[4][13])
{
    int s , f ;
    
    for ( s = 0 ; s < 4 ; s ++ )
    {
        if ( map[s][9] && map[s][10] && map[s][11] && map[s][12] && map[s][0] )
            return straight_flush;
    }

    
    int NumerOfFace[4]={0,};
    int NumberOfSuit[13] = {0,};
    int SameFace_DiffSuit[13]={0,};
    
    for ( f = 0 ; f < 13 ; f ++ )
    {
        for ( s = 0 ; s < 4 ; s ++ )
        {
            NumerOfFace[ s ] += map[s][f] ;
            NumberOfSuit[ f ] += map[s][f] ;
        }
        
        SameFace_DiffSuit[ NumberOfSuit[ f ] ] ++;
        
        if ( NumberOfSuit[ f ] >= 4 )
            return four_of_a_kind;
    }
        
    if ( SameFace_DiffSuit[3] > 0 && SameFace_DiffSuit[2] > 0 )
        return full_house;
    
    for ( s = 0 ; s < 4 ; s ++)
        if ( NumerOfFace[ s ] == 5 )
            return flush;
    
    for ( f = 0 ; f < 10 ; f ++ )
        if ( NumberOfSuit[f] > 0 && 
                NumberOfSuit[f+1] > 0 && 
                NumberOfSuit[f+2] > 0 &&
                NumberOfSuit[f+3] > 0 &&
                NumberOfSuit[(f+4)%13] > 0 )
        {
            return straight;
        }
    
    if ( SameFace_DiffSuit[3] > 0 )
        return three_of_a_kind;
    if ( SameFace_DiffSuit[2] > 1 )
        return two_pairs;
    if ( SameFace_DiffSuit[2] > 0 )
        return one_pair;
    return highest_card;
}

int FaceToInt( char f )
{
    if ( f == 'A' ) return 0;
    else if ( '2' <= f && f <= '9' ) return f - '1';
    else if ( f == 'T' ) return  9;
    else if ( f == 'J' ) return 10;
    else if ( f == 'Q' ) return 11;
    else if ( f == 'K' ) return 12;
    
    return -1;
}
int SuitToInt( char s)
{
    if ( s == 'C' ) return 0;
    else if ( s == 'D' ) return 1;
    else if ( s == 'H' ) return 2;
    else if ( s == 'S' ) return 3;
    return -1;
}
void process( FILE *fp )
{
    while ( !feof( fp ) )
    {
        CARD card[10]={0,};
        for ( int i = 0 ; i < 10 ; i ++ )
            if ( fscanf(fp, "%c%c ", &(card[i].face), &(card[i].suit) ) != 2 )
                return ;
        CARD_TYPE bestType = highest_card;
        
        for ( int i = 0 ; Index[ i ][ 0 ] >= 0 ; i ++ )
        {
            int map[4][13]={0,};
            for ( int j = 0 ; j < 5 ; j ++ )
            {
                int y = SuitToInt( card[ Index[i][j] ].suit ) ;
                int x = FaceToInt( card[ Index[i][j] ].face ) ;
                
                if ( y >= 0 && x >= 0 )
                    map[ y ][ x ] = 1;
                //printf("%c%c ", card[ Index[i][j] ].suit, card[ Index[i][j] ].face );
            }
            
            CARD_TYPE score = GetScore(map);
            if ( bestType < score ) bestType = score ;
        }
        printf("Hand:");
        for ( int i = 0 ; i < 5 ; i ++ )
            printf(" %c%c", card[ i ].face, card[ i ].suit );
        printf(" Deck:");
        for ( int i = 5 ; i < 10 ; i ++ )
            printf(" %c%c", card[ i ].face, card[ i ].suit );
        
        printf(" Best hand: %s\n", GetScoreName(bestType));
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

