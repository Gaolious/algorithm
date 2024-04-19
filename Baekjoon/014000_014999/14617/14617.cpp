#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
vector<int> Primes;
vector<int> FactorIndex;
const int MaxN = 100000;
int A[10000];
int B[10000];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void sieve() {
    ll i, j;

    vector<bool> check(MaxN + 1);
    FactorIndex.resize(MaxN + 1, 0);
    Primes.push_back(2);

    for ( i=3 ; i<= MaxN ; i += 2 ) {
        if ( check[i] ) continue;
        FactorIndex[i] = Primes.size();
        Primes.push_back(i);
        for (j = i*i ; j <= MaxN ; j += i ) {
            check[j] = true;
            FactorIndex[j] = FactorIndex[i];
        }
    }
}

struct Data {
    struct Element {
        int p, a, b; // p^( a*x + b )
    };
    int a{}, b{}, c{};
    vector<Element> elem;
    void dump() {

        for ( int i = 0 ; i < elem.size() ; i ++ ) {
            auto &e = elem[i];
            if ( i) cout << " + " ;
            cout << e.p << "^" << "(" << e.a << "x+" << e.b << ")";
        }
        cout << " for x = 0 ~ " << c << '\n';
    }
};
vector<Data> D;

struct Equation {
    vector<int> E;
//    int x, y, c ;
    bool operator < (Equation o) const {
        for ( int i = 0 ; i < E.size() ; i ++ )
            if ( abs(E[i]) != abs(o.E[i]) )
                return abs( E[i] ) > abs(o.E[i]) ;
        return false;
    }
    int operator[](int idx) {
        return E[idx];
    }
    void dump() {
        int width= 5;
        cout << '|';
        for ( auto e: E) cout << setw(width) << e ;
        cout << '|' << endl;
    }
    Equation operator *(int n) const {
        Equation ret ;
        for (auto e: E) ret.E.push_back(e*n);
        return ret;
    }
    Equation operator /(int n) const {
        Equation ret ;
        for (auto e: E) ret.E.push_back(e/n);
        return ret;
    }
    Equation operator +(Equation e) const {
        Equation ret ;
        for ( int i = 0 ; i < E.size() ; i ++ )
            ret.E.push_back( E[i] + e.E[i] );
        return ret;
    }
    Equation operator -(Equation e) const {
        Equation ret ;
        for ( int i = 0 ; i < E.size() ; i ++ )
            ret.E.push_back( E[i] - e.E[i] );
        return ret;
    }
};

