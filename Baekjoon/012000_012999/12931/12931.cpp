#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, N, cnt=0, c0;
    cin >> N;
    vector<int> A(N);
    for (auto &a: A) cin >> a;
    while (true ) {
        c0 = 0 ;
        for(auto &a: A) {
            if ( a % 2 == 1 ) {
                cnt ++;
                a--;
            }
            if ( a == 0 ) c0 ++;
        }
        if ( c0 == N ) break;
        cnt ++;
        for (auto &a : A) a/= 2;
    }
    cout << cnt << '\n';
    return 0;
}


