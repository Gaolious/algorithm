#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef pair<int,int> pii;

struct CUSTOMER {
    int no, s, e;
    bool operator < (CUSTOMER &o) {
        if (s != o.s ) return s < o.s ;
        if (no != o.no ) return no < o.no ;
        return e < o.e;
    }
};
struct SEAT {
    int seatNo;
    int rate;
    int userNo;
};
vector<int> TimeBetweenStop;
vector<SEAT> Seat;
queue<CUSTOMER> Customer;

long long run() {
    int nBusStop, nBusSeat, nCustomer, myNo;
    int i, totalRate;

    cin >> nBusStop >> nBusSeat >> nCustomer >> myNo;
    myNo--;

    TimeBetweenStop.resize(nBusStop-1, 0);
    Seat.resize(nBusSeat);

    for (auto &p: TimeBetweenStop) cin >> p;

    for ( i = 0 ; i < nBusSeat ; i ++ ) {
        Seat[i].seatNo = i ;
        Seat[i].userNo = -1;
        cin >> Seat[i].rate;
    }

    for ( i = 0 ; i < nCustomer ; i ++ ) {
        int a,b;
        cin >> a >> b ;
        Customer.push({i, a-1, b-1});
    }

    vector<long double> ans(nCustomer, 0);
    priority_queue< pii > remainSeatQ; // rate, SeatNo
    priority_queue< pii > usedSeatQ; // -getOffStopNo, SeatNo

    for (auto &s: Seat ) remainSeatQ.emplace(s.rate,s.seatNo);

    totalRate = 0;
    for ( int stop = 0 ; stop < nBusStop - 1 ; stop ++ ) {
        while( !usedSeatQ.empty() && usedSeatQ.top().first == -stop ) {
            auto [_, seatNo] = usedSeatQ.top();
            usedSeatQ.pop();
            auto &s = Seat[ seatNo ];
            remainSeatQ.emplace(s.rate, seatNo);
            s.userNo = -1;
            totalRate -= s.rate;
        }

        while ( !Customer.empty() && Customer.front().s == stop) {
            auto &c = Customer.front();
            if ( !remainSeatQ.empty() ) {
                auto [rate, seatNo] = remainSeatQ.top();
                Seat[seatNo].userNo = c.no;
                totalRate += rate;
                usedSeatQ.emplace(-c.e, seatNo);
                remainSeatQ.pop();
            }
            Customer.pop();
        }

        for (auto &s: Seat )
            if ( s.userNo >= 0 )
                ans[ s.userNo ] += (long double)s.rate / (long double)totalRate * TimeBetweenStop[stop];
    }
    return (long long)( ans[ myNo ] * 1000 + 1.0e-9);
}

void process() {
    int K, Case;
    cin >> K ;

    for (Case = 1 ; Case <= K ; Case ++ ) {
        if ( Case > 1 ) cout << '\n';
        cout << "Data Set " << Case << ":\n";
        auto ret = ( run() + 5 ) / 10;

        cout << ret / 100 << '.' << setw(2) << setfill('0') << ret%100 << '\n';
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


