#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    map<string,string> A = {
        {"NLCS", "North London Collegiate School"},
        {"BHA", "Branksome Hall Asia"},
        {"KIS", "Korea International School"},
        {"SJA", "St. Johnsbury Academy"},
    };
    string s;
    cin >>s;
    cout << A[s] << '\n';
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


