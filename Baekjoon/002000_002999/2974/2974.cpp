#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define CEIL(a, b) ( ( (a)+(b)-1)/(b) )
#define FLOOR(a, b) ( (a)/(b) )

ll D[18][31][31][31][31];

int primes[][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1 : 2^0 * 3^0 * 5^0 * 7^0
        {1, 0, 0, 0}, // 2 : 2^1 * 3^0 * 5^0 * 7^0
        {0, 1, 0, 0}, // 3 : 2^0 * 3^1 * 5^0 * 7^0
        {2, 0, 0, 0}, // 4 : 2^2 * 3^0 * 5^0 * 7^0
        {0, 0, 1, 0}, // 5 : 2^0 * 3^0 * 5^1 * 7^0
        {1, 1, 0, 0}, // 6 : 2^1 * 3^1 * 5^0 * 7^0
        {0, 0, 0, 1}, // 7 : 2^0 * 3^0 * 5^0 * 7^1
        {3, 0, 0, 0}, // 8 : 2^3 * 3^0 * 5^0 * 7^0
        {0, 2, 0, 0}, // 9 : 2^0 * 3^2 * 5^0 * 7^0
};
int num_prime[4];
//
ll find_number(int ndigits, ull prefix_number, ull p10, ull low, ull high) {
    ull min_value = prefix_number ;
    ull max_value = prefix_number + p10 - 1;
    if (max_value < low || min_value > high) return 0;
    if (ndigits == 18) {
        if ( num_prime[0] + num_prime[1] + num_prime[2] + num_prime[3] == 0 )
            return 1;
        return 0;
    }

    if (low <= min_value && max_value <= high)
    {
        if (D[ndigits][num_prime[0]][num_prime[1]][num_prime[2]][num_prime[3]] >= 0)
            return D[ndigits][num_prime[0]][num_prime[1]][num_prime[2]][num_prime[3]];
    }

    p10 /= 10;
    int curr, i;
    bool flag ;
    ll cnt = 0;
    for ( curr = ( prefix_number == 0 ? 0 : 1) ; curr <= 9 ; curr ++ ) {
        flag = true ;
        for ( i = 0 ; i < 4 ; i ++ ) flag &= num_prime[i] >= primes[curr][i];
        if (!flag) continue;

        for ( i = 0 ; i < 4 ; i ++ ) num_prime[i] -= primes[curr][i];
        cnt += find_number(ndigits+1, prefix_number + curr * p10, p10, low, high);
        for ( i = 0 ; i < 4 ; i ++ ) num_prime[i] += primes[curr][i];
    }

    if (low <= min_value && max_value <= high)
        D[ndigits][num_prime[0]][num_prime[1]][num_prime[2]][num_prime[3]] = cnt ;
    return cnt;
}

ll digit_products(ull low, ull high) {
    ll ret = 0;
    int a, b, c, d;
    ull na, nb, nc, nd, A, B, C, D ;
    ull maxN = 1'000'000'000;
    ull p18 = maxN*maxN;

    for (na=1, a=0 ; na <= maxN ; na*=2, a++) {
        A = na ;
        for (nb=1, b=0 ; A*nb <= maxN ; nb *=3, b++) {
            B = A * nb;
            for (nc=1, c=0 ; B*nc <= maxN ; nc *=5, c++) {
                C = B * nc ;
                for (nd=1, d=0 ; C*nd <= maxN ; nd *=7, d++) {
                    D = C * nd ;
                    num_prime[0] = a ;
                    num_prime[1] = b ;
                    num_prime[2] = c ;
                    num_prime[3] = d ;
                    ret += find_number(0, 0, p18, CEIL(low, D), FLOOR(high, D));
                }
            }
        }
    }
    //    cout << cnt << '\n';  // max : 5194
    return ret;
}

int main()
{
    fastio;
    ull Lo, Hi ;
    cin >> Lo >> Hi ;
    memset(D, -1, sizeof(D));
    cout << digit_products(Lo, Hi) << '\n';
    return 0;
}


