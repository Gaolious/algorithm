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
    int i, j;
    string s;
    getline(cin, s, '\n');
    while ( getline(cin, s, '\n') ) {
        i = j = 0;
        while ( i < s.size() && j < s.size() ) {
            for ( i = j ; i < s.size() && s[i] > ' ' ; i ++ );
            reverse(s.begin()+j, s.begin() + i);
            for ( j=i ; j < s.size() && s[j] <= ' ' ; j ++);
        }
        cout << s << '\n';
    }

    return 0;
}


