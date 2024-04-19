#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    int walk, bus, metro;
    cin >> walk >> bus >> metro;
    if ( walk > metro ) metro = bus + 1;
    if ( bus < metro ) cout << "Bus";
    else if ( bus == metro ) cout << "Anything";
    else cout << "Subway";
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


