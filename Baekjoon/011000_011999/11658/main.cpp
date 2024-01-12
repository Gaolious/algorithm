#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector< vector<int> > tree;
int sum(int y, int x) {
    int ans = 0, i, j;
    for ( i = y ; i > 0 ; i -= (i & -i))
        for ( j = x ; j > 0 ; j -= (j & -j))
            ans += tree[i][j];
    return ans;
}
int sum(int y1, int x1, int y2, int x2) {
    return sum(y2, x2) - sum(y2, x1-1) - sum(y1-1, x2) + sum(y1-1, x1-1);
}
void update(int y, int x, int diff) {
    int i, j;
    for ( i = y ; i < tree.size() ; i += (i & -i))
        for ( j = x ; j < tree[i].size() ; j += ( j & -j))
            tree[i][j] += diff;
}
void process() {
    fastio;
    int N, M ;
    int i, j;
    int w, x, y, c, x1, y1, x2, y2;

    cin >> N >> M ;
    tree.resize( N+1, vector<int>(N+1, 0) );
    for ( i = 1 ; i <= N ; i ++ )
        for ( j = 1 ; j <= N ; j ++ )
        {
            cin >> w ;
            update(i, j, w);
        }

    while ( M -- ) {
        cin >> w ;
        if ( w == 0 ) {
            cin >> y >> x >> c ;
            update(y, x, c - sum(y, x, y, x));
        } else {
            cin >> y1 >> x1 >> y2 >> x2 ;
            if ( y1 > y2 ) swap(y1, y2);
            if ( x1 > x2 ) swap(x1, x2);
            cout << sum(y1, x1, y2, x2) << '\n';
        }
    }
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


