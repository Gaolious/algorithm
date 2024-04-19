#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    map<string, string> A = {
            {"Algorithm", "204"},
            {"DataAnalysis", "207"},
            {"ArtificialIntelligence", "302"},
            {"CyberSecurity", "B101"},
            {"Network", "303"},
            {"Startup", "501"},
            {"TestStrategy", "105"}
    };
    int N;
    string s;
    cin >> N;
    while( N -- ) {
        cin >> s;
        cout << A[s] << '\n';
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


