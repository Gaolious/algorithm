#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    unordered_set<string> A;
    int T;
    string a, b;
    fastio;
    cin >> T ;
    while (T--) {
        cin >> a >> b ;
        if ( b == "enter" )
            A.insert(a);
        else
            A.erase(a);
    }
    vector<string> R ;

    for (auto &s: A)
        R.push_back(s);
    sort(R.begin(), R.end(), greater<string>());
    for (auto &s: R)
        cout << s << '\n';

    return 0;
}


