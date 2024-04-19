#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    map<string, string> A= {
            {"M", "MatKor"},
            {"W", "WiCys"},
            {"C", "CyKor"},
            {"A", "AlKor"},
            {"$", "$clear"},
    };
    string s;
    cin >> s ;
    cout << A[s];
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


