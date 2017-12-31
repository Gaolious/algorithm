#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cstdio>
#include <queue>
using namespace std;

void input(FILE *fp)
{
    const int MaxQueueSize = 100;

    int N, K ;
    
    while ( fscanf(fp, "%d %d ", &N, &K) == 2 )
    {
        int coin, NextCoin;
        int studentNo;
        int Money[26]={0,};
        int Queue[MaxQueueSize]={0,};
        int head, tail;
        
        if ( N == 0 && K == 0 )
            break;
        
        for ( head=tail=0 ; tail < N ; tail ++)
            Queue[tail] = tail + 1;
        
        coin = 0;
        NextCoin = 1;
        for ( ; head != tail ; )
        {
            studentNo = Queue[head];
            head = ( head + 1 ) % MaxQueueSize ;
            
            if ( coin == 0 )
            {
                coin = NextCoin;
                //printf("Student[%d]=%d, Current Coin[%d] => Will %d\n", studentNo, Money[studentNo], coin, Money[studentNo]+ coin);
                NextCoin = NextCoin % K + 1;
            }
            else
            {
                //printf("Student[%d]=%d, Remain Coin[%d] => Will %d\n", studentNo, Money[studentNo], coin, Money[studentNo]+ coin);
            }
            
            if ( Money[ studentNo ] + coin >= 40 ) 
            {
                coin = Money[ studentNo ] + coin - 40 ;
                Money[ studentNo ] = 40;
            }
            else
            {
                Money[ studentNo ] += coin ;
                coin = 0;
            }
            
            if ( Money[ studentNo ] >= 40 )
            {
                printf("%3d", studentNo );
            }
            else
            {
                Queue[tail] = studentNo ;
                tail = ( tail + 1 ) % MaxQueueSize ;
            }
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
    input(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
