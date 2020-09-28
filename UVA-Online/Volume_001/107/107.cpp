// 107 - The Cat in the Hat
/*
 * Input : H, N
 *  H : initial height of cat.
 *  N : number of working-cats
 * 
 *  working cat is smallest cats. ( Height=1)
 * 
 * 
 * H = 216.
 * N = 125.
 * 
 * how many cats in each hat ? (= y, unknown )
 * 
 * Cat #1. ( Height=H, 216)
 * 
 * Cat #2-1, #2-2, #2-3, ... #2-y ( Number of cats = y , Height = 216/(1+y) )
 * 
 * Cat #2-1-1, #2-1-2, #2-1-3, ..... #2-y-y ( Number of cats = y^2, Height = 216/(1+y)/(1+y) )
 * 
 * Cat #2-1-1-1, #2-1-1-2, #2-1-1-3, ..... #2-y-y-y ( Number of cats = y^3, Height = 216/(1+y)/(1+y)/(1+y) )
 * 
 *  ....
 * 
 * Cat #2-1-1-1-1-1.... #2-y-y-y-y-y... ( Number of cats = y^x = 125 :smallest cats. working cats. , Height = 1 )
 * 
 ************************************************************************
 * 
 * x = the number of cat generations  ( unknown )
 * y = the number of cats in each hat ( unknown )
 * H = the height of the bigger cat   ( input )
 * N = the number of worker cats      ( input )
 * 
 ************************************************************************
 * 
 * H = 216.
 * N = 125.
 * y = 5, x = 3;
 * 
 * Cat #1 : [ cats=1, height=216 ]
 * x=1    : [ cats=5, height=36 ]
 * x=2    : [ cats=25, height=6 ]
 * x=3    : [ cats=125, height=1 ]
 * 
 * Working Cats = 125.
 * not working Cats = 1 + 5 + 25 = 31.
 * total Height = 1*216 + 5*36 + 25*6 + 125*1 = 671
 * 
 ************************************************************************
 * 
 * H / { (y+1)^x } = 1
 * (y+1)^x = H 
 * 
 * y^x = N
 * 
 * x * log(y+1) = log(H)
 * x * log(y) = log(N)
 * 
 * log(H)/log(y+1) = log(N)/log(y)
 * 
 * log(H)*log(y) = log(N)*log(y+1)
 * log(H) / log(N) = log(y+1)/log(y)
 *                                      where y != 1, N != 1
 * 
 * if y == 1
 *      N = 1.
 *      2^x = H  
 * 
 * log(H) / log(N) = T
 * 
 * T * log(y) = log(y+1)
 * 
 * T = log(y+1)/log(y)
 * 
 * to solve the equation to find y. use the binary search 
 *    
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void process( FILE *fp )
{
    int H, N ;
    
    
    while ( fscanf(fp, "%d %d", &H, &N) == 2 )
    {
        int not_working=0;
        int total_height=0 ;

        if ( N == 0 && H == 0 )
            break;
        
        if ( H == 1 )
        {
            // height == 1 ? , the cat is smallest cat. = working cat. and height is 1. 
            not_working=0;
            total_height = 1 ;
        }
        else if ( N == 1 )
        {
            /**
            * (y+1)^x = H 
            * y^x = 1
             * 
             * y=1.
             * 
             * 
            * Cat #1 : [ cats=1, height=H ]       not working cat
            * Cat #2 : [ cats=1, height=H/(1+1) ] not working cat
            * Cat #3 : [ cats=1, height=H/(1+1)^2 ] not working cat
            * Cat #4 : [ cats=1, height=H/(1+1)^3 ] not working cat
            *  ...
            * Cat #x : [ cats=1, height=1 = 2^x=H ] working cat.
            * 
            */
            total_height+=H;
            for ( int h=1; h < H ; h *=2)
            {
                total_height += h;
                not_working++;
            }
        }
        else
        {
            double T = log(H) / log(N);
            double min_y=1.0l, max_y=10.0l , min_delta = 0.1l;
            double y, x, t ;
            int i ;
            
            for ( i = 0 ; i < 8 && ( log(max_y+1) / log(max_y) > T ) ; i ++)
                max_y *= 10.0l ;
            
            for ( i = 0 ; i < 8 && ( log(min_y + min_delta + 1) / log(min_y + min_delta) < T ) ; i ++)
                min_delta /= 10.0l;

            min_y = 1.0l + min_delta ;
            
            while ( min_y < max_y && min_y > 1.0l )
            {
                y = (min_y + max_y) / 2.0 ;
                t = log(y+1) / log(y) ;
                
                if ( fabs( t - T ) < 1.0e-8 )
                    break;
                else if ( t < T ) max_y = y;
                else if ( t > T ) min_y = y ;
                else
                    break;
            }
            
            y = (min_y + max_y)/2;
            x = log(N)/log(y);
            
#ifndef ONLINE_JUDGE 
            // printf("N=%d, H=%d, y = %lf, x = %lf\n", N, H, y, x );
#endif

            /**
            * Cat #1 : [ cats=1, height=216 ]
            * x=1    : [ cats=5, height=36 ]
            * x=2    : [ cats=25, height=6 ]
            * x=3    : [ cats=125, height=1 ]
            * 
            * Working Cats = 125.
            * not working Cats = 1 + 5 + 25 = 31.
            * total Height = 1*216 + 5*36 + 25*6 + 125*1 = 671
            */
            
            double sum_of_not_working_cats, sum_height, height;
            double cats = 1.0;
            sum_of_not_working_cats = 0 ;
            sum_height = N ;
            
            height = H;
            
            y = round(y);
            x = round(x);
            for ( cats = 1 ; cats < N ; cats *= y )
            {
                sum_of_not_working_cats += cats;
                sum_height += height*cats;
                height /= (y+1);
            }
            
            not_working = (int)sum_of_not_working_cats ;
            total_height = (int)sum_height ;
        }
        
        printf("%d %d\n", not_working, total_height);
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
