#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

pair<int,int> F(string &s, int i) {
    int cnt = 0 ;
    for ( ; i < s.length() ; i ++ ) {
        char c = s[i];
        if ( '0' <= c && c <='9' ) {
            if ( i + 1 < s.length() && s[i+1] == '(') {
                auto ret = F(s, i+2);
                cnt += (c - '0') * ret.first;
                i = ret.second;
            } else {
                cnt++;
            }
        } else {
            break;
        }
    }
    return make_pair(cnt, i);
}
void process() {
    fastio;
    string s ;
    cin >> s ;
    cout << F(s, 0).first;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


