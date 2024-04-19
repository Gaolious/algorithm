#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int cmp(pair<int,int> a, pair<int,int> b) {
    return ( a.second == b.second ) ? a.first < b.first : a.second < b.second;
}
int main()
{
    fastio;
    int N, D, ret;

    cin >> N ;
    vector<pair<int, int>> A(N) ;
    for (auto &[a, b] : A) {
        cin >> a >> b;
        if ( a > b ) swap(a,b);
    }
    sort(A.begin(), A.end(), cmp);

    cin >> D;

    priority_queue<int> Q;
    ret = 0;
    for (auto [lx, rx] : A ) {
        if ( rx - lx > D ) continue;

        Q.emplace(-lx);
        while ( !Q.empty() && -Q.top() < rx - D) Q.pop();
        ret = max(ret, (int)Q.size());
#ifdef AJAVA_DEBUG
        cout << "rx : " << rx << " / Q size = " << Q.size() << '\n';
#endif
    }
    cout << ret << '\n';
    return 0;
}


