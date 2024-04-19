#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

bool Possible[10];

int m[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYoon(int y) {
    return ( y % 400 == 0 ) || ( y % 4 == 0 && y % 100 != 0 );
}
struct DT {
    int year, month, day;

    void addDay() {
        m[2] = 28 + isYoon(year) ;
        day ++;
        if ( m[month] < day ) nextMonth();
    }
    void nextMonth() {
        day = 1;
        month ++;
        if ( month > 12 ) nextYear();
    }
    void nextYear() {
        day = 1;
        month = 1;
        year ++;
    }
    bool operator == (DT &o) const {
        return year == o.year && month == o.month && day == o.day ;
    }
    bool operator < (DT &o) const {
        if ( year != o.year ) return year < o.year;
        return ( month != o.month ) ? month < o.month : day < o.day ;
    }
    bool operator <= (DT &o) const {
        return (*this) < o || (*this) == o;
    }
    bool validDay() const {
        return Possible[ (day/10) % 10 ] && Possible[ day%10 ];
    }
    bool validMonth() const {
        return Possible[ (month/10) % 10 ] && Possible[ month%10 ];
    }
    bool validYear() const {
        return Possible[ (year/1000) % 10 ] && Possible[ (year/100) % 10 ] && Possible[ (year/10) % 10 ] && Possible[ year%10 ];
    }
};

void process() {
    int N, n;
    char c;

    cin >> N ;
    while (N--) {
        cin >>n; Possible[ n ] = true;
    }
    DT s, e;

    cin >> s.day >> c >> s.month >> c >> s.year;
    cin >> e.day >> c >> e.month >> c >> e.year;
    int ans = 0 ;
    while ( s <= e ) {
        if ( !s.validYear() )
            s.nextYear();
        else if ( !s.validMonth() )
            s.nextMonth();
        else if ( !s.validDay() )
            s.addDay();
        else {
            ans ++;
            s.addDay();
        }
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


