#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    string s ;
    int pos, len, idx, i;
    cin >> s ;
    vector<string> IP[2];
    idx = pos = 0;

    for ( i = 0 ; i < 10 ; i ++ ) {
        len = s.find(":", pos);
        if ( pos == len ) idx=1;
        else IP[idx].push_back(s.substr(pos, len - pos));
        if ( len == s.npos ) break;
        pos = len + 1;
    }
    while ( IP[0].size() + IP[1].size() < 8 ) IP[0].emplace_back("0");
    idx = 0;
    for ( i = 0 ; i < 2 ; i ++ )
        for (auto c : IP[i] ) {
            if ( idx++ != 0 ) cout << ':';
            cout << setw(4) << setfill('0') << c;
        }
    return 0;
}


