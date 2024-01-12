#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;


void process() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Count[] = {
            6, 2, 5, 5, 4, 5, 6, 3, 7, 6
    };
    int n, i, j, k ;
    cin >> n ;
    n-=4;
#define CNT(i) ( Count[ (i)/10 ] + Count[ (i)%10 ] )

    for ( i = 0 ; i < 100 ; i ++)
        for ( j = 0 ; i + j < 100 ; j ++ )
        {
            k = i + j ;
            if ( CNT(i) + CNT(j) + CNT(k) == n ) {
                cout << std::setfill('0') << std::setw(2) << i ;
                cout << "+" ;
                cout << std::setfill('0') << std::setw(2) << j ;
                cout << "=" ;
                cout << std::setfill('0') << std::setw(2) << k << endl ;
                return;
            }
        }
        cout << "impossible" << endl;
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


