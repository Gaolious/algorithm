#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

void binDump(ll v, int maxBit) {
    int i;
    for ( i = maxBit - 1 ; i >= 0 ; i -- ) {
        if ( (v >> i) & 1 ) cout << 1 ;
        else cout << 0 ;
        if ( ( maxBit - i ) % 4 == 0 ) cout << ' ';
    }
}

struct FloatingNum {
    ll fraction : 52 ;
    ll exponent : 11 ;
    ll SignBit : 1 ;
    void dump() {
        binDump(SignBit, 1); cout << ' ';
        binDump(exponent, 11); cout << ' ';
        binDump(fraction, 52); cout << '\n';
    }
};
union DATA {
    double D ;
    ll     L ;
    char   c ;
    FloatingNum F;
    void dump() {
        cout << setw(7) << setprecision(3) << fixed << D << " : ";
        F.dump();
    }
    void dumpC() {
        binDump(L, 8);
        cout << '\n';
    }
};
void process() {
    DATA v ;
//    v.D = 0;
//    v.dump();
//
//    v.D = 7;
//    v.dump();
//    v.D = 7.5;
//    v.dump();
//    v.D = 7.625;
//    v.dump();
//
//
//    v.D = 3;
//    v.dump();
//    v.D = 3.5;
//    v.dump();
//    v.D = 3.625;
//    v.dump();

    v.c = 8;
    cout << " 8      : ";
    v.dumpC();
    cout << " 8 >> 2 : ";
    v.c = 8 >> 2;
    v.dumpC();
    cout << " 8 >> 5 : ";
    v.c = 8 >> 5;
    v.dumpC();

    v.c = -120;
    cout << "-120    : ";
    v.dumpC();
    v.c = -120 >> 2;
    cout << "-120>>2 : ";
    v.dumpC();
    v.c = -120 >> 5;
    cout << "-120>>5 : ";
    v.dumpC();
    v.c = -120 >> 8;
    cout << "-120>>8 : ";
    v.dumpC();
    cout << '\n';

    v.c = 8;
    cout << " 8      : ";
    v.dumpC();
    cout << " 8 << 2 : ";
    v.c = 8 << 2;
    v.dumpC();
    cout << " 8 << 5 : ";
    v.c = 8 << 5;
    v.dumpC();


    v.c = -120;
    cout << "-120    : ";
    v.dumpC();
    v.c = -120 << 2;
    cout << "-120<<2 : ";
    v.dumpC();
    v.c = -120 << 5;
    cout << "-120<<5 : ";
    v.dumpC();
    cout << -4 % 9 ;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


