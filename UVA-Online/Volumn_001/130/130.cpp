// 130 - Roman Roulette
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* n > 0 people are initially arranged in a circle, facing inwards, and numbered from 1 to n.
*
* The numbering from 1 to n proceeds consecutively in a clockwise direction.
*
* Your allocated number is 1. Starting with person number i, counting starts in a clockwise direction,
* until we get to person number k (k > 0), who is promptly killed.
*
* We then proceed to count a further k people in a clockwise direction,
* starting with the person immediately to the left of the victim.
*
* The person number k so selected has the job of burying the victim,
* and then returning to the position in the circle that the victim had previously occupied.
* Counting then proceeeds from the person to his immediate left, with the k-th person being killed, and so on,
* until only one person remains.
*
* For example, when n = 5, and k = 2, and i = 1, the order of execution is 2, 5, 3, and 1. The survivor is 4.
*
*  INIT : 1, 2, 3, 4, 5
*
* in case of i = 1
*
*  [ 1, 2, 3, 4, 5 ]
*      start [1] /  k-th person=2 to kill /  further k-th people( 4 ) replace / next start 3 (left 4)
*
*  [ 1, 4, 3,  , 5 ]
*      start [3] /  k-th person=5 to kill /  further k-th people( 4 ) replace / next start 1 (left 4)
*
*  [ 1,  , 3,  , 4 ]
*      start [1] /  k-th person=3 to kill /  further k-th people( 1 ) replace / next start 4 (left 1)
*
*  [  ,  , 1,  , 4 ]
*      start [4] /  k-th person=1 to kill /  one person remained : 4.
*
*
* in case of i = 2
*
*  [ 1, 2, 3, 4, 5 ]
*      start [2] /  k-th person=3 to kill /  further k-th people( 5 ) replace / next start 4 (left 5)
*
*  [ 1, 2, 5, 4,   ]
*      start [4] /  k-th person=1 to kill /  further k-th people( 5 ) replace / next start 2 (left 5)
*
*  [ 5, 2,  , 4,   ]
*      start [2] /  k-th person=4 to kill /  further k-th people( 2 ) replace / next start 5 (left 2)
*
*  [ 5,  ,  , 2,   ]
*      start [5] /  k-th person=2 to kill /  one person remained : 5.
*
*
* in case of i = 3
*
*  [ 1, 2, 3, 4, 5 ]
*      start [3] /  k-th person=4 to kill /  further k-th people( 1 ) replace / next start 5 (left 1)
*
*  [  , 2, 3, 1, 5 ]
*      start [5] /  k-th person=2 to kill /  further k-th people( 1 ) replace / next start 3 (left 1)
*
*  [  , 1, 3,  , 5 ]
*      start [3] /  k-th person=5 to kill /  further k-th people( 3 ) replace / next start 1 (left 3)
*
*  [  , 1,  ,  , 3 ]
*      start [1] /  k-th person=3 to kill /  one person remained : 1.
*
*/
#ifndef ONLINE_JUDGE
//#define _MBCS_DEBUG_
#endif

int nth_pos(int arr[], int start_pos, int len, int nth)
{
	int i;
	int cnt = 0;

	for (i = 0;; i++)
	{
		if (arr[(start_pos + len + i) % len] > 0) cnt++;
		if (nth <= cnt) return (start_pos + len + i) % len;
	}
	return -1;
}

int nth_inverse_pos(int arr[], int start_pos, int len, int nth)
{
	int i;
	int cnt = 0;

	for (i = 0;; i++)
	{
		if (arr[(start_pos + len - i) % len] > 0) cnt++;
		if (nth <= cnt) return (start_pos + len - i) % len;
	}
	return -1;
}
#ifndef ONLINE_JUDGE
void print(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%3d ", arr[i]);
	printf("\n");
}
#endif
void process( FILE *fp )
{
    int n, k;
    int i, j;
    while ( fscanf(fp, "%d %d ", &n, &k ) == 2 && ( n || k ) )
    {
        if ( n == 1 )
        {
            printf("1\n");
            continue ;
        }
        else
        {
            int circle[101]={0,};
            for ( i = 0 ; i < n ; i ++)
            {
                for ( j = 0 ; j < n ; j ++)
                    circle[ j ] = j + 1 ;


				int first_number_is_killed = 0;
                int start_idx = i ;
                int kill_idx ;
                int replace_idx ;
                int circle_size = n ;
				int remains = n;
#ifdef _MBCS_DEBUG_
				printf("Size : %d , k : %d\n", n, k );
#endif

                while (remains > 1 )
                {
					kill_idx = nth_pos(circle, start_idx, circle_size, k);
					if (kill_idx < 0) break;

                    int kill_number = circle[ kill_idx ] ;
#ifdef _MBCS_DEBUG_
					printf("Start Idx : %d\n", start_idx);
					print(circle, circle_size);
					printf("Kill Number : %d\n", kill_number);
#endif
					if (kill_number == 1)
					{
						first_number_is_killed = 1;
						break;
					}

                    circle[ kill_idx ] = -1;

					remains--;

					if (remains <= 1)
						break;

					replace_idx = nth_pos(circle, kill_idx, circle_size, k);
					int replace_number = circle[replace_idx];
#ifdef _MBCS_DEBUG_
					print(circle, circle_size);
					printf("replace_number : %d\n", replace_number);
#endif
					circle[replace_idx] = -1;

                    circle[ kill_idx ] = replace_number;
					start_idx = (kill_idx + 1) % circle_size;
#ifdef _MBCS_DEBUG_
					print(circle, circle_size);
#endif
				}
            
				if (first_number_is_killed == 0)
				{
					printf("%d\n", i + 1);
					break;
				}
			}
        }
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

#if _MBCS
	getchar();
#endif
    return 0;
}
