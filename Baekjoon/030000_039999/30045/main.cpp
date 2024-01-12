#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
	int N, cnt = 0;
    string s ;
    cin >> N ;
    while (N--) {
        cin >> s;
        if (s.find("01") != string::npos || s.find("OI") != string::npos )
            cnt ++;
    }
    cout << cnt << '\n';
    return 0;
}


