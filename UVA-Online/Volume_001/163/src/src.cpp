#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex>

const int BLOCK_SIZE = 50 ;

//north (N), northeast (NE), east (E), southeast (SE), south (S), southwest (SW), west (W) and northwest (NW).    
//           N, NE,  E, SE, S, SW, W, NW
int dx[] = { 0,  1, 1,  1, 0, -1, -1, -1 };
int dy[] = { 1,  1, 0, -1, -1, -1,  0, 1 };
const char dir_map[8][5]={
    "N", "NE", "E", "SE", "S", "SW", "W", "NW"
};
typedef struct _poistion_ POSITION ;
struct _poistion_ {
    int x, y ;
    int dir ;
    char tmp[1024];
    void dump()
    {
        int y, x ;

        printf("\n");
        printf("curr => %s\n", this->dumpStr());
        for ( x = -BLOCK_SIZE ; x <= BLOCK_SIZE ; x ++ )
            printf("%c", abs(x) % 10 == 0 ? '+' : '0' + abs(x)%10 );
        printf("\n");
        for ( y = BLOCK_SIZE ; y >= -BLOCK_SIZE ; y -- )
        {
            for ( x = -BLOCK_SIZE ; x <= BLOCK_SIZE ; x ++ )
            {
                if ( this->y == y && this->x == x )
                    printf("%d", this->dir);
                else
                {
                    if ( y == 0 && x ) printf("-");
                    else if ( x == 0 && y ) printf("|");
                    else if ( (y+x) % BLOCK_SIZE == 0 && (y-x) % BLOCK_SIZE == 0 ) printf("X");
                    else if ( (y-x) % BLOCK_SIZE == 0 ) printf("/");
                    else if ( (y+x) % BLOCK_SIZE == 0 ) printf("\\");
                    else printf(".");
                }
            }
            printf("\n");
        }
    }
    char *dumpStr()
    {
        sprintf(tmp, "A%d%C S%d%C %s", 
            abs(this->x), 
            x < 0 ? 'W' : 'E', 
            abs(this->y), 
            y < 0 ? 'S' : 'N',
            dir_map[this->dir]
        );
        return tmp;
    }
    void move(int dist=1)
    {
        this->x += dx[ this->dir ] * dist ;
        this->y += dy[ this->dir ] * dist ;
    }
    bool is_stopable()
    {
        return !( this->is_throughway() );
    }
    bool valid_position()
    {
        if ( this->x < -BLOCK_SIZE || this->x > BLOCK_SIZE ) return false ;
        if ( this->y < -BLOCK_SIZE || this->y > BLOCK_SIZE ) return false ;
        return true ;
    }

    bool is_circle()
    {
        return ( this->x % BLOCK_SIZE == 0 && this->y % BLOCK_SIZE == 0 );
    }

    bool is_throughway()
    {
        int tx, ty ;

        tx = dx[this->dir] ;
        ty = dy[this->dir] ;

        if ( this->x % BLOCK_SIZE == 0 && tx == 0 ) return true ;
        if ( this->y % BLOCK_SIZE == 0 && ty == 0 ) return true ;
        // y = -x 
        if ( ( this->y + this->x ) % (2*BLOCK_SIZE) == 0 && tx && ty && tx == -ty ) return true ;
        if ( ( this->y - this->x ) % (2*BLOCK_SIZE) == 0 && tx && ty && tx == ty ) return true ;
        return false ;
    }

    bool is_boulevard() // diagonally
    {
        int ax, ay ;
        int tx, ty ;
        bool ret = true ;

        tx = dx[this->dir] ;
        ty = dy[this->dir] ;
        
        if ( tx && ty )
        {
            if ( abs(this->y + this->x ) == BLOCK_SIZE  && tx == -ty ) return true ;
            if ( abs(this->y - this->x ) == BLOCK_SIZE  && tx == ty ) return true ;
            if ( ( this->y + this->x ) % (2*BLOCK_SIZE) == 0 && tx == -ty ) return true ;
            if ( ( this->y - this->x ) % (2*BLOCK_SIZE) == 0 && tx == ty ) return true ;                
        }        
        return false ;
    }
    bool is_avenue()
    {
        if ( dx[this->dir] == 0) return true ;
        return false ;
    }
    bool is_street()
    {
        if ( dy[this->dir] == 0) return true ;
        return false ;
    }
    
    bool canMove( POSITION *next)
    {
        bool is_enter = false ;
        bool is_leave = false ;
        bool half_left = false ;
        bool left = false ;
        bool sharp_left = false ;

        // sharp left
        if ( (this->dir - 3 + 8 ) % 8 == next->dir ) sharp_left = true ;
        // left
        else if ( (this->dir - 2 + 8 ) % 8 == next->dir ) left = true ;
        // half left ??
        else if ( (this->dir - 1 + 8 ) % 8 == next->dir ) half_left = true ;

        if ( (this->is_circle() || this->is_throughway() ) && ( !next->is_circle() && !next->is_throughway() ) )
            is_leave = true ;
        if ( ( !this->is_circle() && !this->is_throughway() ) && ( next->is_circle() || next->is_throughway() ) )
            is_enter = true ;

        if ( next->is_circle() ) 
            return true ;
        else if ( is_leave || is_enter )
        {
            if (this->is_boulevard() || next->is_boulevard() )
                return sharp_left == true;
            else
                return half_left || left || sharp_left ;
        }
        else if ( next->is_avenue() || next->is_street() || next->is_boulevard() )
            return true ;
        else
            return false ;
    }
}  ;

