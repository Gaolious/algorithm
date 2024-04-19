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

vector<pair<ll, pair<char,char> >> C(3*3);

int Convert(char a) {
    if ( a == 'R') return 0;
    if ( a == 'G') return 1;
    return 2;
}
void add(char a, char b) {
    if ( a > b ) swap(a,b);
    int idx = Convert(a) * 3 + Convert(b);
    C[idx].first++;
}
void process() {
    int N, n;
    string s;
    cin >> N ;
    int i, j ;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            C[i * 3 + j] = {0, {"RGB"[i], "RGB"[j]}};

    while ( N -- ) {
        cin >> s ;
        n = s.size();
        for (i = 0 ; i < n ; i ++ )
            add(s[i], s[(i+1)%n]);
    }
    sort(C.begin(), C.end());

    N = C.size();

    for (i = 0 ; i < N ; i ++ ) {
        if ( C[i].first == C[N-1].first ) {
            cout << C[i].second.first << C[i].second.second << '\n';
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


