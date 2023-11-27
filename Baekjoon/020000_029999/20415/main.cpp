#include <bits/stdc++.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

int D[36+2];
int Range[5]={0,};
int Grade[36+1]={0,};
int MaxCost = 0;

int IDX (char c ){
    if ( c == 'B' ) return 0;
    if ( c == 'S' ) return 1;
    if ( c == 'G' ) return 2;
    if ( c == 'P' ) return 3;
    if ( c == 'D' ) return 4;
    return -1;
}
void process() {
    fastio;
    int i, N, s, g, p, d;
    int ret = 0 ;

    memset(D, 0, sizeof(D));
    memset(Grade, -1, sizeof(Grade));

    string mvp ;

    cin >> N ;
    cin >> s >> g >> p >> d;
    cin >> mvp;
    MaxCost = d ;

    Range[IDX('B')] = s - 1;
    Range[IDX('S')] = g - 1;
    Range[IDX('G')] = p - 1;
    Range[IDX('P')] = d - 1;
    Range[IDX('D')] = 100000000;

    for ( i = 0 ; i < N ; i ++ )
        D[i+1] = Range[ IDX(mvp[i]) ] ;
    D[i+1] = MaxCost ;

    for ( i = 1 ; i <= N ; i ++ )
    {
        D[i] = min( D[i] - D[i-1], D[i+1] );
        D[i] = min( D[i], MaxCost);
        ret += D[i];
    }
    cout << ret << endl;
    // dy2000
    // by5000
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


