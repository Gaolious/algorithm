#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    fastio;
    const char A[10] = "KOREA";
    int idx=0, cnt=0;
    string s;
    cin >> s;
    for (auto c : s) {
        if ( c == A[idx%5] ) {
            idx++;
        }
    }
    cout << idx << "\n";
    return 0;
}