int get_dir(char *dir)
{
    for ( int i = 0 ; i < 8 ; i ++ )
    if ( strcmp(dir_map[i], dir) == 0 )
        return i ;
    return -1;
}
#define min( a, b ) ( (a) < (b) ? (a) : (b))
#define max( a, b ) ( (a) > (b) ? (a) : (b))

char *parseInt(char *position, int *val)
{
    int n=0;
    int MIN = -(BLOCK_SIZE * 2 + 1 );
    int MAX = (BLOCK_SIZE * 2 + 1 );
    for ( n = 0 ; '0' <= *position && *position <= '9' ; position ++ )
    {
        n = n * 10 + *position - '0' ;
        n = max( n, MIN );
        n = min( n, MAX );
    }
    *val = n ;
    return position;
}

char *skip_word(char *p)
{
    while (p && *p && *p != ' ') p++;
    while (p && *p && *p == ' ') p++;
    return p;
}
int strip(char **p, int len)
{
    while ( len > 0 && *p && **p && (*p)[len-1] == '\n')
        (*p)[--len] = 0x00;
    while ( len > 0 && *p && **p && **p == ' ' ) 
        (*p)++, len--;
    return len;
}
bool is(char **p, const char *command)
{
    int len = strlen(command);
    while (*p && **p && **p == ' ') (*p)++;
    if ( strncmp(*p, command, len) == 0 )
    {
        *p = skip_word( *p + len );
        return true ;
    }
    else
        return false ;
}

bool set_init(char *position, POSITION *p)
{
    int n = 0;

    // A[0-9]+[WE]
    if ( *position == 'A' )
    {
        position = parseInt( position + 1, &n );
        
        if ( *position == 'W' )
            p->x = -n;
        else if ( *position == 'E' )
            p->x = n ;
        return true ;
    }
    // S[0-9]+[NS]
    else if ( *position == 'S' )
    {
        position = parseInt( position + 1, &n );
        
        if ( *position == 'N' )
            p->y = n;
        else if ( *position == 'S' )
            p->y = -n ;
        return true ;
    }
    return false ;
}

void process()
{
    char command [100]={0,};
    while ( fgets(command, sizeof(command)-1, stdin))
    {
        POSITION pos ;
        char *p = command;
        int len = strip(&p, strlen(command));
        if ( is(&p, "END") ) break;

        if (!set_init(p, &pos)) continue;
        p = skip_word(p);
        if (!set_init(p, &pos)) continue;
        p = skip_word(p);
        pos.dir = get_dir(p);
        if (pos.dir < 0 ) continue ;

#ifdef AJAVA_DEBUG
        pos.dump();
#endif

        while ( fgets(command, sizeof(command)-1, stdin) )
        {
            p = command;
            len = strip(&p, strlen(command));
            POSITION next = pos ;

#ifdef AJAVA_DEBUG
            printf("\n[%15s] [%15s] ", pos.dumpStr(), p);
#endif            
            if ( is(&p, "STOP") )
            {
                break;
            }
            else if ( is(&p, "TURN") )
            {
                // These are elevated for most of their length, 
                // thus it is possible to cross them easily, 
                // 
                // however they always intersect each other at a circle, which is shared by all other roads that meet at that intersection. 
                // You may only enter or leave them by turning left (sharp left in the case of boulevards). 
                //         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ambiguous !!!!!!!!!!!!!!!!!!!
                // You may not stop on them for any reason. There are no restrictions on turns for other roads.
                //
                int delta = 2;
                bool is_left = false ;
                next.move();
                if ( is(&p, "HALF") )
                    delta = 1;
                else if ( is(&p, "SHARP") )
                    delta = 3;

                if ( is(&p, "LEFT") ) is_left=true, delta *= -1;
                else if ( is(&p, "RIGHT") ) is_left=false, delta = delta;

                next.dir = ( next.dir + 8 + delta ) % 8 ;

                if ( pos.canMove(&next)  && *p == 0x00 )
                {
                    pos = next ;
                }
            }
            else if ( is(&p, "GO") )
            {
                int val ;

                if ( is(&p, "STRAIGHT" ) ) {}

                p = parseInt(p, &val);
                if ( 1 <= val && val <= 99 && *p == 0x00 )
                {
                    next.move(val);
                    if ( next.valid_position() )
                    {
                        pos = next ;                    
                    }
                }

            }

#ifdef AJAVA_DEBUG
        pos.dump();
#endif


        } // end of while ( fgets(command, sizeof(command)-1, stdin) && strncmp(command, "END", 3) != 0 )
        
        POSITION next = pos ;
        next.move();

        if ( pos.is_stopable())
            printf("%s\n", pos.dumpStr());
        else
            printf("Illegal stopping place\n");
    }
}

int main() 
{
    process();     

    return 0;
}

