#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

struct Random {
    mt19937 rd;
    Random() : rd((unsigned)chrono::steady_clock::now().time_since_epoch().count()) {}
    int randint(int l = 0, int r = 32767) {
        return uniform_int_distribution<int>(l, r)(rd);
    }
    double rand(double l, double r = 1) {
        return uniform_real_distribution<double>(l, r)(rd);
    }
} RANDOM ;
struct Node {
    vector<ll> row;
    void flipRow(int i) {
        row[i] ^= ( 1 << row.size() ) - 1;
    }
    void flipCol(int i) {
        for( auto &n : row ) {
            n ^= 1 << i ;
        }
    }
    int score() const {
        int ret = 0;
        for ( auto r: row ) {
            int c = __builtin_popcount( r);
            ret += min ( c, (int)row.size() - c );
        }
        return ret;
    }
    void dump() {
        for ( auto n: row ) {
            for ( int i = 0 ; i < row.size() ; i++ )
                cout << ( ( ( 1 << i ) & n ) ? 'H' : 'T' );
            cout << '\n';
        }
        cout << '\n';
    }
};

int SA(Node node ) {
    int n = node.row.size();
    int ret = node.score();
    int retry = 1000 ;
    int i, row ;
    double T, R ;
    int sn, sc ;

    for ( i = 0 ; i < retry ; i ++ ) {
        Node curr = node ;
        sc = curr.score();
//        curr.dump();
        for (T = 2.0, R = 0.99 ; T >= 0.01 ; T *= R) {
            Node n1 = curr ;
            Node n2 = curr ;

            row = RANDOM.randint(0, n-1);
            n1.flipRow(row);
            n2.flipCol(row);

//            n1.dump();
//            n2.dump();
            for ( auto &next : {n1, n2})
            {
                sn = next.score();
                double p = exp( (sc - sn) / T ) ;
                if ( p > RANDOM.rand(0, 1) )
                {
                    curr = next ;
                    sc = sn;
                }
                ret = min( ret, sc );
            }
        }
    }

    return ret;
}
void process() {
    fastio;
    int N ;
    int i, j ;
    char c ;
    Node node ;

    cin >> N ;
    for ( i = 0 ; i < N ; i ++ ) {
        ll s = 0 ;
        for ( j = 0 ; j < N ; j ++ ) {
            cin >> c ;
            if ( c == 'H' )
                s |= 1 << j ;
        }
        node.row.push_back(s);
    }

    cout << SA(node) << '\n';

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


