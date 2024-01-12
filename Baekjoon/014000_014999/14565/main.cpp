#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
typedef long long int ll ;

template<typename T> pair<T, T> exGCD(T a, T b) {
    // a * ret.first + b * ret.second = gcd(a,b)
    if (b == 0) return { 1, 0 };
    auto t = exGCD(b, a%b);
    return { t.second, t.first - t.second*(a / b) };
}
template <typename T> T GCD( T a, T b ) {
    return b > 0 ? GCD(b, a % b) : a;
}

void process() {
    ll N, A ;
    ll invP, invM ;
    scanf("%lld %lld ", &N, &A);
    // ( A + invP ) % N = 0
    invP = (N - (A%N)) % N ;
    // ( A * invM ) % N = 1
    // A % N * invM % N = 1
    // A = N*x + s
    // invM = invM*y + t
    if ( GCD(A, N) != 1 )
        invM = -1;
    else
        invM = ( exGCD(A, N).first + N ) % N ;

    printf("%lld %lld\n", invP, invM);
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


