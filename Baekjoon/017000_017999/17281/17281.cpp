#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int A[50][9] ; // 50이닝, 9명 선수
int N ;

int getScore(vector<int> &p ) {
    bool base[4]{};
    int playerNo[9], playerIdx, inning;
    int score, out ;
    int i ;
    for ( i = 0 ; i < 3 ; i++ ) playerNo[i] = p[i];
    playerNo[3] = 0;
    for ( i = 3 ; i < 8 ; i++ ) playerNo[i+1] = p[i];

    inning = 0; score = out = 0;
    for ( playerIdx = 0 ; inning < N; playerIdx = (playerIdx+1)%9 ) {
        int t = A[ inning ][ playerNo[playerIdx] ];
        if ( t == 0 ) {
            out ++ ;
        }
        else {
            base[0] = true;
            for (i=0 ; i <= 3 ; i ++ ) score += (base[i] && i+t >= 4) ? 1 : 0 ;

            for ( i=3 ; i >= t ; i -- )
                base[i] = base[i - t];
            for ( i=t-1 ; i>= 0 ; i -- )
                base[i] = false;
        }
        if ( out >= 3 ) {
            out = 0;
            inning ++;
            for ( i = 0 ; i <= 3 ; i ++ ) base[ i ] = false;
        }
    }
    return score;
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j ;
    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        for ( j = 0 ; j < 9 ; j ++ )
            cin >> A[i][j];
    }

    vector<int> p ;
    for ( i = 1 ; i < 9 ; i ++) p.push_back(i);

    int ans = 0 ;
    do {
        ans = max(ans, getScore(p));
    } while ( next_permutation(p.begin(), p.end()));

    cout << ans ;

    return 0;
}


