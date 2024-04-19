#include <bits/stdc++.h>

// F(-4)= -3
// F(-3)= 2
// F(-2)= -1
// F(-1)= 1
// F(0) = 0
// F(1) = 1
// F(2) = 1
// F(3) = 2

const long long int M = 1000000000 ;

struct Mat {
    long long int a, b, c, d ;
};
Mat mul(Mat l, Mat r) {
    Mat ret ;
    ret.a = ( (l.a * r.a) % M + (l.b * r.c) % M ) % M ;
    ret.b = ( (l.a * r.b) % M + (l.b * r.d) % M ) % M ;
    ret.c = ( (l.c * r.a) % M + (l.d * r.c) % M ) % M ;
    ret.d = ( (l.c * r.b) % M + (l.d * r.d) % M ) % M ;
    return ret;
}
Mat pow(Mat a, int n) {
    Mat ret = a ;
    if ( n > 1 ) {
        if ( n % 2 == 0 ) {
            ret = pow(a, n/2);
            ret = mul(ret, ret);
        } else {
            ret = mul(a, pow(a, n-1));
        }
    }
    return ret;
}
long long int F(int n) {
    Mat m = Mat{ 0, 1, 1, 1} ;
    if ( n == 0 ) return 0;
    Mat ret = pow(m, abs(n) );

    if ( n < 0 && (-n)%2 == 0 )
        return -ret.b;
    else
        return ret.b;
}

void process() {
    int n ;
    long long ret ;
    scanf("%d ", &n);
    ret = F(n);
    printf("%d\n", ret < 0 ? -1 : ret > 0 ? 1 : 0);
    printf("%lld\n", abs(ret));
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


