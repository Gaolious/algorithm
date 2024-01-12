#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

ll F(ll n) {
    ll ret = 0 ;
    ll i ;
    /*
     *      0   :   0 0 0 0
     *      1   :   0 0 0 1
     *      2   :   0 0 1 0
     *      3   :   0 0 1 1
     *      4   :   0 1 0 0
     *      5   :   0 1 0 1
     *      6   :   0 1 1 0
     *      7   :   0 1 1 1
     *
     *      // 첫번째 자리는 (0 1회, 1 1회) 2번 cycle
     *      // 두번째 자리는 (0 2회, 1 2회) 4번 cycle
     *      // 세번째 자리는 (0 4회, 1 4회) 8번 cycle
     *
     *      ex> n= 5
     *      1 부터 n 까지
     *
     *      첫번째 자리가 1인 경우 : (1+5) / 2(cycle) = 3 회 cycle * 1(1의 개수) = 3
     *      두번째 자리가 1인 경우 : (1+5) / 4(cycle) = 1 회 cycle * 2(1의 개수) = 2
     *      세번째 자리가 1인 경우 : (1+5) / 8(cycle) = 0 회 cycle
     *                          (1+5) % 8 = 6.
     *                          1회 cycle[ 4번은 0, 4번은 1 ] 중 6 은, 추가 2(=6- 4(0의 개수))번의 1 발생. = 2
     *      총 7번.
     *
     * */
    for ( i = 1 ; i <= n ; i *= 2 )
    {
        ret += (n+1) / (i*2) * i ;
        ret += max( 0ll, (n+1) % ( i * 2 ) - i );
    }

    return ret;
}
void process() {
    fastio;
    ll A, B;
    cin >> A >> B ;
    cout << F(B) - F(A-1) << endl;
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


