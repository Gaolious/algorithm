#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    string s;
    int n;

    while(getline(cin, s) && s != "0") {
        n = 0;
        for (auto c: s) n = ( n * 10 + c-'0') % 42;
        cout << ( n == 0 ? "PREMIADO" : "TENTE NOVAMENTE") << '\n';
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


