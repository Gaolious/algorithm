#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

string gen(vector<int> &a, vector<int> &b) {
    int i, j ;
    string ret ;
    int prev = -1;

    for ( i = 9, j = 9 ; i >= 0 || j >= 0 ; ) {
        while ( i >= 0 && a[i] == 0 ) i --;
        while ( j >= 0 && b[j] == 0 ) j --;

        if ( i >= 0 && a[i] > 0 && i != prev ) {
            ret.push_back( i + '0' );
            a[i]--;
            prev = i ;
        }
        else break;

        if ( j >= 0 && b[j] > 0 && j != prev ) {
            ret.push_back( j + '0' );
            b[j]--;
            prev = j;
        }
        else break;
    }
    return ret;
}

bool operator < (string &a, string &b) {
    if ( a.length() < b.length() ) return true ;
    else if ( a.length() > b.length() ) return false ;
    for ( int i = 0 ; i < a.length() ; i ++ ) {
        if ( a[i] < b[i] ) return true ;
        else if ( a[i] > b[i] ) return false ;
    }
    return false;
}
int main()
{
    fastio;
    string ans, ret ;
    int cnt[10]={0,}, i, j, S;
    S = 0 ;
    for ( i = 0 ; i < 10 ; i ++ )
    {
        cin >> cnt[ i ];
        S += cnt[ i ];
    }

    int prev = -1, l, r, v;
    vector<int> g1(10, 0), g2(10, 0);
    l = 0 , r = 9;
    while(l <= r) {
        while ( l <= r && cnt[l] == 0 ) l ++;
        while ( r >= l && cnt[r] == 0 ) r --;
        if ( l < r ) {
            v = min( cnt[l], cnt[r]);
            g2[l]+=v;
            g1[r]+=v;

            cnt[l] -=v;
            cnt[r] -=v;
        } if ( l == r && cnt[l] > 0) {
            g1[l] +=1;
            break;
        }
    }
    ans = gen(g1, g2);
    cout << ans << "\n";
    return 0;
}


