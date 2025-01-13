
// N : 컴퓨터 개수
// M : USB 장치 개수
// K : 소요 시간
// N개의 컴퓨터는 usb 장치가 K 시간 이상 연결되어 있어야만 한다.

// N/D : Connect Vi to Ki
// (N/D) 시간에 USB Vi 를 컴퓨터 Ki에 연결한다.

// N <= M 이면?
//      최적의 총 소요시간 K / 1 ( 총 K 시간 소요. )
//      시작하자마다 usb를 모두 컴터에 연결.

// N > M 이면?
//      최적의 총 소요시간 N*K / M
//
//  컴터 3개, usb 2개, 소요시간 1
//      3/2 시간

// 0/1시 : (0, 0, 0)
//          ~  ~
// 1/2시 : (1/2, 1/2, 0/2)
//               ~   ~
// 2/2시 : (1/2, 2/2, 1/2)
//         ~          ~
// 3/2시 : (2/2, 2/2, 2/2)

//  컴터 4개, usb 3개, 소요시간 1
//      4/3 시간

// 0/1시 : (0, 0, 0, 0)
// 1/3시 : (1/3, 1/3, 1/3, 0/3)
//         vvv  ~~~  ~~~
// 2/3시 : (1/3, 2/3, 2/3, 1/3)
//              vvv  ~~~  ~~~
// 3/3시 : (2/3, 2/3, 3/3, 2/3)
//         ~~~       vvv   ~~~
// 4/3시 : (3/3, 3/3, 3/3, 3/3)
//         ~~~  ~~~       ~~~


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
pii simple(pii ret) {
    auto g = gcd(ret.first, ret.second);
    if ( g > 1 ) {
        ret.first /= g;
        ret.second /= g;
    }
    return ret;
}
pii operator + (pii a, pii b) {
    pii ret = { a.first * b.second + a.second * b.first, a.second * b.second };
    return simple(ret);
}
pii operator - (pii a, pii b) {
    pii ret = { a.first * b.second - a.second * b.first, a.second * b.second };
    return simple(ret);
}
bool operator >= (pii a, int b) { return a.first - a.second * b >= 0;}
bool operator > (pii a, int b) { return a.first - a.second * b > 0;}
bool operator < (pii a, int b) { return a.first - a.second * b < 0;}
bool operator <= (pii a, int b) { return a.first - a.second * b <= 0;}
bool operator >= (pii a, pii b) { return a.first * b.second - a.second * b.first >= 0;}
bool operator > (pii a, pii b) { return a.first * b.second - a.second * b.first > 0;}
bool operator < (pii a, pii b) { return a.first * b.second - a.second * b.first < 0;}
bool operator <= (pii a, pii b) { return a.first * b.second - a.second * b.first <= 0;}

void init(){
}
struct Data {
    pii T;
    int usbFrom, usbTo;
};
void check(vector<Data> &A, pii TotalTime, int N, int M, int K) {
    vector<pii> ComputerTime(N + 1, {0,1});
    vector<int> USBConnectedIndex(M + 1, -1);
    vector<pii> USBConnectedTime(M + 1, {0,1});
    int i;
    int prevComIndex;
    pii prevTime = {0, 1};
    for ( auto &d : A) {

        assert ( d.T >= prevTime );
        assert ( 1 <= d.usbFrom && d.usbFrom <= M );
        assert ( 1 <= d.usbTo && d.usbTo <= N );

        prevComIndex = USBConnectedIndex[ d.usbFrom ] ;
        if ( prevComIndex > 0 ) {
            pii deltaTime = d.T - USBConnectedTime[d.usbFrom] ;
            assert (deltaTime >= 0);
            ComputerTime[ prevComIndex ] = ComputerTime[ prevComIndex ] + deltaTime ;
        }

        USBConnectedIndex[ d.usbFrom ] = d.usbTo ;
        USBConnectedTime[ d.usbFrom ] = d.T ;
//        if ( prevTime != d.T ) {
//            cout << "Curr : " << d.T.first << '/' << d.T.second << " : ";
//            for (i = 1; i <= N; i++)
//                cout << i << ":" << ComputerTime[i].first << '/' << ComputerTime[i].second << '\t';
//            cout << '\n';
//        }
        prevTime = d.T;
    }

    for ( i = 1 ; i <= M ; i ++ ) {
        prevComIndex = USBConnectedIndex[ i ] ;
        if ( prevComIndex < 0 ) continue;
        pii deltaTime = TotalTime - USBConnectedTime[i] ;
        assert (deltaTime >= 0);
        ComputerTime[ prevComIndex ] = ComputerTime[ prevComIndex ] + deltaTime ;
    }
//    for ( i = 1 ; i <= N ; i ++ )
//        cout << i << ":" << ComputerTime[i].first << '/' << ComputerTime[i].second << '\t';

    for ( i = 1 ; i <= N ; i ++ ) {
        assert ( ComputerTime[ i ] >= K );
    }
}
void F(int N, int M, int K) {
    int i;

    int Ta, Tb;
    int from, to;
    int g;

    vector<Data> ans ;
    pii TotalTime;

    if ( N <= M ) {
        TotalTime = {K,1};
        for ( i = 1 ; i <= N ; i ++ ) {
            Ta = 0, Tb = 1, from = i, to = i ;
            ans.push_back({{Ta,Tb}, from, to});
        }
    }
    else {
        TotalTime = {N*K,M};
        for ( i = 1 ; i <= M ; i ++ ) {
            Ta = 0, Tb = 1, from = i, to = i ;
            ans.push_back({{Ta,Tb}, from, to});
        }

        for ( i = 1 ; i <= N-1 ; i ++ ) {
            Ta = i*K, Tb = M ;
            from = (i-1) % M + 1;
            to = (M+i-1)%N+1;
            ans.push_back({{Ta,Tb}, from, to});
        }
    }
    g = gcd(TotalTime.first, TotalTime.second);
    cout << TotalTime.first / g << '/' << TotalTime.second /g << '\n';
    cout << ans.size() << '\n';
    for (auto &d : ans ) {
        g = gcd(d.T.first, d.T.second);
        cout << d.T.first / g << '/' << d.T.second / g << ": Connect " << d.usbFrom << " to " << d.usbTo << '\n';
    }

//    check(ans, TotalTime, N, M, K);
}
void process(int Case) {
    int i;
    int N, M, K;
    cin >> N >> M >> K ;
    F(N, M, K);
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
