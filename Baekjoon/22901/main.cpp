#include <bits/stdc++.h>


void process() {
    int T, n;
    int hi, m1, m2 ;
    bool fake, check;
    std::priority_queue<int> lo;
    scanf("%d", &T);

    FILE *fp;

    while ( T-- ) {
        lo.push(2100);
        hi = 2399;
        fake = false ;
        check = false ;

        while ( lo.top() <= hi ) {
            m1 = ( lo.top() + hi + 1)/3;

            if ( lo.top() != hi )
            {
                printf("? %d\n", m);
                fflush(stdout);
            }
            else
            {
                if ( !fake && lo.size() > 1 ) {
                    lo.pop();
                    fake = true ;
                    continue;
                }
                printf("! %d\n", m);
                fflush(stdout);
                break;
            }

            scanf("%d", &n);
            if ( n == 1 ) {
                lo.push(m);
            }
            else {
                hi = m-1;
            }
        }
    }
    fclose(fp);
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


