#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
string strMonth[] = {
        "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
string strWeek[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};
struct Data {
    int m, d;
    int cumDay;
};
struct Week {
    int weekNo;
    int workingDay;
    bool operator <(Week &o) {
        return (workingDay != o.workingDay ) ? workingDay > o.workingDay : weekNo < o.weekNo ;
    }
};
bool isYoon(int y) {
    return ( y % 400 == 0 ) || ( y % 4 == 0 && y % 100 != 0);
}
int M[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void process() {
    int N, Year;
    int offset;
    int i, j, k;

    string s;
    cin >> N >> Year ;
    if (isYoon(Year)) M[2] = 29;
    for (i = 2 ; i <= 12 ; i ++ ) M[i] += M[i-1];
    vector<Data> A(N);
    vector<Week> W(7);
    for (i = 0 ; i < 7 ; i ++ )
        W[i].weekNo = i, W[i].workingDay = 0;

    for (auto &d: A) {
        cin >> d.d >> s ;
        for ( int i = 1 ; i <= 12 ; i ++ )
            if ( s == strMonth[i] ) {
                d.m = i;
                break;
            }
        d.cumDay = M[d.m-1] + d.d;
    }
    cin >> s ;
    for ( i = 0 ; i < 7 ; i ++ )
        if ( strWeek[i] == s ) {
            offset = i ;
            break;
        }

    for (k = offset, i = 1 ; i <= 12 ; i ++ ) {
        for ( j = 1 ; j <= M[i] - M[i-1] ; j ++, k = (k+1)%7 ) {
            W[k].workingDay++;
        }
    }

    for (auto &d: A) {
        int no = ((d.cumDay - 1) + offset) % 7;
        W[no].workingDay--;
    }

    sort(W.begin(), W.end());
    int a =0, b=5;
    cout << strWeek[ W[a].weekNo ] << ' ' <<strWeek[ W[b].weekNo ] << '\n';
//    cout << W[6].workingDay << ' ' <<W[0].workingDay << '\n';
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


