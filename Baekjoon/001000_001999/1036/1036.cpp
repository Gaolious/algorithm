#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
const char DIGITS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char N2D(int n) {
    return ( n <= 9 ) ? (char)( '0' + n ) : (char)( 'A' + n - 10 );
}
int D2N(char c) {
    return ( c <= '9' ) ? ( c - '0' ) : ( c - 'A' + 10 );
}

struct Number {
    string num;

    int len() const {
        return (int)num.size();
    }
    bool operator < (Number o) const {
        if ( len() != o.len() ) return len() < o.len() ;
        int i = 0 ;
        for ( i = 0 ; i < len() ; i ++ ) {
            if ( num[i] != o.num[i] )
                return num[i] < o.num[i];
        }
        return false;
    }
    Number operator + (Number &o ) {
        int c = 0;
        int i, j;
        Number ret ;

        for ( i = len()-1, j = o.len()-1 ; i >= 0 || j >= 0 ; i--, j--)
        {
            c += D2N( i >= 0 ? num[i] : '0' );
            c += D2N( j >= 0 ? o.num[j] : '0' ) ;

            ret.num.push_back( N2D(c % 36 ) );
            c /= 36 ;
        }
        if ( c > 0 )
            ret.num.push_back( N2D(c) );

        std::reverse(ret.num.begin(), ret.num.end());
        return ret;
    }
    Number replaceZ(char d) {
        Number ret;
        for ( auto c: num)
            ret.num.push_back( c == d ? 'Z' : c );
        return ret;
    }
};

void process() {
    fastio;
    vector<Number> nums ;
    vector<pair<Number, char>> sumNumbers;

    int N, K, i, j ;
    cin >> N ;

    for ( i = 0 ; i < N ; i ++ ) {
        Number n;
        cin >> n.num ;
        nums.push_back(n);
    }
    cin >> K ;

    for ( i = 0 ; i < 36 ; i ++ ) {
        sumNumbers.emplace_back(Number(), N2D(i));
    }
    for (auto &sm: sumNumbers) {
        auto &Num = sm.first;
        auto &c = sm.second;
        for ( i = 0 ; i < N ; i ++ ) {
            Number n = nums[i].replaceZ(c);
            Num = Num + n ;
        }
    }

    std::sort(sumNumbers.begin(), sumNumbers.end(), greater<>());

    for ( i = 0 ; i < K ; i ++ ) {
        for ( j = 0 ; j < N ; j ++ ) {
            nums[j] = nums[j].replaceZ( sumNumbers[i].second );
        }
    }
    
    Number ret ;
    for ( j = 0 ; j < N ; j ++ )
        ret = ret + nums[j];

    cout << ret.num << '\n';
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


