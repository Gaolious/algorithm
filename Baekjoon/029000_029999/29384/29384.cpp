#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
void process() {
    int K;
    int i, j;
    int arrivedTime;
    int leaveTime;
    int order;
    int N, M;

    cin >> N >> M >> K ;

    vector<bool> ans(K);

    priority_queue<pair<int,int>> Q;

    for ( i = 0 ; i < K ; i ++ ) {
        cin >> arrivedTime >> leaveTime >> order;
        leaveTime += arrivedTime;

        while ( !Q.empty() && Q.top().first <= arrivedTime ) {
            if ( Q.top().second == 0 ) N ++;
            if ( Q.top().second == 1 ) N ++, M++;
            Q.pop();
        }

        if ( order == 0 && N > 0 ) {
            N--;
            Q.emplace(leaveTime, order);
            ans[i] = true;
        }
        else if ( order == 1 && N > 0 && M > 0 ) {
            N--;
            M--;
            Q.emplace(leaveTime, order);
            ans[i] = true;
        }
        else {
            ans[i] = false;
        }
    }


    for ( i = 0 ; i < K ; i ++ ) {
        cout << ( ans[i] ? "Yes" : "No" ) << '\n';
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


