#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int NumFriends[4001];
vector<int> R[4001];

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, M;
    int a, b;
    int i;
    int cnt, ans ;

    cin >> N >> M ;
    for (i = 0 ; i < M ; i ++ ) {
        cin >> a >> b ;
        if ( a == b ) continue;
        if ( a > b ) swap(a,b);
        R[a].push_back(b);
        NumFriends[a]++;
        NumFriends[b]++;
    }

    for ( i = 1 ; i <= N ; i ++ )
        sort(R[i].begin(), R[i].end());

    ans = N * 100;

    for ( i = 1 ; i <= N ; i ++ ) {
        for (auto j : R[i] ) {
            for (auto k: R[j] ) {
                if ( !binary_search(R[i].begin(), R[i].end(), k) ) continue;
                cnt = NumFriends[i] - 2 + NumFriends[j] - 2 + NumFriends[k] - 2;
                ans = min(ans, cnt);
            }
        }
    }

    if ( ans >= N *100 )
        cout << "-1\n";
    else
        cout << ans ;
    return 0;
}


