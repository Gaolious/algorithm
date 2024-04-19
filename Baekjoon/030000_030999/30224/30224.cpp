#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int N;
    int c, d;
    cin >> N ;
    d = N % 7 == 0 ? 1 : 0;
    for (c = 0 ; N > 0 && !c; N /=10 ) c = N % 10 == 7 ? 1 : 0;
    cout << c * 2 + d;
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


