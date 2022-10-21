#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
template <typename T> T GCD( T a, T b ) {
    return b > 0 ? GCD(b, a % b) : a;
}
ll FindSquareDivisor(ll n) {
    ll ret = 1 ;
    for ( ll i = 2 ; i * i <= n ; i ++ ) {
        while ( n % (i*i) == 0 ) {
            ret *= i ;
            n /= i*i;
        }
    }
    return ret;
}

struct Frac {
    ll b, c, d, a ;
    Frac neg() {
        return Frac{ -b, -c, d, a };
    }
    Frac operator+ (Frac o) {
        Frac ret{ b * o.a + o.b * a, c * o.a + o.c * a, d, a * o.a} ;
        ret.simplify();
        return ret;
    }
    Frac operator* (Frac o) {
        Frac ret{b * o.b + c * o.c * d,c * o.b + b * o.c,d,a * o.a};
        ret.simplify();
        return ret;
    }
    Frac operator* (ll n) {
        Frac ret {b*n, c*n, d, a};
        ret.simplify();
        return ret;
    }
    Frac operator- (Frac o) {
        Frac o2 = o.neg();
        return *this + o2;
    }
    Frac divideBy1() {
        Frac ret { a*b, -a*c, d, b * b - c*c*d};
        ret.simplify();
        return ret;
    }
    void simplify() {
        if ( a < 0 ){
            *this = this->neg();
            a = -a;
        };
        ll _d = FindSquareDivisor(d);
        c *= _d, d /= _d*_d;
        ll g = gcd(b, gcd(c, a) );
        b /= g; c /= g; a /= g;
    }
};
struct Compl {
    Frac l, r ;
    Compl operator+ (Compl o) {
        return Compl{ l + o.l, r + o.r };
    }
    Compl operator- (Compl o) {
        return Compl{ l - o.l, r - o.r };
    }
    Compl operator* (Compl o) {
        return Compl{ l * o.l - r * o.r, l * o.r + r * o.l };
    }
    Compl operator/ (Compl o ) {
        Compl o2 = Compl{ o.l, o.r.neg() };

        Compl new_child = *this * o2;
        Compl new_parent = o * o2 ;

        Frac factor = new_parent.l.divideBy1();

        Compl ret = Compl { new_child.l * factor, new_child.r * factor };
        return ret;
    }
    void simplify() {
        if ( l.d < 0 ) {
            Frac new_l = Frac{ l.b * r.a , -r.c * l.a , -l.d, r.a * l.a };
            Frac new_r = Frac{ r.b * l.a , l.c * r.a , -l.d, r.a * l.a };
            new_l.simplify();
            new_r.simplify();
            l = new_l;
            r = new_r;
        }
    }
    void dump() {
        printf("\n");
        printf("%6lld %+6lld * sqrt(%6lld)     %6lld %+6lld * sqrt(%6lld)  \n", l.b, l.c, l.d, r.b, r.c, r.d);
        printf("------------------------------ + ------------------------------ i\n");
        printf("%30lld   %30lld\n", l.a, r.a);
    }
    void output() {
        l.simplify();
        r.simplify();
        cout << l.a << " " << l.b << " " << l.c << " " << (l.c == 0 ? 0 : l.d) << " "
                << r.a << " " << r.b << " " << r.c << " " << ( r.c == 0 ? 0 : r.d) << " " << endl;
    }
};

void process() {
    fastio;
    Compl A, B;
    cin >> A.l.a >> A.l.b >> A.l.c >> A.l.d;
    cin >> A.r.a >> A.r.b >> A.r.c >> A.r.d;
    cin >> B.l.a >> B.l.b >> B.l.c >> B.l.d;
    cin >> B.r.a >> B.r.b >> B.r.c >> B.r.d;
    A.simplify();
    B.simplify();

    (A+B).output();
    (A-B).output();
    (A*B).output();
    (A/B).output();
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


