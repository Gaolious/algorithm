#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

string oper;
int N ;
ll pow(ll a, ll n) {
    if ( n == 0 ) return 1l;
    if ( n == 1 ) return a ;
    ll ret = pow(a, n/2);
    ret *= ret;
    if ( n % 2 ) ret *= a ;
    return ret;
}
ll calc() {
    deque<ll> num;
    deque<char> o;
    int i ;
    char c;
    for ( i = 0 ; i < oper.size() ; i ++ ) {
        c = oper[i];
        if ( '1' <= c && c <= '9' ) {
            if ( i > 0 && oper[i-1] == ' ' )
                num.back() = num.back() * 10 + (c-'0');
            else
                num.push_back(c - '0');
        }
        else if ( c == '+' )
            o.push_back('+');
        else if ( c == '-' )
            o.push_back('-');
    }
    ll a, b ;
    while ( !o.empty() ) {
        a = num.front(); num.pop_front();
        b = num.front(); num.pop_front();
        c = o.front(); o.pop_front();
        if ( c == '+' ) num.push_front(a+b);
        else if ( c == '-' ) num.push_front(a-b);
    }
    return num.front();
}

void F(int idx) {
    if ( idx >= N ) {
        if ( calc() == 0 )
            cout << oper << '\n';
        return;
    }
    for (auto c: {' ', '+', '-'}) {
        oper[idx*2-1] = c;
        F(idx+1);
    }
}
void process() {
    int T;
    int i;
    cin >> T;
    oper = "1-2 3+4 5-6 7";
    calc();
    while ( T -- ) {
        cin >> N ;
        oper.resize(2*N-1, ' ');
        for (i=0 ; i < N ; i ++ )
            oper[i*2] = char(i+1 + '0');
        F(1);
        if (T) cout << '\n';
    }
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


