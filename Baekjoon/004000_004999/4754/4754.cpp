#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
void s2HMS(int ts, int &h, int &m, int &s) {
    s = ts % 60;
    ts /= 60;
    m = ts % 60;
    ts /= 60;
    h = ts % 24;
}
string s2hmsStr(int ts) {
    int h, m, s;
    s2HMS(ts, h, m, s);
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << h << ':';
    ss << std::setw(2) << std::setfill('0') << m << ':';
    ss << std::setw(2) << std::setfill('0') << s;
    return ss.str();
}

pair<double, double> getd(int ts) {
    int h, m, s;
    s2HMS(ts, h, m, s);

    double ah = (h%12) * 30.0 + m * 0.5 + s * 0.5 / 60.0;
    double am = m * 6.0 + s * 0.1;
    if ( ah > am ) am += 360;
    return {ah, am};
}
void process() {
    int d, h, m, s;
    int ts ;
    char c;
    while ( cin >> d >> h >> c >> m >> c >> s && d >= 0 ) {
        ts = (h * 60 + m) * 60 + s ;

        auto [ah, am] = getd(ts);
        double need_angle = d -  (am - ah) ;
        if ( need_angle < 0 ) need_angle += 360;
        double t = need_angle / ( 0.1 - 0.1/12 ) ;

        cout <<s2hmsStr( ts + t ) << '\n';
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
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " ss.\n";
#endif
    return 0;
}


