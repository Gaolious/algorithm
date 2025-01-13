#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    string s;
    while (getline(cin, s) && !s.empty() ) {
        for (auto &c: s) {
            if ( c == 'i') c = 'e';
            else if ( c == 'e' ) c = 'i';
            else if ( c == 'I' ) c = 'E';
            else if ( c == 'E' ) c = 'I';
        }
        cout << s << '\n';
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


