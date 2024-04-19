#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int bulb[10]={0,};
int origin[10]={0,};
void dump(){
    int i, j ;
    for ( i = 0 ; i < 10 ; i ++ ) {
        for ( j = 0 ; j < 10 ; j ++ ) {
            if ( bulb[i] & ( 1 << j ) )
                cout << 'O';
            else
                cout << '#';
        }
        cout << '\n';
    }
    cout << '\n';
}
void XOR(int y, int x) {
    if ( y >= 0 && y < 10 && x >= 0 && x < 10) {
        int mask = 1 << x ;
        bulb[y] = (bulb[y] & mask) ? (bulb[y] & (~mask)) : (bulb[y] | mask);
    }
}
void click(int y, int x) {
    int i ;
    XOR(y-1, x);
    XOR(y, x-1);
    XOR(y, x);
    XOR(y, x+1);
    XOR(y+1, x);
}
void process() {
    fastio;
    char c ;
    int i, j, mask ;
    int ret, cnt ;

    for ( i = 0 ; i < 10 ; i ++ ) {
        for ( j = 0 ; j < 10 ; j ++ ) {
            cin >> c ;
            if ( c == 'O' ) bulb[i] |= (1<<j);
        }
        origin[i] = bulb[i];
    }

    ret = 100000 ;

    for ( mask = 0x3ff ; mask >= 0 ; mask -- ) {
        cnt = 0 ;
        memcpy(bulb, origin, sizeof(bulb));
        for ( i = 0 ; i < 10 ; i ++ )
            if ( (1<<i) & mask )
            {
                click(0, i);
                cnt ++;
            }

        for ( i = 1 ; i < 10 ; i ++ ) {
            if ( bulb[i-1] > 0 ) {
                for ( j = 0 ; j < 10 ; j ++ ) {
                    if ( (1<<j) & bulb[i-1] )
                    {
                        click(i, j);
                        cnt++;
                    }
                }
            }
            if ( bulb[i-1] > 0 )
                break;
        }

        int s = 0 ;
        for ( i = 0 ; i < 10 && s == 0; i ++ ) s += bulb[i];

        if ( s > 0 ) continue;
        ret = min( ret, cnt);
    }

    if ( ret > 100 ) cout << "-1\n";
    else cout << ret << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