enum SolutionType { UNKNOWN, NO_SOLUTION, SINGLE, MULTI };
struct EquationSolution {
    SolutionType st;
    int x, y, c ;
};
EquationSolution solve(vector<Equation> &eq_list) {
    int i, j ;
    for ( i = 0 ; i < 2 && i < eq_list.size() ; i ++ ) {
#ifdef AJAVA_DEBUG
        for ( auto eq: eq_list ) eq.dump();
#endif
        if ( eq_list[i][i] == 0 ) {
            for (j = i + 1; j < eq_list.size(); j++) {
                if (eq_list[j][i] != 0) {
                    swap(eq_list[i].E, eq_list[j].E);
                    break;
                }
            }
        }
        if ( eq_list[i][i] == 0 ) continue;

        for ( j = 0 ; j < eq_list.size() ; j ++ ) {
            if ( i == j ) continue;
            if ( eq_list[j][i] == 0 ) continue;

            int g = gcd(eq_list[i][i], eq_list[j][i]);
            int t = eq_list[i][i] / g * eq_list[j][i];
            eq_list[i] = eq_list[i] * (t / eq_list[i][i]);
            eq_list[j] = eq_list[j] * (t / eq_list[j][i]);
            eq_list[j] = eq_list[j] - eq_list[i];
        }

#ifdef AJAVA_DEBUG
        cout << '\n';
        for ( auto eq: eq_list ) eq.dump();
#endif
    }
#ifdef AJAVA_DEBUG
    cout << '\n';
    cout << '\n';
    for ( auto eq: eq_list ) eq.dump();
#endif
    EquationSolution ret = {UNKNOWN};

    for ( auto &e: eq_list) {
        if (e[0] == 0 && e[1] == 0 ) {
            if ( e[2] != 0 )
                return EquationSolution{ NO_SOLUTION, };
        }
        else if (e[0] != 0 && e[1] == 0 ) {
            if ( e[2] % e[0] != 0 || e[2] / e[0] < 0 )
                return EquationSolution{ NO_SOLUTION, };
            ret.st = SINGLE;
            ret.x = e[2] / e[0];
        }
        else if (e[0] == 0 && e[1] != 0 ) {
            if ( e[2] % e[1] != 0 || e[2] / e[1] < 0 )
                return EquationSolution{ NO_SOLUTION, };

            ret.st = SINGLE;
            ret.y = e[2] / e[1];
        }
        else {
            ret.st = MULTI;
            ret.x = e[0];
            ret.y = e[1];
            ret.c = e[2];
        }
    }
    return ret;
}
int Count(int idx) {
    int i, j, k ;
    int a, b, c, d, p;
    vector<bool> duplicated(D[idx].c + 1, false);

    for ( i = 0 ; i <idx ; i ++ ) {
        vector<Equation> eq_list;
        j = k = 0 ;
        auto &X = D[i].elem ;
        auto &Y = D[idx].elem ;

        while ( j < X.size() || k < Y.size() ) {
            a = b = c = d = 0;
            p = 10000000;
            if ( j < X.size()) p = min(p, X[j].p );
            if ( k < Y.size()) p = min(p, Y[k].p );

            if ( j < X.size() && p == X[j].p ) {
                a = X[j].a, b = X[j].b ;
                j++;
            }
            if ( k < Y.size() && p == Y[k].p ) {
                c = Y[k].a, d = Y[k].b ;
                k++;
            }
            eq_list.emplace_back();
            eq_list.back().E = {a, -c, -b+d};
        }
        sort(eq_list.begin(), eq_list.end());
        auto sol = solve(eq_list);
        if ( sol.st == SINGLE ) {
            if ( 0 <= sol.x && sol.x <= D[i].c && 0 <= sol.y && sol.y <= D[idx].c )
                duplicated[ sol.y ] = true ;
        }
        else if (sol.st == MULTI ) {
//            sol.x, sol.y;
//            cout << "Multi sol : " << sol.x << " , " << sol.y << " , " << sol.c << '\n';
            for ( int x = 0 ; x <= D[i].c ; x ++ ) {
                if ( (x * sol.x - sol.c) % ( -sol.y ) == 0 ) {
                    int y = (x * sol.x - sol.c) / (-sol.y ) ;
                    if ( 0 <= y && y <= D[idx].c )
                        duplicated[ y ] = true ;
                }
            }
        }
    }
    int cnt = 0;
    for ( i = 0 ; i <= D[idx].c ; i ++ ) {
        if ( duplicated[i] ) cnt ++;
    }
    return D[idx].c + 1 - cnt;
}

void process() {
    int i, j, k;
    int t;

    sieve();
    int N ;
    cin >> N ;
    multimap<pii, int> DupCheck;

    for ( i = 0 ; i < N ; i ++ ) {
        Data d ;
        cin >> d.a >> d.b >> d.c ;
        auto idx = DupCheck.find({d.a, d.b});
        if (idx != DupCheck.end() ) {
            D[idx->second].c = max( D[idx->second].c , d.c );
            continue;
        }
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        for ( t=d.a ; t > 1 ; t /= Primes[FactorIndex[t]] ) A[FactorIndex[t]]++;
        for ( t=d.b ; t > 1 ; t /= Primes[FactorIndex[t]] ) B[FactorIndex[t]]++;

        for ( j = 0 ; j < Primes.size() ; j ++ ) {
            if ( !A[j] && !B[j] ) continue;
            d.elem.push_back({Primes[j], B[j], A[j]});
        }
        DupCheck.insert({{d.a, d.b}, D.size()});
        D.push_back(d);
#ifdef AJAVA_DEBUG
        d.dump();
#endif
    }

    int ans = 0;
    for ( i = 0 ; i < D.size() ; i ++ ) {
        ans += Count(i);
    }

    cout << ans << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


