#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int mapping[26];
int N;
bool compare(string &a, string &b) {
    for(int i = 0 ; i < N ; i ++ ) {
        if (mapping[a[i]] == mapping[b[i]])
            continue;
        if ( mapping[a[i]] < mapping[b[i]] )
            return true;
        break;
    }
    return false;
}
int main()
{
    fastio;

    int i, j, k;
    string s[3];

    cin >> N;
    for ( i = 0 ; i < 3 ; i ++)
        cin >> s[i];
    for (auto H:{1,2,3}) {
        for (auto J:{1,2,3}) {
            for (auto S:{1,2,3}) {
                if ( H == J || H == S || J == S ) continue;
                mapping['H'] = H ;
                mapping['J'] = J ;
                mapping['S'] = S ;
                if ( compare(s[0], s[1]) && compare(s[1], s[2]) ) {
                    cout << "HJS! HJS! HJS!\n";
                    return 0;
                }
            }
        }
    }


    cout << "Hmm...\n";
    return 0;
}


