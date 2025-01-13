#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}

void init() {}

void process(int Case) {
    int i, j, red, yellow, no, roomNo;
    int N, M;
    cin >> N >> M ;

    vector<int> K(N), A(N);
    vector<bool> KnowWhoKiller(N, false);
    vector<bool> Killed(N, false);

    for (auto &n: K) {
        cin >> n; n--;
    }
    yellow = N, red = 0;
    int round = 0;

    for ( auto killNo: K) {
        round++;
#ifdef AJAVA_DEBUG
        cout << "Round #" << round << " / " << "kill no = " << killNo+1 << '\n';
#endif
        vector< vector<int> > HumanList(M);
        for ( i = 0 ; i < N ; i ++ ) {
            cin >> A[i]; A[i]--;
            if ( Killed[ i ] ) continue;
            HumanList[ A[i] ].push_back( i );
        }
        roomNo = A[killNo];

#ifdef AJAVA_DEBUG
        for ( i = 0 ; i < M ; i ++ ) {
            cout << "\t Room No: " << i+1 << " : ";
            for (auto n: HumanList[i] )
                cout << n + 1 << ' ';
            if ( roomNo == i ) {
                cout << " will kill ";
            }
            cout << '\n';
        }
#endif

        for ( auto no: HumanList[ roomNo ] ) {
            if ( no == killNo ) continue;
            if ( !KnowWhoKiller[no] ) {
                yellow --;
                red++;
                KnowWhoKiller[no] = true;
            }
        }
        if ( KnowWhoKiller[ killNo ] ) red--;
        else yellow--;
        Killed[killNo] = true;

#ifdef AJAVA_DEBUG
        for ( i = 0 ; i < N ; i ++ ) {
            cout << "\t - Human " << i +1 << " : ";
            if ( Killed[i] ) cout << "Killed \n";
            else if ( KnowWhoKiller[i] ) cout << "Know Who is killer\n";
            else cout << "Don't know anything\n";
        }
        cout << "\tYellow : " << yellow << ", Red = " << red << '\n';
#endif

        if ( red > yellow+1 ) {
            cout << round << '\n';
            return;
        }
    }
    cout << round << '\n';
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
