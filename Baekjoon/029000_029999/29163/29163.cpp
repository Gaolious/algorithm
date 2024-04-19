#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int N, n, A[2]={0,} ;
    cin >> N ;
    while ( N -- ) {
        cin >> n ; A[n%2]++;
    }
    if ( A[0] > A[1]) cout << "Happy";
    else cout << "Sad";
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


