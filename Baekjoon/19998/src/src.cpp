#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/syscall.h>

using namespace std;

int A[10][10]={0,};

unsigned char check_col[9][10]={0,};
unsigned char check_row[9][10];
unsigned char check_inside[3][3][10];

struct Point 
{
    int y, x ;
    vector<int> available_numbers ;
    int choosed_num ;
    Point () {}
    Point(int y, int x) : y(y), x(x) {}
};
Point unassigned_points [91];
int nUnassignedPoints = 0 ;

bool is_set(int y, int x, int val)
{
    if ( check_col[x][val] ) return true ;
    if ( check_row[y][val] ) return true ;
    if ( check_inside[y/3][x/3][val] ) return true ;
    return false ;
}

void set_value(int y, int x, int val)
{
    A[y][x] = val ;

    check_col[x][val] = 1;
    check_row[y][val] = 1;
    check_inside[y/3][x/3][val] = 1;
}

void unset_value(int y, int x, int val)
{
    A[y][x] = 0 ;
    check_col[x][val] = 0;
    check_row[y][val] = 0;
    check_inside[y/3][x/3][val] = 0;
}

void setNumberOfAvailablePoints(Point &p)
{
    int i, j ;
    int cnt = 0 ;
    
    p.available_numbers.clear();
    for ( i = 1 ; i <= 9 ; i ++ )
        if ( !is_set(p.y, p.x, i )) 
            p.available_numbers.push_back(i);
}
bool is_finish(int idx)
{
    int i, j ;
    int n ;

    if ( idx == nUnassignedPoints )
    {
        for ( i = 0 ; i < 9 ; i ++ )
        {
            for ( j = 0 ; j < 9 ; j ++ )
                printf("%d ", A[i][j]);
            printf("\n");
        }
        return true;
    }
    return false ;
}

bool recur(int idx)
{
    int i, j, tail ;
    int n ;
    int row[9][10]={0,};
    int col[9][10]={0,};
    int inside[3][3][10]={0,};

    if ( is_finish(idx) ) return true ;
    
    for ( i = idx ; i < nUnassignedPoints ; i ++ )
    {
        Point &p = unassigned_points[i] ;
        setNumberOfAvailablePoints(p);
        if ( p.available_numbers.size() == 0 )
            return false ;
    }
    for ( i = idx ; i < nUnassignedPoints ; i ++ )
    {    
        Point &p = unassigned_points[i] ;
        for ( j = 0 ; j < unassigned_points[i].available_numbers.size() ; j ++ )
        {
            row[ p.y ][ p.available_numbers[j] ] ++;
            col[ p.x ][ p.available_numbers[j] ] ++;
            inside[ p.y / 3 ][ p.x / 3 ][ p.available_numbers[j] ] ++ ;
        }
    }
    // dump(idx);

    for (i = idx ; i < nUnassignedPoints ; i ++ )
    {
        Point &p = unassigned_points[i] ;
        
        for ( j = 0 ; j < unassigned_points[i].available_numbers.size() ; j ++ )
        if ( row[ p.y ][ p.available_numbers[j] ] == 1 || 
            col[ p.x ][ p.available_numbers[j] ] == 1 || 
            inside[ p.y / 3 ][ p.x / 3 ][ p.available_numbers[j] ] == 1 )
            {
                int y, x, n ;
                y = p.y ;
                x = p.x ;
                n = p.available_numbers[ j ] ;

                set_value( y, x, n );

                if ( i != idx ) 
                    std::swap( p, unassigned_points[idx]);
                // dump(idx);
                if ( recur(idx+1) ) return true ;

                unset_value( y, x, n );

                return false ;
            }
    }
    // if ( idx < nUnassignedPoints / 2)
    //     sort(unassigned_points + idx , unassigned_points+nUnassignedPoints, [](Point &a, Point &b){
    //         return a.available_numbers.size() < b.available_numbers.size();
    //     });
        sort(unassigned_points + idx , unassigned_points+nUnassignedPoints, [](Point &a, Point &b){
            return a.available_numbers.size() < b.available_numbers.size();
        });
    for ( i = 0 ; i < unassigned_points[idx].available_numbers.size() ; i ++ )
    {
        n = unassigned_points[idx].available_numbers[i];
        set_value( unassigned_points[idx].y, unassigned_points[idx].x, n);

        if ( recur( idx + 1 ) ) return true ;

        unset_value( unassigned_points[idx].y, unassigned_points[idx].x, n);
    }

    return false ;
}


void process2()
{
    int i, j ;
    int y, x , k;

    int n ;
    float max_t = -1 ;


    for ( y = 0 ; y < 9 ; y ++)
    for ( x = 0 ; x < 9 ; x ++ )
    {
        scanf("%d ", &k);
        if ( k != 0 )
            set_value(y, x, k);
    }

    for ( y = 0 ; y < 9 ; y ++)
    for ( x = 0 ; x < 9 ; x ++ )
    if ( A[y][x] == 0 )
    {
        unassigned_points[nUnassignedPoints].y = y ;
        unassigned_points[nUnassignedPoints].x = x ;
        nUnassignedPoints++;
    }

    bool ret = recur(0);
}
int main() 
{ 
#ifndef ONLINE_JUDGE 
    clock_t t = clock();
#else  
#endif 

    process2(); 

#ifndef ONLINE_JUDGE 
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);    
    printf("\n[Press Enter to Continue ...]");
    fflush(stdout);
    fflush(stdin);
#else 
#endif 
    return 0; 
} 


