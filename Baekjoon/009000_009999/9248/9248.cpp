#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

void SuffixArray(string &s, vector<int> &SA, vector<int> &LCP) {
    vector<int> Index, Freq, Group, NextGroup;
    int i, j, m = 26, len;
    int n = s.size();

    SA.resize(n);
    Freq.resize( max(n+1, m), 0);
    Index.resize(n);
    Group.resize(n);
    NextGroup.resize(n);
    for (i = 0; i < n; i++) Freq[Group[i] = s[i] - 'a']++;
    for (i = 1; i < m; i++) Freq[i] += Freq[i - 1];
    for (i = 0; i < n; i++) SA[--Freq[Group[i]]] = i;

    for (len = 1; len == 1 || m < n; len <<= 1) {
        for (j = 0; j < n; j++)
            NextGroup[j] = Group[j], Freq[Group[Index[j] = SA[j]]] = j;

        for (j = n - 1; j >= 0; j--)
            if(Index[j] >= len)
                SA[Freq[Group[Index[j] - len]]--] = Index[j] - len;

        for (j = n - 1; j >= 0; j--)
            if(Index[j] + len >= n)
                SA[Freq[Group[Index[j]]]--] = Index[j];

        for (j = m = 0; j < n; j++) {
            Group[SA[j]] = m;
            if (j + 1 == n || NextGroup[SA[j]] != NextGroup[SA[j + 1]] ||
                SA[j] + len >= n || NextGroup[SA[j] + len] != NextGroup[SA[j + 1] + len])
                m++;
        }
    }

    LCP.resize(n);
    for (len = j = 0; len < n; len++) if (Group[len]) {
        for (; s[len + j] == s[SA[Group[len] - 1] + j]; j++);
        LCP[Group[len]] = j; if(j) j--;
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, j, k ;
    string s ;
    cin >> s ;
    vector<int> SA;
    vector<int> LCP;
    SuffixArray(s, SA, LCP);
    for ( i = 0 ; i < s.size() ; i ++ ) cout << SA[i] + 1 << ' ';
    cout << '\n' << 'x' << ' ';
    for ( i = 1 ; i < s.size() ; i ++ ) cout << LCP[i] << ' ';
    return 0;
}


