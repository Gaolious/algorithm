#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}
template <typename T> ll DIST2(pair<T,T>  a) {return a.first*a.first + a.second*a.second;}

void init(){
}
void process(int Case) {
    int N, i, j;
    int pos[3];
    cin >> N;
    vector<pll> P;
    vector<vector<pll>> A(N, vector<pll>(3));
    unordered_set<ll> C;

    for (i = 0; i < N; i++) {
        for (auto &a: A[i]) {
            cin >> a;
            P.push_back(a);
        }
    }
    std::sort(P.begin(), P.end());
    P.erase(std::unique(P.begin(), P.end()), P.end());

    ll PSize = P.size();
    ll a, b;
    ld L = 0, d;
    for (i = 0; i < N; i++) {
        for (j = 0; j < 3; j++)
            pos[j] = std::lower_bound(P.begin(), P.end(), A[i][j]) - P.begin();

        for (j = 0; j < 3; j++) {
            a = ((ll) pos[j] * PSize + pos[(j + 1) % 3]);
            b = ((ll) pos[(j + 1) % 3] * PSize + pos[j]);
            d = sqrt(DIST2(P[pos[j]] - P[pos[(j + 1) % 3]]));

            if (C.count(a * PSize + b) || C.count(b * PSize + a)) {
                L -= d ;
            }
            else {
                C.insert(a * PSize + b);
                C.insert(b * PSize + a);
                L += d;
            }
        }
    }

    cout << setprecision(12) << L << '\n';
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
