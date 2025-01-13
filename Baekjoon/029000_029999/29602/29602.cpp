#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

void init(){
}
void process(int Case) {
    int N, i;
    cin >> N;
    vector<pii> A(N);
    vector<int> ans(N);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> A[i].first ;
        A[i].second = i;
    }
    std::sort(A.begin(), A.end());
    for ( i = 0 ; i < N ; i ++ ) ans[ A[i].second ] = i + 1;
    for (auto a: ans) cout << a << ' ';
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
