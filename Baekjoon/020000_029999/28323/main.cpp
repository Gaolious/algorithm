#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;


int main()
{
    fastio;
    int N, a, prev, cnt = 1 ;
    cin >> N >> prev;
    while (N-- > 1) {
        cin >> a ;
        if ( a % 2 != prev % 2) {
            prev = a;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}


