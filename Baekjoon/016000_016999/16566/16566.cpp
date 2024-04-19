#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int P[4'000'001]={0,};
int parent(int x) {
    if ( P[x] < 0 )
        return x ;
    else
        return P[x] = parent(P[x]);
}
void merge(int x, int y) {
    x = parent(x);
    y = parent(y);
    if ( x != y ) P[x] = y;
}
void process() {
    fastio;
    vector<int> card ;

    int N, M, K ;
    int i, t;
    cin >> N >> M >> K ;

    memset(P, -1, sizeof(P));

    for ( i = 0 ; i < M ; i ++)
    {
        cin >> t;
        card.push_back(t);
    }

    std::sort(card.begin(), card.end());

    while ( K -- ) {
        cin >> t ;
        i = upper_bound(card.begin(), card.end(), t) - card.begin();
        cout << card[parent(i)] << '\n';
        merge(parent(i),parent(i) + 1);
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


