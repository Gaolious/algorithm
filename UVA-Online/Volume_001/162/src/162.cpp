#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Simulation
  player [26] 2 7 12 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 0]
  dealer [26] 2 10 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

=>player [25] 7 12 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 1] 2 
  dealer [26] 2 10 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

  player [25] 7 12 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 2] 2 2 
=>dealer [25] 10 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

=>player [24] 12 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 3] 7 2 2 
  dealer [25] 10 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

  player [24] 12 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 4] 10 7 2 2 
=>dealer [24] 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 


=>player [23] 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 5] 12 10 7 2 2 
  dealer [24] 8 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 
// need to cover (2)

  player [23] 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 6] 8 12 10 7 2 2 
=>dealer [23] 10 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 
// rank 8 can't cover 12, (1)

  player [23] 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 
   table [ 7] 10 8 12 10 7 2 2 
=>dealer [22] 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 
// rank 10 can't cover 12, (0)

  player [30] 3 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 [ 2 2 7 10 12 8 10 ]
   table [ 0] 
  dealer [22] 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

=>player [29] 13 14 3 13 4 5 3 2 8 11 9 13 9 10 7 12 7 4 5 13 4 14 2 2 7 10 12 8 10 
   table [ 1] 3 
  dealer [22] 12 14 9 9 12 11 7 2 8 6 6 8 10 6 11 4 11 5 6 5 14 3 

*/

int Rank2Int(char rank)
{
    if ( rank >= '2' && rank <='9' ) return rank - '0' ;

    if ( rank == 't' || rank == 'T' ) return 10;
    if ( rank == 'j' || rank == 'J' ) return 11;
    if ( rank == 'q' || rank == 'Q' ) return 12;
    if ( rank == 'k' || rank == 'K' ) return 13;
    if ( rank == 'a' || rank == 'A' ) return 14;
    return 0;
}

#define QUEUE_SIZE (100)
class CARD_QUEUE
{
    int queue[QUEUE_SIZE];
    int size;
    int head, tail;
public:    
    int count() { return this->size; }

    void initialize()
    {
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }
    void push_back(int c)
    {
        this->size++;
        this->queue[ this->tail ] = c ;
        this->tail = ( this->tail + 1 + QUEUE_SIZE) % QUEUE_SIZE;
    }
    void push_front(int c )
    {
        this->size++;
        this->head = ( this->head - 1 + QUEUE_SIZE ) % QUEUE_SIZE ;
        this->queue[ this->head ] = c;
    }
    bool empty() { return this->size <= 0; }
    int front()
    {
        return this->queue[ this->head ];
    }
    int pop_front() 
    { 
        int ret = this->queue[ this->head ];
        this->head = ( this->head + 1 + QUEUE_SIZE ) % QUEUE_SIZE ; 
        this->size--;
        return ret;
    }
    int pop_back() 
    {
        this->tail = ( this->tail - 1 + QUEUE_SIZE ) % QUEUE_SIZE ; 
        this->size--;
        return this->queue[ this->tail  ];
    }

    void dump(const char *name, bool is_turn)
    {
        int i;

        if ( is_turn )
            printf("=>%6s [%2d] ", name, this->size );
        else
            printf("  %6s [%2d] ", name, this->size );

        for ( i = this->head ; i != this->tail ; i = ( i + 1 + QUEUE_SIZE ) % QUEUE_SIZE )
            printf("%d ", this->queue[ i ] );
        printf("\n");
    }
} ;

void play2(CARD_QUEUE &player, CARD_QUEUE &dealer)
{
    const int TURN_PLAYER = 0;
    const int TURN_DEALER = 1;
    CARD_QUEUE table;
    CARD_QUEUE *prev, *curr, *cover_player ;

    int turn ;
    int table_front = -1;
    int cover_count = 0 ;

    table.initialize();

    for ( turn = 0 ; ; )
    {
        if ( turn == TURN_PLAYER )
            prev = &dealer, curr = &player ;
        else
            curr = &dealer, prev = &player ;
        if ( curr->empty() ) break;
        table.push_front( curr->pop_front() );
        table_front = table.front();
        cover_count = table_front < 11 ? cover_count : table_front - 10 ;
        if ( table_front > 10 ) cover_player = curr ;

        // player.dump("player", turn == TURN_PLAYER );
        // table.dump("table", false );
        // dealer.dump("dealer", turn == TURN_DEALER );    
        // printf("\n");    

        if ( cover_count > 0 )
        {
            if ( table.front() > 10 ) 
                turn = 1 - turn ;
            else
            {
                cover_count --;
                if ( cover_count == 0 )
                {
                    while ( ! table.empty() )
                        cover_player->push_back( table.pop_back() );
                    turn = 1 - turn ;                
                }
            }
        }
        else
            turn = 1 - turn ;            
    }
}

void process(FILE *fp)
{
    char suit, rank ;
    int i ;
    int turn = 0;

    while ( fscanf(fp, "%c", &suit) == 1 && suit != '#' )
    {
        turn = 0;
        CARD_QUEUE player, table, dealer;
            
        player.initialize();
        dealer.initialize();

        fscanf(fp, "%c ", &rank);
        
        player.push_front( Rank2Int(rank) );

        for ( i = 1 ; i < 52 ; i ++ )
        {
            fscanf(fp, "%c %c ",&suit ,&rank );
            
            if ( i % 2 == 1 ) 
                dealer.push_front( Rank2Int(rank) );
            else
                player.push_front( Rank2Int(rank) );
        }

        play2(player, dealer);

        if ( player.empty() ) 
            printf("1%3d\n", dealer.count() );
        else
            printf("2%3d\n", player.count() );
    }
}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}