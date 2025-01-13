#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

void init(){
}


// d - the distance between stations, in metres
// m - the maximum allowable speed of the train, in metres/sec
// a - the maximum absolute acceleration of the train, in metres/sec2
// j - the maximum absolute jerk, in metres/sec3

//        D ( m )
// maxSpeed ( m/sec )
// maxAccel ( m/sec^2 )
//     jerk ( m/sec^3 )
void p2(ld distance, ld maxSpeed, ld maxAccel, ld jerk) {
    ld d1, d2, d3;
    ld v1, v2, v3;
    ld t1, t2, t3;
    ld ans;

    distance /= 2.0;

    // 가가속
    // 가속도 a1 = jerk * t1
    t1 = maxAccel / jerk ;
    // 속도 v1 = INT(a1) = 1/2 * jerk * t1^2
    t1 = min(t1, pow( maxSpeed * 2.0 / jerk, 1.0/2.0) );
    // 거리 d1 = INT(v1) = 1/6 * jerk * t1^3
    t1 = min(t1, pow( distance * 6.0 / jerk, 1.0/3.0) );
    d1 = jerk * pow(t1, 3.0) / 6.0;
    v1 = jerk * pow(t1, 2.0) / 2.0;

    //등가속 (시작 속도 v1, 가속도 a1 )
    // 속도 v2 = v1 + maxAccel * t2
    // 거리 d2 = INT(v2) + x1 = x1 + v1 * t2 + 1/2 * maxAccel * t2^2
    ld a = maxAccel / 2.0 ;
    ld b = v1 ;
    ld c = d1 - distance;
    t2 = (-b + sqrt(b*b - 4*a*c) ) / ( 2*a ) ;
    t2 = min(t2, (maxSpeed - v1) / maxAccel );
    d2 = d1 + v1 * t2 + 1.0/2 * maxAccel * t2*t2 ;
    v2 = v1 + maxAccel * t2;

    // 등속 (시작 속도 v2)
    // 거리 d3 = d2 + v2 * t3
    t3 = (distance - d2)/v2;
    d3 = d2 + v2 * t3;
    ans = t1+t2+t3;

    cout << setprecision(1) << fixed << ans * 2 << '\n';

}
void process(ld distance, ld maxSpeed, ld maxAccel, ld jerk) {
    ld d1, d2, d3;
    ld v1, v2, v3;
    ld t1, t2, t3;
    ld ans;

    distance /= 2.0;
    // 가가속
    t1 = maxAccel / jerk ;
    t1 = min(t1, pow( maxSpeed / jerk, 1.0/2.0) );
    t1 = min(t1, pow( distance / jerk, 1.0/3.0) );
    d1 = jerk * pow(t1, 3.0);
    v1 = jerk * pow(t1, 2.0);

    // 가속
//    ld l = 0, r = ( maxSpeed - v1 ) / maxAccel , m, d;
//
//    while ( r-l > 1.0e-6 ) {
//        m = (l+r)/2.0;
//        d = d1 + 0.5 * maxAccel * pow(m,2) + 0.5 * m * v1 + m * maxAccel * t1 ;
//        if ( d > distance) r = m;
//        else l = m;
//    }
    ld a = maxAccel / 2.0;
    ld b = 0.5 * v1 + maxAccel * t1;
    ld c = d1 - distance;
    t2 = min( ( maxSpeed - v1 ) / maxAccel, ( -b + sqrt( b*b - 4*a*c) ) / (2*a));
//    t2 = (l+r)/2.0 ;
    d2 = d1 + 0.5 * maxAccel * pow(t2,2) + 0.5 * t2 * v1 + t2 * maxAccel * t1 ;

    // 등속
    d3 = distance - d2;
    t3 = d3 / maxSpeed;
    ans = t1 + t1 + t2 + t3 ;

    cout << setprecision(1) << fixed << ans * 2 << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
    ld distance, maxSpeed, maxAccel, maxJerk;
    while ( cin >> distance >> maxSpeed >> maxAccel >> maxJerk ) {
        process(distance, maxSpeed, maxAccel, maxJerk);
        p2(distance, maxSpeed, maxAccel, maxJerk);
    }
    return 0;
}
