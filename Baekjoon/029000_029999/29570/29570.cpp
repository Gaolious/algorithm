#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

using Rect=pair<pii, pii>;

void init(){
}
void process(int Case) {
    Rect A[4];
    int i, j, k;
    vector<int> X, Y;
    for (i = 0 ; i < 4 ; i ++ ) {
        cin >> A[i].first >> A[i].second;
        if ( A[i].first.first > A[i].second.first) swap(A[i].first.first, A[i].second.first);
        if ( A[i].first.second > A[i].second.second) swap(A[i].first.second, A[i].second.second);
        X.push_back(A[i].first.second);
        X.push_back(A[i].second.second);
        Y.push_back(A[i].first.first);
        Y.push_back(A[i].second.first);
    }
    std::sort(X.begin(), X.end());
    X.erase(std::unique(X.begin(), X.end()), X.end());
    std::sort(Y.begin(), Y.end());
    Y.erase(std::unique(Y.begin(), Y.end()), Y.end());

    int ans = 0 ;
    for ( i = 0 ; i + 1 < X.size() ; i ++ ) {
        for ( j = 0 ; j + 1 < Y.size() ; j ++ ) {
            bool in = false;

            for ( k = 0 ; k < 4 ; k ++ ) {
                if ( !(A[k].first.second <= X[i] && X[i+1] <= A[k].second.second ) ) continue;
                if ( !(A[k].first.first <= Y[j] && Y[j+1] <= A[k].second.first ) ) continue;
                in = true;
            }
            if ( in )
                ans += (Y[j+1] - Y[j]) *(X[i+1]-X[i]);
        }
    }
    cout << ans << '\n';

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
