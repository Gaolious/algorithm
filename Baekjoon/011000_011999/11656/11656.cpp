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

vector<int> SA;

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i ;
    string s ;
    cin >> s ;
    SA.resize(s.size());
    for ( i = 0 ; i < s.size() ; i ++ ) SA[i] = i;

    sort(SA.begin(), SA.end(), [&](int a, int b) {
        return strcmp(s.c_str()+a, s.c_str()+b) < 0;
    });
    for ( i = 0 ; i < s.size() ; i ++ )
        cout << s.c_str() + SA[i] << '\n';
    return 0;
}


