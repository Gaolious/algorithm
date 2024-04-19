#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<int> Idx;
vector<int> D;

int sum(int i) {
    int ans = 0;
    for ( ; i > 0 ; i -= (i & -i))
        ans += D[i];
    return ans;
}
void update(int i, int diff) {
    for (;i < D.size(); i += (i & -i))
        D[i] += diff;
}
void process() {
    fastio;
    int T, N, M, n ;
    int i ;
    cin >> T ;

    while ( T -- ) {
        cin >> N >> M ;
        Idx.clear();
        D.clear();
        Idx.resize(N+1, 0);
        D.resize(N + M + 1, 0);

        for ( i = 1 ; i <= N ; i ++ ) update(Idx[i] = M+i, 1);

        for ( i = 1 ; i <= M ; i ++ ) {
            cin >> n ;
            cout << sum(Idx[n]-1) << ' ';
            update(Idx[n], -1);
            update(Idx[ n ] = M - (i-1), 1);
        }
        cout << '\n';
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


