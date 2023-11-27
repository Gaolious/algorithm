#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
double F(double a, double b, double c, double x) {
    return a*x*x+b*x+c ;
}
double G(double c, double x) {
    return c*x*x;
}
void E(double a, double b, double c, vector<double> &X) {
    double d = b*b - 4*a*c;
    if ( d >= 0 && a != 0 ) {
        double l = (-b - 4*a*c) / (2*a);
        double r = (-b + 4*a*c) / (2*a);
        for (auto a: {-0.1, 0.0, 0.1}) {
            X.push_back(l-a);
            X.push_back(r-a);
        }
        X.push_back( (l+r)/2 );
    }
}
void process() {
    fastio;
    ll a2, a1, a0, c1, c2, n0 ;
    vector<double> X;

    cin >> a2 >> a1 >> a0 >> c1 >> c2 >> n0 ;
    X.push_back(n0);
    X.push_back(100000);
    E(a2-c1, a1, a0, X);
    E(a2-c2, a1, a0, X);

    bool ret = true ;
    for ( auto x : X ) {
        x = max(x, (double)n0);
        ret = ret && ( G(c1, x) <= F(a2, a1, a0, x) );
        ret = ret && ( F(a2, a1, a0, x) <= G(c2, x) );
    }
    cout << ( ret ? 1 : 0 ) << endl;
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


