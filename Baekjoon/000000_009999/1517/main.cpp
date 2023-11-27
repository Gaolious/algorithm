#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
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

void process() {
    fastio;
    int N ;
    int i, j ;
    ll ret;

    cin >> N ;
    vector<ll> tree(N+1, 0);
    vector<pair<int,int>> A(N+1);

    A[0] = make_pair(-2'000'000'000, 0);
    for ( i = 1 ; i <= N ; i ++ ) {
        cin >> A[i].first;
        A[i].second = i;
    }
    std::sort(A.begin(), A.end());

    ret = 0;
    for ( i = 1 ; i <= N ; i ++ )
    {
        ret += sum(tree, N) - sum(tree, A[i].second);
        update(tree, A[i].second, 1);
    }
    cout << ret;
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


