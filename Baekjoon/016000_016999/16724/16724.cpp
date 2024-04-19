#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int P[1'000'000];
int Y, X;
int parent(int x){
    if (P[x] < 0 ) return x;
    else
        return P[x] = parent(P[x]);
}
void merge(int x, int y){
    x = parent(x);
    y = parent(y);
    if ( x != y ) P[x] = y;
}
void dumpP() {
    int i, j;
    for (i = 0 ; i < Y ; i ++ ) {
        for (j = 0; j < X; j++) {
            cout << P[i*X+j] << ' ' ;
        }
        cout << '\n';
    }
}
void process() {
    fastio;
    int i, j, N, t ;

    memset(P, -1, sizeof(P));
    string M;

    cin >> Y >> X ;
    for (t = 0, i = 0 ; i < Y ; i ++ )
    {
        cin >> M;
        for ( j = 0 ; j < X ; j ++, t++ ) {
            if ( M[j] == 'R' ) merge( t, t+1);
            else if ( M[j] == 'L' ) merge(t, t-1);
            else if ( M[j] == 'D' ) merge(t, t+X);
            else if ( M[j] == 'U' ) merge(t, t-X);
        }
    }

    int ret = 0 ;
    N = X*Y;
    for ( i = 0 ; i < N ; i ++ )
        if ( P[i] < 0 ) ret ++;
    cout << ret << '\n';
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


