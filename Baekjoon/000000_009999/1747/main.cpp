#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const int MaxN = 1'003'001;

bool is_palindrome(int n) {
    int p = 1, t;
    for ( t = n ; t > 9 ; t /= 10, p *= 10){}

    for ( t = 1 ; t < p ; t *=10, p/=10 ) {
        if ( (n/t)%10 != (n/p)%10 )
            return false;
    }
    return true ;
}
void gen_prime(vector<int> &p) {
    vector<char> flag(MaxN+ 1, 0);
    int i, j;
    p.push_back(2);

    for ( i = 3 ; i <= MaxN ; i +=2 ) {
        if ( flag[i] != 0 ) continue;

        for ( j = i ; j <= MaxN ; j += i )
            flag[j] = 1;

        if ( is_palindrome(i))
            p.push_back(i);
    }
}
void process() {
    fastio;
    int n;
    vector<int> prime ;
    gen_prime(prime);

    cin >> n ;
    int idx = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
    cout << prime[idx] << '\n';
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


