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

int S(int D, int K, int O, int R) {
    int ret = D*D + K*K + O*O + R*R;
    ret += min( min(D, K/2) , min(O/2, R)) * 7;
    return ret;
}
void process() {
    int N, M ;
    int D, K, O, R;
    int i, j, k, l;
    string s ;
    cin >> N >> M >> s ;
    int best = -1;
    D=K=O=R = 0;
    for (auto c: s) {
        if ( c == 'd') D++;
        else if ( c == 'k' ) K++;
        else if ( c == 'o' ) O++;
        else if ( c == 'r' ) R++;
    }
    for ( i = M ; i >= 0 ; i --) {
        for ( j = M-i ;  j>= 0 ; j -- ) {
            for ( k = M-i-j ; k >= 0 ; k -- ) {
                for ( l = M-i-j-k; l >= 0 ; l -- ) {
                    best = max(best, S(D+i, K+j, O+k, R+l));
                }
            }
        }
    }
    cout << best << '\n';
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


