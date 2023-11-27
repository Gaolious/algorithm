#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<int> P;
int parent(int x) {
    if ( P[x] == x )
        return x;
    return P[x] = parent(P[x]);
}
void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if ( x > y ) swap(x, y);
    P[y] = x;
}

void process() {
    fastio;
    int nG, nP ;
    int i, n ;
    int j;

    cin >> nG >> nP ;
    P.resize(nG + 1);
    for ( i = 0 ; i <= nG ; i ++ ) P[i] = i;

    int ret = 0;
    for ( i = 0 ; i < nP; i ++ ) {
        cin >> n ;
        j = parent(n);
        if ( j == 0 ) break;
        merge(j-1, j);
        ret ++;
    }
    cout << ret ;
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


