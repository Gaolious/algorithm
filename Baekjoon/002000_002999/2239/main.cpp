#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
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
    bool is_set ;
    int y, x ;
    vector<int> available_numbers ;
    Point(int y, int x) : y(y), x(x), is_set(false) {}
};
vector<Point> unassigned_points ;

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
bool is_finish(vector<Point>::iterator curr)
{
    int i, j ;
    int n ;

    if ( curr == unassigned_points.end() )
    {
        for ( i = 0 ; i < 9 ; i ++ )
        {
            for ( j = 0 ; j < 9 ; j ++ )
                cout << A[i][j];
            cout << '\n';
        }
        return true;
    }
    return false ;
}

Point *getAvailablePoints(int y, int x)
{
    for ( auto i = unassigned_points.begin() ; i != unassigned_points.end() ; i ++ )
        if ( i->y == y && i->x == x )
            return &(*i);
    return NULL ;
}

bool recur(vector<Point>::iterator curr, int depth = 1)
{
    int i, j ;
    int n ;

    vector<Point>::iterator loop, start, tail, next ;
    start = curr ;
    tail = curr ;

    if ( is_finish(start) ) return true ;

    for ( loop = start ; loop != unassigned_points.end() ; loop ++ )
    {
        setNumberOfAvailablePoints(*loop);
        if ( loop->available_numbers.size() == 0 )
            return false ;
    }

    if ( is_finish(start) ) return true ;

    start->is_set = true ;
    for ( i = 0 ; i < start->available_numbers.size() ; i ++ )
    {
        n = start->available_numbers[i];
        set_value( start->y, start->x, n);

        if ( recur( start + 1, depth + 1 ) ) return true ;

        unset_value( start->y, start->x, n);
    }

    start->is_set = false ;
    return false ;
}

void process() {
    fastio;

    int i, j ;
    int y, x , k;

    int n ;
    float max_t = -1 ;
    string s ;

    for ( y = 0 ; y < 9 ; y ++)
    {
        cin >> s ;
        for ( x = 0 ; x < 9 ; x ++ ) {
            if ( s[x] != '0' )
            set_value(y, x, s[x] - '0');

        }
    }

    for ( y = 0 ; y < 9 ; y ++)
        for ( x = 0 ; x < 9 ; x ++ )
            if ( A[y][x] == 0 )
            {
                Point p = Point(y, x);
                unassigned_points.push_back(p);
            }

    bool ret = recur(unassigned_points.begin());
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


