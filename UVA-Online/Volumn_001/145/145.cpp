#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double rate[5][4] = {
    {0.02, 0.1, 0.06, 0.02,},
    {0.05, 0.25, 0.15, 0.05,},
    {0.13, 0.53, 0.33, 0.13,},
    {0.17, 0.87, 0.47, 0.17,},
    {0.30, 1.44, 0.80, 0.30,}
};

int range[][2] = {
    {    0,  8*60 },
    { 8*60, 18*60 }, 
    {18*60, 22*60 },
    {22*60, 24*60 },
};

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

void input(FILE *fp)
{
    char c, phoneNumber[9];
    int start_hour, start_minute, end_hour, end_minute;
    
    while ( fscanf(fp, "%c ", &c ) == 1 )
    {
        if ( c == '#' )
            break;
        fscanf(fp, "%s %d %d %d %d ", phoneNumber, &start_hour, &start_minute, &end_hour, &end_minute );
        
        if ( start_hour * 60 + start_minute >= end_hour * 60 + end_minute )
        {
            end_hour += 24;
        }
        c = c - 'A';
        
        int sum_minute[4]={0,};
        double sum_rate = 0.0;
        
        int s, e;
        
        s = start_hour * 60 + start_minute ;
        e = end_hour * 60 + end_minute ;
            
        for ( int day = 0 ; day < 2 ; day ++ )
        for ( int i = 0 ; i < 4 ; i ++ )
            if ( day*24*60 + range[i][0] <= s && s <= day*24*60 + range[i][1] )
            {
                int l = min(e, day*24*60 + range[i][1]);
                int t = max(0, l - s );

//                printf("Calculate[%c] [%d][%02d:%02d ~ %02d:%02d] / %02d:%02d ~ %02d:%02d : %d minutes  / End:  %02d:%02d\n", 
//                        c + 'A', 
//                        i,
//                        range[i][0]/60, range[i][0]%60,
//                        range[i][1]/60, range[i][1]%60,
//                        s/60, s%60,
//                        l/60, l%60,
//                        t, 
//                        e/60, e%60
//                    );
                sum_minute [ i ] += t;
                sum_rate += t * rate[c][i];
                s = l;
            }
            
        printf("%10s%6d%6d%6d%3c%8.2lf\n", phoneNumber, 
                sum_minute[1], 
                sum_minute[2], 
                sum_minute[0]+sum_minute[3], 
                c + 'A',
                sum_rate
                );
    }
}


int main()
{
#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif
    input(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
