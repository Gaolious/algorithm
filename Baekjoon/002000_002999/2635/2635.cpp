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

int F(int N, int M, bool print) {

    int ret = 2 ;
    if ( print ) cout << N << ' ' << M ;
    while ( true ) {
        N-=M;
        swap(N, M);
        if ( M < 0 ) break;
        if ( print ) cout << ' ' << M ;
        ret ++;
    }
    return ret;
}
void process() {
    int N, M, max_ans, max_val ;
    max_ans = -1;
    cin >> N ;
    for ( M = N + 1 ; M >= 0 ; M -- ) {
        auto ret = F(N, M, false);
        if (ret > max_ans) {
            max_ans = ret ;
            max_val = M;
        }
    }
    cout << max_ans << '\n';
    F(N, max_val, true);
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


