#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;

void init(){
}
struct Data {
    char c;
    ll sum;
    bool canZero;
    int num;
};
void process(int Case) {
    vector<ll> P(12);
    vector<Data> A(10);
    int N, i, j;
    for (P[0]=1, i = 1 ; i < 12 ; i ++ ) P[i] = P[i-1]*10;
    for ( i = 0 ; i < 10 ; i ++ )
        A[i] = { (char)('A' + i), 0, true, -1};

    cin >> N;
    vector<string> S(N);
    for (auto &s: S) {
        cin >> s ;
        N = s.size();
        A[ s[0]-'A' ].canZero = false;
        for ( i = 0 ; i < N ; i ++ )
            A[ s[i] - 'A' ].sum += P[ N-1-i ];
    }
    std::sort(A.begin(), A.end(), [](Data &a, Data &b){
        return a.sum > b.sum ;
    });
    for ( i = 0 ; i < 10 ; i ++ ) {
        A[i].num = 9-i;
        for( j = i ; A[j].num == 0 && !A[j].canZero && j > 0 ; j -- )
            swap(A[j].num, A[j-1].num);
    }

//    for (auto &a : A)
//        cout << a.c << " : sum=" << a.sum << ' ' << a.canZero << ' ' << a.num << '\n';
    std::sort(A.begin(), A.end(), [](Data &a, Data &b){
        return a.c < b.c ;
    });

    ll ans = 0 ;
    for (auto &s : S ) {
        N = s.size();
        for ( i = 0 ; i < N ; i ++ )
            ans += P[ N-1-i ] * A[ s[i] - 'A' ].num;
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
