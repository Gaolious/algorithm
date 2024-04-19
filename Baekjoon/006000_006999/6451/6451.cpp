#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

int N, EtNo;
vector<vector<int>> C;
vector<int> D;
vector<vector<int>> Possibles;

vector<bool> Visit;
vector<int> Order;

void F( int s, int idx ) {
    if ( s == EtNo ) {
        auto &route = Possibles.emplace_back();
        for (auto &p: Order) {
            if ( p < 0 || p == EtNo ) break;
            route.push_back(p);
        }
        return;
    }
    for (auto nxt: C[s] ) {
        if ( Visit[nxt]) continue;
        Visit[nxt] = true;
        Order[idx] = nxt;
        F(nxt, idx+1);
        Order[idx] = -1;
        Visit[nxt] = false;
    }
}
void process() {
    int a, b;

    cin >> N >> EtNo;
    C.resize(N+1);
    D.resize(N+1, -1);
    Visit.resize(N+1, false);
    Order.resize(N+1, -1);

    while ( cin >> a >> b )
        C[a].push_back(b);

    Visit[0] = true;
    Order[0] = 0;
    F(0, 1);
    vector<int> Count(N+1, 0) ;
    int maxCnt = -1;
    for ( auto &route : Possibles) {
        for (auto &p: route ) {
            Count[p]++;
            maxCnt = max(maxCnt, Count[p]);
        }
    }
    auto ret = max_element(Count.begin(), Count.begin());
    for ( auto &route : Possibles) {
        int ans ;
        for (auto &p: route ) {
            if ( Count[p] == *ret ) {
                ans = p;
            }
        }
        cout << "Put guards in room " << ans << ".\n";
        return;
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


