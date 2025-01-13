#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
enum {RED=0, GREEN, BLUE, YELLOW};
// 빨간 불빛이 켜져 있고 어떤 버튼이든 누르면, 초록 불빛이 켜집니다.
// 초록 불빛이 켜져 있고
//      버튼 0을 누르면, 빨간 불빛이 켜집니다.
//      버튼 1을 누르면, 파란 불빛이 켜집니다.
// 파란 불빛이 켜져 있고
//      버튼 0을 누르면, 노란 불빛이 켜집니다.
//      버튼 1을 누르면, 파란 불빛이 계속 켜집니다.
// 노란 불빛이 켜져 있고
//      버튼 0을 누르면, 노란 불빛이 계속 켜집니다.
//      버튼 1을 누르면, 빨간 불빛이 켜집니다.

void process(int Case) {
    int F[2][4]={0,};
//    int P[4]={0,};
    int N, turn, i ;
    cin >> N ;

    vector<int> A(N, 0);
    for (auto &n: A) cin >> n ;

    turn = 0;
    F[turn][RED] = 1 ;

    for ( auto n: A ) {
        memset(F[1-turn], 0, sizeof(F[1-turn]));

        if ( F[turn][RED] ) F[1-turn][GREEN] = 1;
        if ( F[turn][GREEN] ) {
            if ( n == 0 || n == -1 ) F[1-turn][RED] = 1;
            if ( n == 1 || n == -1 ) F[1-turn][BLUE] = 1;
        }
        if ( F[turn][BLUE] ) {
            if ( n == 0 || n == -1 ) F[1-turn][YELLOW] = 1;
            if ( n == 1 || n == -1 ) F[1-turn][BLUE] = 1; // P[BLUE] = 1;
        }
        if ( F[turn][YELLOW] ) {
            if ( n == 0 || n == -1 ) F[1-turn][YELLOW] = 1; // P[YELLOW] = 1;
            if ( n == 1 || n == -1 ) F[1-turn][RED] = 1;
        }
        turn = 1 - turn;
    }

    for ( i = 0 ; i < 4 ; i ++ ) {
//        if ( F[turn][i] || P[i] )
        if ( F[turn][i] )
            cout << "JAH\n";
        else
            cout << "EI\n";
    }
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
