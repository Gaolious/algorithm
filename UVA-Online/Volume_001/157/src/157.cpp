#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <queue>

#define MAX_NODE_SIZE (702) // = 26 * 26 + 26 ;

std::list<int> node[ MAX_NODE_SIZE ] ;
std::list<int> trans[ MAX_NODE_SIZE ] ;

int node_to_int(char line, char station)
{
    return ( line - 'A' ) * 26 + station - 'a' ;
}
void int_to_node(int i, char &line, char &station)
{
    line = i / 26 + 'A' ;
    station = i % 26 + 'a' ;
}

void set_trans_info( int s, int e ) 
{
    char a, b, c, d;

    int_to_node(s, a, b);
    int_to_node(e, c, d);
    if ( a == c )
    {
        node[s].push_back(e);
        node[e].push_back(s);
    }
    else
    {
        trans[s].push_back(e);
        trans[e].push_back(s);
    }
}

void update_trans()
{
    char a, b, c, d;

    for ( int s = 0 ; s < MAX_NODE_SIZE ; s ++ )
    {
        std::vector<int> q;
        std::list<int>::iterator iter;

        char check[MAX_NODE_SIZE+1] = {0,};
        int i = 0 ;

        q.push_back(s);
        check[s] = 1;
        int_to_node(s, a, b);


        for ( i = 0 ; i < q.size() ; i ++ )
        {
            for( iter = trans[ q[i] ].begin() ; iter != trans[ q[i] ].end() ; iter ++ )
            if ( check[ *iter ] == 0 )
            {
                q.push_back( *iter );
                check[ *iter ] = 1 ;
            }
        }

        if ( q.size() > 1 )
        {
            for ( std::vector<int>::iterator j = q.begin() ; j != q.end() ; j ++ )
                if ( s != *j)
                    node[ s ].push_back(*j);
        }
    }
}
void parse_line(char line, char stations[])
{
    int i;
    char first_station = 0x00 ;
    char previous_station = 0x00;
    char s;
    char connected_line ;

    previous_station = first_station = stations[ 0 ] ;
    int len = strlen(stations);

    for ( i = 1 ; i < len && stations[ i ]  ; i ++ )
    {
        s = stations[ i ];

        while ( s == '=')
        {
            s = previous_station;

            set_trans_info( node_to_int(line, s), node_to_int(stations[i+1], stations[i+2]) );

            i+=3;
            if ( i >= len ) return;
            s = stations[ i ];
        }

        set_trans_info( node_to_int(line, previous_station), node_to_int(line, s) );
        previous_station = s;
    }
}

void dijkstra(int s, int e)
{
    std::list<int>::iterator i, j ;
    std::queue<int> Q ;
    int dist[ MAX_NODE_SIZE + 1 ];
    int path[ MAX_NODE_SIZE + 1 ];
    int src ;
    char src_line, src_station ;
    int dest ;
    char dest_line, dest_station;

    for ( int a = 0 ; a < MAX_NODE_SIZE ; a ++)
    {
        dist[ a ] = -1 ;
        path[ a ] = -1 ;
    }

    Q.push(s);
    dist[s] = 0;
    path[s] = s;

    while ( ! Q.empty() )
    {
        src = Q.front();
        Q.pop();

        int_to_node(src, src_line, src_station);
        // printf("Src : %c:%c\n", src_line, src_station);

        for ( i = node[src].begin() ; i != node[src].end() ; i ++ )
        {
            dest = *i ;
            int_to_node(dest, dest_line, dest_station);
            
            int cost = src_line == dest_line ? 1 : 3 ;


            // printf("\tTry : %c:%c,  dist(src):%d, dist(dest):%d, cost : %d\n", dest_line, dest_station, dist[src], dist[dest], cost);

            if ( dist[ dest ] < 0 || dist[ dest ] > dist[ src ] + cost )
            {
                dist[ dest ] = dist[ src ] + cost;
                path[ dest ] = src ;
                Q.push(dest);
                // printf("\tpush back : %c:%c, dist : %d\n", dest_line, dest_station, dist[dest]);
            }
        }
    }

    printf("%3d: ", dist[e]);
    
    std::list<int> p ;
    dest = e ;
    do 
    {
        p.push_front(dest);
        if ( path[dest] == dest ) 
            break;
        dest = path[dest];
    } while ( dest >=0 );

    dest_line = src_line = -1;

    for ( i = p.begin() ; i != p.end() ; i ++ )
    {
        int_to_node(*i, dest_line, dest_station);
        if ( src_line < 0 )
            printf("%c%c", dest_line, dest_station);
        else if ( src_line == dest_line)
            printf("%c", dest_station);
        else
            printf("=%c%c", dest_line, dest_station);

        src_line = dest_line;
    }
    printf("\n");
    // printf("%c:%c -> %c:%c dist : %d\n", src_line, src_station, dest_line, dest_station, dist[e]);
}

void process(FILE *fp)
{
    /*
4
A:fgmpnxzabjd=Dbf
D:b=Adac=Ccf
B:acd=Azefg=Cbh
C:bac
AgAa
AbBh
BhDf
#    
    */
    int N ;
    int i ;
    char in[1024]={0,};

    while ( fscanf(fp, "%d ", &N) == 1 )
    {
        for ( i = 0 ; i < N ; i ++ )
        {
            
            char line;
            if ( fscanf(fp, "%c: %s ", &line, in) == 2 )
                parse_line(line, in );
        }
    }
#if 0
    for  ( int s = 0 ; s < MAX_NODE_SIZE ; s ++ )
    {
        for ( std::list<int>::iterator i = node[s].begin() ; i != node[s].end() ; i ++ )
        {
            char a, b, c, d;

            int_to_node(s, a, b );
            int_to_node(*i, c, d );

            printf("%c:%c -> %c:%c\n", a, b, c, d);
        }
    }
#endif    
    update_trans();

    while ( fscanf(fp, "%s ", in) == 1 && in[0] != '#' )
    {
        int s = node_to_int(in[0], in[1]), e = node_to_int(in[2], in[3]);
        dijkstra(s, e);
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