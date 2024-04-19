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
    string s;
    int i, j;
    getline(cin, s, '\n');
    i = j = 0;

    while ( i < s.size() && j < s.size() ) {
        for ( j = i ; j < s.size() && s[j] <= ' ' ; j ++);
        if ( j < s.size() && s[j] == '<') {
            while (j < s.size() && s[j++] != '>');
        }
        for ( i = j ; i < s.size() && ' ' < s[i] && s[i] != '<' ; i ++ );
        reverse(s.begin()+j, s.begin() + i);
    }
    cout << s << '\n';
    return 0;
}


