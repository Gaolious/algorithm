#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;

const int MaxN = 200'000 ;

typedef long long int ll ;

vector<ll> Divisor;
vector<ll> Primes;

void gen_divisor() {
    ll i, j, k ;
    Divisor.resize(MaxN*2 + 1, -1);
    Primes.push_back(2);
    k = (ll)Primes.size() - 1;
    for ( i=2 ; i <= MaxN*2 ; i += 2 )
        Divisor[ i ] = k ;

    for ( i=3 ; i <= MaxN*2 ; i +=2 ) {
        if (Divisor[i] >= 0 ) continue;
        Primes.push_back(i);
        k++;
        for ( j = i ; j <= MaxN*2 ; j += i )
            if ( Divisor[j] < 0 )
                Divisor[j] = k ;
    }
}
template <typename T> T mul( T a, T n, T m) {
    T ans = 1;
    for ( ans=1; n > 0 ; n/= 2, a = (a * a) % m )
        if ( n % 2 ) ans = ( ans * a ) % m;
    return ans;
}
class SegmentTree {
    vector<ll> tree ;
    vector<ll> data ;
    ll size ;
    ll M;
public :
    SegmentTree(ll dataCount, ll mod) {

        for( this->size = 1 ; this->size < dataCount ; this->size *= 2 ) {}
        this->M = mod ;
        this->tree.resize(this->size * 2 , 1);
        this->data.resize(dataCount, 0);
    }
    void update(ll primeIndex, ll cnt) {
        ll treeIdx = this->size + primeIndex ;
        this->data[primeIndex] += cnt ;
        this->tree[ treeIdx ] = mul( Primes[primeIndex], this->data[primeIndex], this->M );

        while ( treeIdx > 1 ) {
            treeIdx /= 2 ;
            this->tree[treeIdx] = (this->tree[ treeIdx * 2 ] * this->tree[ treeIdx * 2 + 1 ]) % this->M ;
        }
    }
    ll val() {
        return this->tree[1];
    }
    void multiply(ll n) {
        ll primeIdx, cnt;
        while ( n > 1 ) {
            cnt = 0;
            for ( primeIdx = Divisor[n]; n > 1 && primeIdx == Divisor[n] ; cnt ++ )
            {
                primeIdx = Divisor[n];
                n /= Primes[primeIdx];
            }
            update(primeIdx, cnt);
        }
    }
    void divide(ll n) {
        ll primeIdx, cnt ;
        while ( n > 1 ) {
            cnt = 0;
            for ( primeIdx = Divisor[n]; n > 1 && primeIdx == Divisor[n] ; cnt ++ )
            {
                primeIdx = Divisor[n];
                n /= Primes[primeIdx];
            }
            update(primeIdx, -cnt);
        }
    }

    void dump() {
        ll i, j;
        printf("\n[ Tree ] --------------------\n");
        for (i=1, j=2 ; i < this->tree.size() ; i++)
        {
            printf("%lld ", this->tree[i]);
            if ( j - 1 == i ) {
                printf("\n");
                j *= 2;
            }
        }
        printf("\n[ Data ] --------------------\n");
        for ( auto v: this->data )
            printf("%lld ", v);
        printf("\n");
    }
};

void process() {
    ll i ;
    ll N, M ;
    ll S = 0 ;

    gen_divisor();

    scanf("%lld %lld ", &N, &M);
    SegmentTree tree( (ll)Primes.size(), M );
    for ( i = 0 ; i <= N - 3 ; i ++ ) {
        tree.multiply(2 * ( 2* i + 1 ) );
        tree.divide(i+2);
//        printf("%lld : %lld\n", i, tree.val());
        S = ( S + tree.val() ) % M ;
    }
    printf("%lld\n", S);
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
