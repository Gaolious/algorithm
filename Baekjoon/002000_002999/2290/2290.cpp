#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int M[10][15]= {
    {0,1,0, 1,0,1, 0,0,0, 1,0,1, 0,1,0},
    {0,0,0, 0,0,1, 0,0,0, 0,0,1, 0,0,0},
    {0,1,0, 0,0,1, 0,1,0, 1,0,0, 0,1,0},
    {0,1,0, 0,0,1, 0,1,0, 0,0,1, 0,1,0},
    {0,0,0, 1,0,1, 0,1,0, 0,0,1, 0,0,0},
    {0,1,0, 1,0,0, 0,1,0, 0,0,1, 0,1,0},
    {0,1,0, 1,0,0, 0,1,0, 1,0,1, 0,1,0},
    {0,1,0, 0,0,1, 0,0,0, 0,0,1, 0,0,0},
    {0,1,0, 1,0,1, 0,1,0, 1,0,1, 0,1,0},
    {0,1,0, 1,0,1, 0,1,0, 0,0,1, 0,1,0},
};
void S(char c, int n, string &ret) {
    while(n--) ret += c;
}
void col(string &N, int s, int idx) {
    int i, len, n;
    len = N.length();
    string ret ;
    for ( i = 0 ; i < len ; i ++ ) {
        n = N[i] - '0';
        ret += ' ';
        S(M[n][idx] ? '-' : ' ', s, ret);
        ret += ' ';
        ret += ' ';
    }
    cout << ret << '\n';
}
void row(string &N, int s, int idx1, int idx2) {
    int k, i, j, len, n;
    string ret ;

    len = N.length();
    for ( i = 0 ; i < len ; i ++ ) {
        n = N[i] - '0';
        ret += M[n][idx1] ? '|' : ' ';
        S(' ', s, ret);
        ret += M[n][idx2] ? '|' : ' ';
        ret += ' ';
    }
    for ( k = 0 ; k < s ; k ++ )
        cout << ret << '\n';
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int s;
    string N;

    fastio;

    cin >> s >> N ;
    col(N, s, 0*3 + 1);
    row(N, s, 1*3+0, 1*3+2);
    col(N, s, 2*3 + 1);
    row(N, s, 3*3+0, 3*3+2);
    col(N, s, 4*3 + 1);
    return 0;
}


