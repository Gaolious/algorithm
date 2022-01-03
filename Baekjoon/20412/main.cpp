#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

template<typename T> pair<T, T> eGCD(T a, T b) {
    if (b == 0) return { 1, 0 };
    auto t = eGCD(b, a%b);
    return { t.second, t.first - t.second*(a / b) };
}
template <typename T> T eGCD(T a, T b, T &x, T &y) {
    if (b == 0) { x=1, y=0; return a; }
    auto t = eGCD(b, a % b, y, x);
    y -= a / b * x;
    return t;
}

template <typename T> T GCD( T a, T b ) {
    return b > 0 ? gcd(b, a % b) : a;
}

void process() {
    long long int m, seed, x1, x2 ;
    long long int AmB, a, c ;

    fastio;
    cin >> m >> seed >> x1 >> x2 ;

    // ( [A] - [B] ) * m + ( seed - x1 ) * a = x1 - x2
    auto g = eGCD(m, seed-x1, AmB, a);
    AmB *= (x1-x2)/g;
    a *= (x1-x2)/g;

    a = ( a + ( (abs(a/m)+1) * m ) ) % m;

    c = x1 - ( a * seed % m ) ;
    c = ( c + (abs(c/m) + 1) * m ) % m ;
    cout << a << " " << c << endl ;
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


