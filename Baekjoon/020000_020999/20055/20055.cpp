#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct CONVEYER {
    int idx;
    int durability;
    bool robot;
    CONVEYER(): durability(0), robot(false){}
    bool canLoad() const { return durability > 0 && !robot; }

    CONVEYER &Load() { robot = true; return *this;}
    CONVEYER &Unload() { robot = false; return *this;}
    CONVEYER &ReduceDurability() { durability--; return *this;}
    bool isBroken() const { return durability == 0 ;}
};
void dump_conveyer(vector<CONVEYER> &conveyer, int idx, int size) {
    int i, j;
    for ( i = 0 ; i < conveyer.size() ; i ++ )
        cout << conveyer[(i + idx + size)%size].idx << ' ';
    cout << '\n';
    for ( i = 0 ; i < conveyer.size() ; i ++ )
        cout << conveyer[(i + idx + size)%size].durability << ' ';
    cout << '\n';
    for ( i = 0 ; i < conveyer.size() ; i ++ )
        cout << conveyer[(i + idx + size)%size].robot << ' ';
    cout << '\n';
    cout << endl;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;

    int size, i, idx;
    int N, K, ans, NumberOfBroken, firstIndex, prev ;
    cin >> N >> K ;
    size = N * 2;
    vector<CONVEYER> Conveyer(size);

    i = 0;
    for ( auto &c: Conveyer ) {
        cin >> c.durability;
        c.idx = ++i;
    }

    ans = NumberOfBroken = 0;
    firstIndex = 0;

    while( NumberOfBroken < K ) {
        ans ++;
        firstIndex = ( firstIndex + size - 1 ) % size ;

        idx = ( firstIndex + N-1 + size ) % size ;
        if ( Conveyer[idx].robot)
            Conveyer[idx].Unload();

        for ( i = N-1 ; i > 0 ; i -- ) {
            idx = ( firstIndex + i + size ) % size ;
            prev = ( idx - 1 + size ) % size ;

            if (Conveyer[idx].canLoad() && Conveyer[prev].robot ) {
                Conveyer[prev].Unload();
                Conveyer[idx].Load().ReduceDurability();
                if ( i == N-1) {
                    Conveyer[idx].Unload();
                }
                if ( Conveyer[idx].isBroken() )
                    NumberOfBroken ++;
            }
        }
        if ( Conveyer[firstIndex].canLoad() ) {
            if ( Conveyer[firstIndex].Load().ReduceDurability().isBroken() )
                NumberOfBroken ++;
        }
    }
    cout << ans << '\n';
    return 0;
}


