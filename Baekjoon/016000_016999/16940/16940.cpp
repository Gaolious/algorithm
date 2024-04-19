#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

vector<vector<int>> A;
vector<int> ans;
vector<int> C;

bool check_child() {
    int idx, order ;
    int curr ;

    curr = order = 1;
    C[curr] = order;
    idx = 0;
    while(true) {
        for ( auto t: A[curr] )
            if ( C[t] == 0 )
                C[t] = order + 1;
        if ( ++idx >= ans.size() ) break;
        order ++;
        curr = ans[idx];
    }
    for ( idx = 1 ; idx < ans.size() ; idx ++ ) {
        if ( C[ ans[idx-1] ] > C[ans[idx]] )
            return false;
    }
    return true;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, a, b, i ;
    cin >> N ;

    A.resize(N+1);
    ans.resize(N);
    C.resize(N+1, 0);
    for ( i = 1 ; i < N; i ++ ) {
        cin >> a >> b ;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    for (auto &t : ans ) cin >> t ;

    cout << check_child() << '\n';

    return 0;
}


