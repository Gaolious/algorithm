#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[100'000];

void process() {
    fastio;
    int i, j, N, t;
    int best, bl, br;

    cin >> N ;
    sort(A, A+N);
    best = 2'000'000'001;
    for ( i = 0 ; i < N ; i ++ ) cin >> A[ i ] ;
    for ( i = 0, j = N - 1 ; i < j ; ) {
        t = A[i] + A[j] ;
        if ( abs(t) < best ) {
            best = abs(t);
            bl = A[i], br = A[j] ;
        }
        if ( t == 0 ) break;
        else if ( t < 0 ) i ++;
        else j--;
    }
    cout << bl << ' ' << br << endl;
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


