#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
string A, B;
string ret ;

void lcs(int l1, int r1, int l2, int r2) {
    int i, j;
    if ( l1 > r1 ) return;

    if ( l1 == r1 ) {
        for ( i = l2 ; i <= r2 ; i ++ )
            if ( A[l1] == B[i] ) {
                ret += A[l1];
                break;
            }
        return;
    }
    int m = ( l1 + r1 ) / 2 ;
    int len = r2 - l2 + 1;

    vector<int> LCS1(len+2), LCS2(len+2);
    vector<int> PREV(len+2);
    for ( i = l1 ; i <= m ; i ++ ) {
        for ( j = l2 ; j <= r2 ; j ++ )
            LCS1[j-l2+1] = (A[i] == B[j]) ? PREV[j-l2]+1 : max(LCS1[j-l2], PREV[j-l2+1]);
        PREV = LCS1;
    }

    fill(PREV.begin(), PREV.end(), 0);
    for (i = r1; i > m; i--){
        for (j = r2; j >= l2; j--)
            LCS2[j-l2+1] = (A[i] == B[j]) ? PREV[j-l2+2]+1 : max(LCS2[j-l2+2], PREV[j-l2+1]);
        PREV = LCS2;
    }

    int mxv = -1, idx = 0;
    for ( i = l2 ; i <= r2 + 1 ; i ++ ) {
        if ( mxv < LCS1[i-l2] + LCS2[i-l2+1] ) {
            mxv = LCS1[i-l2] + LCS2[i-l2+1];
            idx = i;
        }
    }
    lcs(l1, m, l2, idx-1);
    lcs(m+1, r1, idx, r2);
}
int main()
{
    fastio;
    cin >> A >> B ;
    lcs(0, A.length() - 1, 0, B.length() - 1);
    cout << ret.size() << '\n' << ret <<  '\n';
    return 0;
}


