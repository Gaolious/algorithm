#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
vector<int> P;
int parent(int x){
    if ( P[x] < 0 )
        return x;
    else
        return P[x] = parent(P[x]);
}
void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if ( x > y ) swap(x,y);
    P[y] = x;
}
void process() {
    fastio;
    int N, M ;
    int x, y;
    int i;

    cin >> N >> M ;
    P.resize(N, -1);

    for ( i = 1 ; i <= M ; i ++ ) {
        cin >> x >> y ;
        if ( parent(x) != parent(y) )
            merge(x, y);
        else {
            cout << i << '\n';
            return;
        }
    }
    cout << "0\n";
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


