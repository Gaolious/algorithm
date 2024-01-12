#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); } while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

#define MaxN (100'010)

int D[MaxN+2][3]={0,};
int D3[MaxN+2]={0,};
int P10[MaxN+2]={0,};

#define IS369(x) ( (x) > 0 && (x) % 3 == 0 )

const int M = 20'150'523;

void init() {
    int i;
    int P ;

    D[0][0] = 1;
    D3[1] = 3;
    P10[1] = 1;

    for ( i = 1; i <= MaxN ; i ++) {
        D[i][0] = ( D[i-1][0] * 1 + D[i-1][1] * 3 + D[i-1][2] * 3) % M ;
        D[i][1] = ( D[i-1][0] * 3 + D[i-1][1] * 1 + D[i-1][2] * 3) % M ;
        D[i][2] = ( D[i-1][0] * 3 + D[i-1][1] * 3 + D[i-1][2] * 1) % M ;
    }

    for ( i = 2, P=10 ; i <= MaxN ; i++, P=(P*10)%M ) {
        D3[i] = (P * 3 + D3[i-1] * 7) % M;
    }
    for ( i = 0, P=1 ; i <= MaxN ; i++, P=(P*10)%M ) {
        P10[i] = P;
    }

}

bool include_369(string &str){
    for (auto r: str){
        int n = r - '0';
        if (IS369(n)) return true;
    }
    return false;
}
bool is_multi3(string &str) {
    int ret = 0 ;
    for (auto r: str)
        ret  += r - '0';

    return ret && ret % 3 == 0;
}

int Multi3(string &str) {
    // 3의 배수 개수.
    int i, j, n ;
    int len = str.length();
    int prev, idx;
    int other3;

    prev = 0;
    other3 = 0;

    for ( i = 0 ; i < len ; i ++ ) {
        n = (int)(str[i] - '0');

        for ( j = 0 ; j < n ; j ++ ) {
            if (IS369(j)) continue;
            idx = (prev+j)%3 ;
            idx = (3 - idx) % 3;
            other3 = ( other3 + D[ len-i-1 ][ idx ] ) % M ;
        }
        if (IS369(n) ) break;
        prev = ( prev + n ) % 3 ;
    }
    return other3 - 1;
}

int Count369(string &str) {
    int len = str.length();
    int ret, n, i, j, multi ;
    bool has369 ;
    ret = 0;
    has369 = false ;

    for ( i = 0 ; i < len ; i ++ ) {
        n = str[i] - '0' ;

        for ( j = 0 ; j < n ; j ++ )
        {
            if ( has369 || IS369(j))
                ret += P10[len-i-1];
            else
                ret += D3[len-i-1];
        }
        ret %= M ;
        if ( IS369(n) ) has369 = true ;

    }

    return ret;
}

void process() {
    fastio;
    string a, b ;
    int ret ;

    init();

    cin >> a >> b ;

    ret = Multi3(b) + Count369(b) ;
    ret = ( ret - Multi3(a) + M ) % M;
    ret = ( ret - Count369(a) + M ) % M ;
    if (is_multi3(b) || include_369(b) ) ret ++ ;

    ret = ( ret + M ) % M;

    cout << ret ;
//    cout << endl;
//    cout << b[0] << endl
//         << "\t369포함 = " << Count369(b) << endl
//         << "\t3의 배수 = " << Multi3(b) << endl
//         << a[0] << endl
//         << "\t369포함 = " << Count369(a) << endl
//         << "\t3의 배수 = " << Multi3(a) << endl ;
//
//    int i ;
//    int a369 = 0 ;
//    int m3 = 0;
//    char str[1024];
//
//    for ( i = 1 ; i <= 100 ; i ++ ) {
//        if (IS369((i/100)%10) ||IS369((i/10)%10) ||IS369((i/1)%10))
//            a369 ++;
//        else if ( i % 3 == 0 )
//            m3 ++;
//
//        sprintf(str, "%d", i+1);
//        string s(str);
//        printf("%d : 369포함(%d), 3배수(%d) \t\t 369포함(%d), 3배수(%d)\n", i, a369, m3, Count369(s), Multi3(s));
//    }
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


