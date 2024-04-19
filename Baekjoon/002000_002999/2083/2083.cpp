#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    string s;
    int a, b;
    while ( cin >> s >> a >> b && !(s=="#" && !a && !b) ) {
        cout << s << ' ';
        if ( a > 17 || b >= 80 ) cout << "Senior";
        else cout << "Junior";
        cout << '\n';
    }
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


