#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int cnt[10];
string A, B;
string ans ;

bool F(int idx, bool isLess) {

    int i, s, e ;
    if ( idx >= B.size() ) {
        return isLess;
    }
    s = isLess ? 9 : B[idx]-'0';
    e = idx == 0 ? 1 : 0 ;
    for ( i = s ; i >= e ; i -- ) {
        if ( cnt[ i ] == 0 ) continue;
        cnt[ i ] --;
        ans.push_back('0' + i);
        if ( F( idx + 1, isLess || ( i < B[idx]-'0' ) ) )
            return true;
        ans.pop_back();
        cnt[ i ] ++;
    }
    return false;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    cin >> A >> B;

    for (auto a : A) cnt[ a - '0' ] ++;

    if ( A.size() == B.size() && F(0, false)) {
        cout << ans;
    }
    else if ( A.size() < B.size() && F(B.size() - A.size(), true) ) {
        cout << ans;
    }
    else {
        cout << "-1\n";
    }
    return 0;
}


