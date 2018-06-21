#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { BLUE, YELLOW, RED } LIGHT;

typedef struct _t 
{
    int cycle_time ;
    LIGHT light ;
    int duration_for_current_light;
} T ;
int get_remained_time_to_blue_light(T t)
{
    switch ( t.light )
    {
        case BLUE: return 0;
        case YELLOW: return 5 - t.duration_for_current_light + t.cycle_time ;
        case RED: return t.cycle_time - t.duration_for_current_light;
    }
    return 0;
}
int duration(T time[], int n, int passed_time )
{
    int additional_time ;
    int remained_time ;
    LIGHT next_light ;
    int all_blue = 1 ;
    for ( int i = 0 ; i < n ; i ++ )
    {
        additional_time = passed_time % ( time[ i ].cycle_time * 2 );
        while ( additional_time > 0 )
        {
            switch ( time[ i ].light )
            {
                case BLUE : 
                    remained_time = time[ i ].cycle_time - 5 - time[ i ].duration_for_current_light ;
                    next_light = YELLOW ;
                break;

                case YELLOW : 
                    remained_time = 5 - time[ i ].duration_for_current_light;
                    next_light = RED ;
                break;

                case RED : 
                    remained_time = time[ i ].cycle_time - time[ i ].duration_for_current_light;
                    next_light = BLUE ;
                break;
            }

            if ( additional_time >= remained_time )
            {
                additional_time -= remained_time;
                time[ i ].duration_for_current_light = 0;
                time[ i ].light = next_light;
            }
            else
            {
                time[ i ].duration_for_current_light += additional_time ;
                additional_time = 0;
            }
        }
        if ( time[i].light != BLUE )
            all_blue = 0 ;        
    }
    return all_blue;
}

char get_light(T t)
{
    if ( t.light == BLUE ) return 'B';
    if ( t.light == YELLOW ) return 'y';
    if ( t.light == RED ) return 'r';
}

void pr_hour(int t)
{
    int h, m, s ;
    s = t % 60 ; t -= s ;
    m = (t % 3600) / 60 ; t -= m * 60 ;
    h = t / 3600;
    printf("%02d:%02d:%02d\n", h, m, s);
}

void dump(T time[], int n, int t )
{
    int h, m, s ;
    s = t % 60 ; t -= s ;
    m = (t % 3600) / 60 ; t -= m * 60 ;
    h = t / 3600;

    printf("--------------------------------------\n");
    printf(" Current : %02d:%02d:%02d\n", h, m, s);

    for ( int i = 0; i < n ; i ++)
        printf("%c : %d\n", get_light(time[i]), time[i].duration_for_current_light);
}

void process(FILE *fp)
{
    while ( 1 )
    {
        T time[1024]={0,};
        int n ;
        int s ;

        s = 0x7FFFFFFF;
        for ( n = 0 ; ; n ++ )
        {
            fscanf(fp, "%d ", &(time[n].cycle_time) );
            if ( time[n].cycle_time == 0 )
                break;
            if ( time[n].cycle_time < s )
                s = time[n].cycle_time;
        }
        if ( time[0].cycle_time == 0 && time[1].cycle_time == 0 && time[2].cycle_time == 0 )
            break;
        if ( s > 1 )
        {
            duration(time, n, s);
        }

        //dump(time, n, s);

        while ( 1 )
        {
            int next_s  = 0;
            int all_blue ;

            for ( int i = 0 ; i < n ; i ++ )
            {
                int t = get_remained_time_to_blue_light( time[ i ] );
                if ( next_s < t ) next_s = t;
            }

            all_blue = duration(time, n, next_s );
            s += next_s ;
            //dump(time, n, s );
            if ( s > 18000 )
            {
                printf("Signals fail to synchronise in 5 hours\n");
                break;
            }
            else if ( all_blue )
            {
                pr_hour(s);
                break;
            }
        }
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