#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> pair<T,T> minxy(pair<T,T> a, pair<T,T> b) { return { min(a.first, b.first), min(a.second, b.second) }; }
template <typename T> pair<T,T> maxxy(pair<T,T> a, pair<T,T> b) { return { max(a.first, b.first), max(a.second, b.second) }; }
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}
template <typename T> ll DISTm(pair<T,T>  a) {return abs(a.first) + abs(a.second);}

int B[2][2001][2001];
int W[2][2001][2001];

void init(){
}

void process(int Case) {
    int Y, X, K, i, j, k;
    string s;
    cin >> Y >> X >> K;
    for (i = 0; i < Y; i++) {
        cin >> s;
        for (j = 0; j < X; j++) {
            if (s[j] == 'B') B[(i + j) % 2][i + 1][j + 1] = 1;
            else W[(i + j) % 2][i + 1][j + 1] = 1;
        }
    }
    for (k = 0; k < 2; k++) {
        for (i = 1; i <= Y; i++) {
            for (j = 1; j <= X; j++) {
                B[k][i][j] += B[k][i - 1][j] + B[k][i][j - 1] - B[k][i - 1][j - 1];
                W[k][i][j] += W[k][i - 1][j] + W[k][i][j - 1] - W[k][i - 1][j - 1];
            }
        }
    }

    int ans = Y * X + 1, b1, b2, w1, w2, t;
    for (i = 1; i <= Y - K + 1; i++) {
        for (j = 1; j <= X - K + 1; j++) {
            b1 = B[0][i + K - 1][j + K - 1] - B[0][i + K - 1][j - 1] - B[0][i - 1][j + K - 1] + B[0][i - 1][j - 1];
            b2 = B[1][i + K - 1][j + K - 1] - B[1][i + K - 1][j - 1] - B[1][i - 1][j + K - 1] + B[1][i - 1][j - 1];
            w1 = W[0][i + K - 1][j + K - 1] - W[0][i + K - 1][j - 1] - W[0][i - 1][j + K - 1] + W[0][i - 1][j - 1];
            w2 = W[1][i + K - 1][j + K - 1] - W[1][i + K - 1][j - 1] - W[1][i - 1][j + K - 1] + W[1][i - 1][j - 1];
            t = K * K - max(b1 + w2, b2 + w1);
            ans = min(ans, t);
        }
    }
    cout << ans;
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
