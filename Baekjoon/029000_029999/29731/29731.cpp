#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    unordered_set<string> A= {
            "Never gonna give you up",
            "Never gonna let you down",
            "Never gonna run around and desert you",
            "Never gonna make you cry",
            "Never gonna say goodbye",
            "Never gonna tell a lie and hurt you",
            "Never gonna stop",
    };
    string s;
    int N ;
    cin >> N ;
    cin.ignore();
    while (N-- ) {
        getline(cin, s);
        if ( A.count(s) == 0 ){
            cout << "Yes";
            return;
        }
    }
    cout << "No";

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


