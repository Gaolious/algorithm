#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

struct Data{
    pii p;
    int idx;
    bool operator < (Data &o) {
        return p < o.p;
    }
};
void init(){
}
void process(int Case) {
    int N;
    int i;
    cin >> N;
    vector<Data> A(N);
    for(i = 0 ; i < N ; i ++ ){
        cin >> A[i].p;
        A[i].idx = i+1;
    }
    std::sort(A.begin(), A.end());
    cout << A.size() / 2 << '\n';
    for ( i = 0 ; i + 1< N ; i += 2 )
        cout << A[i].idx << ' ' << A[i+1].idx << '\n';
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
