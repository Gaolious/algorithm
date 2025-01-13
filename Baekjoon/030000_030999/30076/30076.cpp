#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}

void init(){
}
void process(int Case) {
    int N, M ;
    int i ;

    cin >> N >> M ; // N:아이 수, M:장소 수
    vector<pii> A;
    for ( i = 0 ; i < M ; i ++ ) cin >> A.emplace_back();

    std::sort(A.begin(), A.end());

    int last = N;
    int required=0, need;
    for ( int i = A.size() - 1 ; i >= 0 ; i -- ){
        need = last-A[i].first+1;
        A[i].second = min(need + required, A[i].second);
        required += need - A[i].second;
        last = A[i].first-1;
    }

    need = last + required;
    cout << need << '\n';
    for (auto [_, c]: A)
        cout << c << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif

    char str[10];
    cin >> str;

    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
