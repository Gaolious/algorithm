#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
int DIST2(pii a) {return a.first*a.first + a.second*a.second;}
int DISTm(pii a) {return abs(a.first) + abs(a.second);}

void init(){
}
void process(int Case) {
    int N, M, K;
    int i, j;
    pii p;
    int score1=0, score2=0;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> M >> K ;
        vector<int> P1(M), P2(K);
        for ( j = 0 ; j < M ; j ++ ) {
            cin >> p;
            P1[j] = DIST2(p);
        }
        for ( j = 0 ; j < K ; j ++ ) {
            cin >> p;
            P2[j] = DIST2(p);
        }
        std::sort(P1.begin(), P1.end());
        std::sort(P2.begin(), P2.end());


        if ( P1[0] == P2[0] ) {

        }
        else if ( P1[0] < P2[0] ) {
            for (auto n: P1) {
                if ( n < P2[0] ) score1++;
                else break;
            }
        }
        else {
            for (auto n: P2) {
                if ( n < P1[0] ) score2++;
                else break;
            }
        }
    }
    cout << score1 << ":" << score2 << '\n';
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
