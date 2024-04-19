#include <bits/stdc++.h>

#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int months[12+1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYoon(int y) {
    if ( y % 4 == 0 && (y % 100 != 0 || y % 400 == 0 ) )
        return true ;
    return false;
}
struct Ymd {
    int year, month, day;
    int nth;
};
const int MaxN = 37197;
Ymd A[MaxN] = {};
Ymd *P[102][12][31] = {};
bool D[MaxN+1];

void init() {
    int y, m, d;
    int nth = 0;

    for ( y = 1900 ; y <= 2001 ; y ++ ) {
        months[2] = isYoon(y) ? 29 : 28;
        for ( m = 1 ; m <= 12 ; m ++ ) {
            for ( d = 1 ; d <= months[m] ; d ++ ) {
                A[nth] = {y, m, d, nth};
                P[y-1900][m-1][d-1] = A+nth;
                nth++;
                if ( y == 2001 && m == 11 && d == 4 )
                    return;
            }
        }
    }
}

Ymd *getYmd(int y, int m, int d, int diff) {
    if ( y <= 2001 && m <= 12 && d <= 31 && P[y-1900][m-1][d-1] ) {
        int idx = P[y-1900][m-1][d-1]->nth;
        if ( idx + diff >= 0 && idx + diff <= MaxN )
            return A + idx + diff;
    }
    return nullptr;
}
Ymd *getYmdAdd1Month(int y, int m, int d) {
    m++;
    if ( m > 12 )
        y ++, m = 1;
    return getYmd(y, m, d, 0);
}
int main()
{
    int y, m, d;
    int T, i;
    Ymd *curr, *t;
    fastio;
    init();

    D[MaxN] = false ;
    for ( i = MaxN-1 ; i >= 0 ; i -- ) {
        bool c1, c2;
        t = getYmd(A[i].year, A[i].month, A[i].day, 1);
        c1 = !t || D[t->nth];
        t = getYmdAdd1Month(A[i].year, A[i].month, A[i].day);
        c2 = !t || D[t->nth];
        D[i] = !c1 || !c2 ;
    }

    cin >> T;
    while (T--) {
        cin >> y >> m >> d;
        curr = getYmd(y, m, d, 0);
        cout << ( D[curr->nth] ? "YES" : "NO" ) << "\n";
    }

    return 0;
}


