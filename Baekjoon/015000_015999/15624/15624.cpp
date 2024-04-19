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

const ll MOD = 1000000007;
struct Matrix {
    ll m[2][2];
    Matrix operator *(Matrix &o) {
        Matrix ret{};
        int i, j, k;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                for (k = 0; k < 2; k++) {
                    ret.m[i][j] += m[i][k] * o.m[k][j];
                    ret.m[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    void dump () {
        int i, j;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                cout << m[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};
Matrix I = { 1, 0, 0, 1};
Matrix P(Matrix a, int k ) {
    if ( k == 0 ) return I ;
    if ( k == 1 ) return a;
    Matrix ret = P(a, k/2);
    ret = ret * ret ;
    if ( k % 2 ) ret = ret * a ;
    return ret;
}
void process() {
    int N ;
    Matrix m = { 0, 1, 1, 1};
    cin >> N ;
    auto ret = P(m, N);
    cout << ret.m[0][1] << '\n';
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


