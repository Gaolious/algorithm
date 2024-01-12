#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const ll MOD = 1'000'000'007;
struct Mat {
    ll a, b, c, d;
    Mat operator *(Mat other) {
        return Mat{
        (this->a * other.a + this->b * other.c) % MOD,
        (this->a * other.b + this->b * other.d) % MOD,
        (this->c * other.a + this->d * other.c) % MOD,
        (this->c * other.b + this->d * other.d) % MOD
        };
    }
    Mat pow(int n) {
        if ( n == 1 ) return *this;
        else if ( n % 2 == 0 ) {
            auto r = this->pow(n/2);
            return r*r;
        } else {
            return *this * pow(n-1);
        }
    }
    void dump() {
        printf("%7lld %7lld \n%7lld %7lld \n",a,b,c,d);
    }
};
void process() {
    fastio;
    Mat m = { 0, 1, 1, 1 };
    int N ;
    cin >> N ;
    cout << m.pow(N).b << ' ' << (N - 2 ) % MOD << '\n';
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


