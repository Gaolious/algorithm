#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MAXN (1000000)
// #define MAXN (10)
int Index[1000001];

long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(vector<long long> &tree, int i, long long diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main()
{
    fastio;
    int N, i, k, j;
    cin >> N ;

    for (i = 0 ; i < N ; i ++ ) {
        cin >> k;
        Index[k] = i ;
    }
    vector<ll> Tree(N+1);

    ll ret = 0 ;

    for (i = 0 ; i < N ; i ++ ) {
        cin >> k;
        j = Index[k] + 1;
        ret += i - sum(Tree, j);
        update(Tree, j, 1);
    }
    cout << ret ;
    return 0;
}


