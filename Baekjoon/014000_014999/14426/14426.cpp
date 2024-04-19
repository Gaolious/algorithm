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

vector<string> A;

bool find(vector<string>::iterator lo, vector<string>::iterator hi, string &s) {
    int i ;
    for (i = 0 ; i < s.size() && lo < hi ; i ++ ) {
        lo = lower_bound( lo, hi, s[i], [&](const string &a, const char &b) { return a[i] < b; });
        hi = upper_bound( lo, hi, s[i], [&](const char &b, const string &a) { return b < a[i]; });
    }
    while ( lo < hi) {
        if ( lo->substr(0, s.size()) == s ) return true;
        lo++;
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
    int N, M ;
    int cnt = 0 ;
    string t ;

    cin >> N >> M ;
    A.resize(N);
    for (auto &s : A) cin >> s ;
    sort(A.begin(), A.end());

    while (M--) {
        cin >> t;
        // if ( find(A.begin(), A.end(), t) ) cnt ++;
        if ( lower_bound(A.begin(), A.end(), t)->substr(0, t.size()) == t ) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}


