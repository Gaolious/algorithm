#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    vector<pair<int,string>> A = {
        {620, "Red"},
        {590, "Orange"},
        {570, "Yellow"},
        {495, "Green"},
        {450, "Blue"},
        {425, "Indigo"},
        {380, "Violet"},
    };
    int N ;
    cin >> N;
    for (auto &[l, s]: A) {
        if (N>=l) {
            cout << s << '\n'; return;
        }
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


