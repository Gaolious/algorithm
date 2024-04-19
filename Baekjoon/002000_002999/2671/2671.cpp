#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    string s ;
    cin >> s ;

    std::regex re("(100+1+|01)+");
    if ( regex_match(s, re) )
        cout << "SUBMARINE\n";
    else
        cout << "NOISE\n";
    return 0;
}


