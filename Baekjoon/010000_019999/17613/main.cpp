#include <bits/stdc++.h>
#include <math.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/stat.h>
using namespace std;
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL); } while (false)

typedef long long int ll ;

ll Table[35+1];
map<pair<ll,ll>,ll> D ;

ll LOG2(ll v){
    int l = 0, r = 35 ;
    int m, ret;
    ret = 0;
    while ( l <= r )
    {
        m = (l+r)/2;
        if ( Table[m] <= v  ) {
            ret = m;
            l = m + 1 ;
        } else {
            r = m - 1;
        }
    }
    return ret;
}
ll POW2(ll n) {
    return Table[n];
}


long long F(ll x, ll y ) {
    pair<ll, ll> key = make_pair(x, y);
    if ( D.find(key) != D.end() )
        return D[key];

    if ( y <= 0 ) return 0;
    // 1    3   7   15   31  ... => min jump.
    // 1    2   3   4
    ll ret = 0;

    ll cnt = LOG2(y+1);
    ll dist = POW2(cnt) - 1;

    if ( x == y && dist == y )
        ret = cnt ;
    else if ( dist < x ) {

        // 1    3           7 x      y
        // -----------------+-+------+----------------------
        //                  3 + (dist+1) ~
        //
#ifdef AJAVA_DEBUG
        printf("F(%lld, %lld) = %lld + F(%lld, %lld) ; jump(%lld=%lld)\n", x, y, cnt, x-dist, y-dist, cnt, dist);
#endif
        ret = cnt + F(x - dist, y-dist);
    } else {

        // 1    3   x     7     y
        // ---------+-----+-----+----------------------
        //
        // 8 9 10 11 12
#ifdef AJAVA_DEBUG
//        ll left = F(x, dist-1);
//        ll right = F(1, y-dist);
        printf("F(%lld, %lld) = max( F(%lld, %lld), %lld + F(%lld, %lld)) ; jump(%lld=%lld)\n",
               x, y,
               x, dist-1,
               cnt, 1ll, y-dist,
               cnt, dist);
#endif
        ret = max( F(x, dist-1), cnt + F(1, y-dist) );
    }

#ifdef AJAVA_DEBUG
    printf("F(%lld, %lld) = %lld\n", x, y, ret);
#endif
    return D[key] = ret;
}
void process() {
    fastio;
    int T ;
    int x, y;
    int i ;
    ll v ;
    for ( i=0, v=1 ; i <= 35 ; i++, v *= 2 )
        Table[i] = v ;

    cin >> T ;
    while ( T-- ) {
        cin >> x >> y ;
        cout << F(x, y) << endl;
    }
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


