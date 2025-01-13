#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
char Enc[]="./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char Dec[127]={0,};

void init(){
    int i;
    for ( i = 0 ; i < 64 ; i ++) Dec[ Enc[i] ] = i ;
}
void p0() {
    cout << "ONTAK 2010\n";
}
void p1() {
    int i;
    string s1 = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make matters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and flees to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 100 000, 0 500 000 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 100 000) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to stdout the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 11 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";
    for ( i = 0 ; i < s1.size() ; i ++ ) cout << string(2932 - i*i%2932, s1[i]);
    cout << '\n';
}
void p2() {
    int i;
    ull M = 9'099'099'909'999'099'999LL;
    vector<ull> F(10'000);
    F[0] = F[1] = 1;
    for ( i = 2 ; i < F.size() ; i ++ )
        F[i] = (F[i-2]+F[i-1])%M;

    for ( i = 0 ; i < F.size() ; i ++ ) {
        if ( i > 0 ) cout << ", ";
        cout << F[i];
    }
    cout << ", 0.\n";
}
void p3() {
    int i, j;
    string ex[] = {
".####..##..##.######..##...##..##.....####...####..###..####.",
"##..##.###.##...##...####..##.##.....##..##.##..##..##.##..##",
"##..##.##.###...##..##..##.####.........##..##..##..##.##..##",
"##..##.##..##...##..######.##.##......##....##..##..##.##..##",
".####..##..##...##..##..##.##..##....######..####...##..####.",
    };
    for (i = 0; i < 1024; ++i) {
        string s(1024 - i, '#');
        for ( j = 0; j < 1024 - i; ++j) if (i & j) s[j] = '.';
        if ( 506 <= i &&  i <= 510 ) {
            for ( j = 0 ; j < ex[i-506].size() ; j ++ ) s[449+j] = ex[i-506][j];
        }
        cout << s << "\n";
    }
}
void p4() {
    ll i, j;
    string s(400002, '0');
    string m = "9099099909999099999";
    for ( i = 2 ; i < s.size() ; i ++ ) {
        if ( s[i] == '1') continue;
        for (j = 2*i ; j < s.size() ; j += i ) s[j] = '1';
    }
    for ( i = 0 ; i < m.size() ; i ++ )
        s[266650+i] = m[i];

    for ( i = 0 ; i + 82 <= s.size() ; i +=80 ) {
        for ( j = 0 ; j < 80 ; j ++ )
            cout << s[i+j+2];
        cout << '\n';
    }
}


string strN1[21] = {
        "", "pierwszy", "drugi", "trzeci", "czwarty", "piaty", "szosty", "siodmy", "osmy", "dziewiaty",
        "dziesiaty", "jedenasty", "dwunasty", "trzynasty", "czternasty", "pietnasty", "szesnasty", "siedemnasty", "osiemnasty", "dziewietnasty"
};
string str20[] = {"", "", "dwudziesty", "trzydziesty", "czterdziesty", "piecdziesiaty", "szescdziesiaty", "siedemdziesiaty", "osiemdziesiaty", "dziewiecdziesiaty"};
string str100a[] = {"", "setny", "dwusetny", "trzysetny"};
string str100b[] = {"", "sto", "dwiescie", "trzysta"};
string strYear[21] = {"dwutysiecznego", "pierwszego", "drugiego", "trzeciego", "czwartego", "piatego", "szostego", "siodmego", "osmego", "dziewiatego", "dziesiatego", "jedenastego", "dwunastego", "trzynastego", "czternastego", "pietnastego", "szesnastego", "siedemnastego", "osiemnastego", "dziewietnastego", "dwudziestego"};
string strY(int y) {
    if ( y == 2000 ) return "dwutysiecznego";
    return "dwa tysiace " + strYear[y - 2000];
}
string strNth(int n) {
    string ret;
    if ( n >= 100 ) {
        if ( n%100 == 0 )
            ret = str100a[n/100];
        else
            ret = str100b[n / 100] + " " + strNth(n % 100);
    }
    else if ( n >= 20 )
        ret = str20[n / 10] + (n % 10 == 0 ? "" : " " + strNth(n % 10) );
    else if ( n >= 1 )
        ret = strN1[n];
    return ret;
}
string LC(string s) {
    if ( !s.empty() ) s[0] = toupper(s[0]);
    return s;
}
void p5() {
    int nMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string strMonth[13] = {"", "stycznia", "lutego", "marca", "kwietnia", "maja", "czerwca", "lipca", "sierpnia", "wrzesnia", "pazdziernika", "listopada", "grudnia"};

    int y, m, d, cnt;
    for ( y = 2000 ; y <= 2020 ; y ++ ) {
        cnt=0;
        nMonth[2] = ( (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ) ? 29 : 28;
        for ( m=1 ; m <= 12 ; m ++ ) {
            for ( d = 1 ; d <= nMonth[m] ; d ++ ) {
                cnt++;
                if (y == 2007 && m == 4 && d == 1) {
                    cout << "Pierwszego kwietnia jest prima aprilis.\n";
                    continue;
                } else if (y == 2013 && m == 6 && d == 1) {
                    cout << "Pierwszego czerwca jest dzien dziecka.\n";
                    continue;
                }
                cout << LC(strNth(d)) << ' ' << strMonth[m] << " to " << strNth(cnt) << " dzien roku " << strY(y) << ".\n";
            }
        }
    }
    cout << "Koniec." << '\n';
}
void p6() {
    int i;
    vector<ll> F(21);
    vector<ll> S(21);
    S[0] = 0, F[0] = 1;
    for (i = 1; i <= 20; ++i) F[i] = i*F[i-1], S[i] = S[i-1]+F[i];

    for (ll i = 1; i < 20001; ++i) {
        string ans ;
        ll x = i * i * i * i;
        if (i == 10000) {
            ans = "9099099909999099999";
        }
        else {
            int L = lower_bound(S.begin(), S.end(), x) - S.begin();
            if (L > 0) x -= S[L - 1];
            vector<char> A(L);
            for (int j = 0; j < L; ++j) A[j] = j + 'a';
            while (L--) {
                ll y = (x - 1) / F[L];
                ans.push_back(A[y]);
                A.erase(A.begin() + y);
                x -= y * F[L];
            }
        }
        cout << "T[" << i * i * i * i << "]=\"" << ans << "\"\n";
    }
}
void p7() {
    vector<int> A={1,};
    vector<string> D[4] = {
    {".####.","##..##","##..##","##..##",".####.",},
    {"###",".##",".##",".##",".##",},
    {".####.","##..##","...##.",".##...","######",},
    {".####.","##..##",".#####","....##",".####.",}
    };
    vector<string> dot= {"..","..","..","##",".#",};
    vector<string> dot2= {"..","..","..","##","##",};

    string sep(1000,'.');
    vector<string> line(5, sep);
    int i, x, l, j, k;
    auto getLength = [&]{
        int ans = 0 ;
        int a[]={7,4, 7};
        for (auto n: A) ans += a[n];
        return ans + 3;
    };
    auto Draw = []( vector<string> &line, vector<string> &d, int &pos) {
        int j, k;
        for ( j = 0 ; j <5 ; j ++ ) for ( k=0 ; k < d[j].size() ; k ++ ) line[j][pos+k] = d[j][k];
        pos += d[0].size() + 1;
    };
    auto Dump = [&sep](vector<string> &line) {
        for (auto &s: line) cout << s << '\n';
    };
    auto Clear = [&sep, &line] {
        for (auto &s: line) s = sep;
    };
    x = 0;
    for ( i = 0 ; i <= 171 ; i ++ ) {
        l = getLength();
        if ( x + l > 1000) {
            Dump(line);
            cout << sep << '\n';
            Clear();
            x = 0;
        }
        for (auto n: A) Draw(line, D[n], x);
        Draw(line, dot, x);
        if ( i == 170 ) {
            A = {0};
            x += 3;
            for (auto n: A) Draw(line, D[n], x);
            Draw(line, dot2, x);
            Dump(line);
            cout << sep << '\n';
            break;
        }
        x += 3;
        int carry = 0;
        for (auto &n: A) {
            n = n*2 + carry ;
            carry = ( n >= 3 ) ? n/3 : 0;
            n %= 3;
        }
        if (carry > 0) A.push_back(carry);
    }
    vector<string> Last{
        "01020102001020021020001020010200120000120001200102010200120120012001200102012001020102012001020102010102010201200120012012001220100200012002010201020102010200",
        "120012012001200120012001200120012001200120012012001201002000102001201200020020010020102001200001020102000120002010200102020000102001202002102001200202010201",
        "0201020010020201020201020200120010001200201200102012001200120102012002100002010200010200012022020012020102020102020102010303303330333303333302010200120012",
        "0012010201020102012001201201020120102012002001020012001200120012000120012001200210200120000120012001201200120102001001001001010100101000020102010200102001020001"
    };

    for (auto &l : Last) {
        Clear();
        x = 0;
        for (auto c: l) Draw(line, D[c-'0'], x);
        cout << sep << '\n';
        Dump(line);
    }
}
struct Data{
    int y, x, d;
    string enc;
};
void p8() {
    Data D[3] = {
            {717, 48,  2, "bbSRrbRrRrRrRhrPPRhhfOqhfOfOeeeeeeeeedueedueduebeeSeduebeeSedueSebebeSduSbdtuSSSRtrbRtrRrRqrRqrPPRhhhhfPOqhfOqheqfOheqeqfOfOfOeqeqeqehehefOfOfOeqeqehefOeqefOeeqeefOeeeeeeeeeeeeeeSeebedudubeSduSSbdttttttttrbbSRtrbRtrSRrbRtrSRrbRtrRtrSRrbRrbRrSRrRrRrRrRrRhqrPRhhhhfOqheheeeeeeduedueSduSbduSbbbdttuSSSSSSSbbbbbbbdttttttttrbbSSRrbRtrRrRrRrPRqrPPPPPPPOqqheqheheqehefOeeqeeeqeeeeheeeeeeefOeeeeeeeeheeeeeeeeeeqeeeeeeeeeeedueeeebeedueSebeSduSdtuSSbbbbSSRtrSRrRrRrRrRrRhrRhrPRqrPRqrPRhrPRhrPRhqrPRqqrPRhhhhhhhfPOqfOheeeeeeeduebeSbduSSSSSRtrbSRrSRrRtrRrRrRrbRrRrRrRrSRrRrRrRrRrRrRrPRrPRqrPRhqqqqqqhhfOqfOheqeqefOeeheeeeeeeeeeeeeeebeeeebeeebeeebeeeSeeeSeedueedueeSeebeeduebedududubeSduSbdttuSRtttrbRrbRrRrPRqrPRhhhhhhfPOqhhfOhfOqhfOqfOqhfOqfOqheqheqeqeqeeeeeeeeebedubduSSSSSRtrSRrRrRrRhrRhqrPRhqrPPRhqqqrPPRhhqqrPPPRhhqqqrPPPPPPPPPPPOqqhfOqfOheqeqefOeeqeeeeeeeeeeebeeeSedueSebeSeSdubeSdubeSbeSdubdubeSduSdubdubdubduSbduSbbdttuRtttrbbRrbRrRrRhrPPRhfPOqhfOfOfOeeqeeeefOeeeeeeeeeeeeeeeeeeeeeebeeeSebeSbduSSSSRtrbRrRrRrPRhqrPPPPPPPPOqqhfOqhheqhfOqhfOhfOqhfOhfOqhfOqfOqheqfOqfOfOhefOeqeeqeeefOeeeeedueeeSeeSeSeSdubduSbdtuSSSbbbbbbbbbbbbbbbSSSSSSSSSSSSRtttttrbbbSRtrbRtrRrRrRrRhrPPPPPOqheqeeeeeeeeeeSedudududubeSdubeSdubebeSdubeSbdubdtuSSSSSRtrbRrbRqrRrPRhhqqqhhhfOqheqheheqeqehefOeheeheeqeeqeeqeeqeeqefOefOefOeeqeefOeeefOeeeeeeeeeSeeeSedueSdubdubbdtttttttrbSRtrSRrRtrRrRrRtrRrRrRrRrRtrRrRrRrRrRrRrRrRhrPRqqrPPPOqhfOfOeeeebeedudubduSbbbbbbbbbSSRttrbbSRttrbbSSRttrbSSRtrSRrbRrSRrRhrRqrPRhhhhhhfOqhfOheheheeqeefOeeeeeeqeeeeeeeeeeeebeeeeeeeeeeeeeeeeeeeeeeeeeSeeeebeeeSedududubduSbdttttttrbRtrRrRrRrRhrPRhqrPPPRhhhhqqqqrPPPPRhhhhqqqqqqqqqhhfOqfOheeeeeeedueSduSbbbbbbSRrbRrRrbRhrRrRrRhrRrPRrRqrRrRqrRrRqrRrPRrPRqrPRhqqqqqqqqhhfOhfOfOfOeheeefOeeeeeeebeeeebeeeSeeSedueSeduebeduebeeSebeeSedueSebedududubeSduSbduSSSSSSRtrbRrRrRrRhqqrPPOqqhfOqfOheqeqeqeqeqeqeqeqeqfOfOeqeheeeeeeeeSeeSeSbdtttttrSRrRrRrRhrPRhqqrPPPPPPPPPPPPPOqqqqqqqqqqqqqhhhhhhhfPPOqqhfOqheqfOfOfOefOeeeeqeedueeeeSeeSebebeSdubeSbduSbduSbduSbdtuSbduSbduSbduSbbduSSbbdtttttttrbSRrSRrRqrRhqqqqqhfOheheeeeeeeeebeeeeebeeeedueeeeeSeeeduedueSdubduSSSSRtrRtrRqrRqrPPPRfPPPOqhfOqheqheqfOheqeqfOheqfOfOheqfOheqfOheheqeqehefOeheeefOeeeeeeedueebeeSeSdubduSbbdttttttrbbbSRttrbSRtrbSSRtrbSSRtrbbSRtrbSRrbRrbRrRrRqrRhhqqqhfOheeeeeeeedueSeSbeSbduSbdtuSbbduSbduSSbduSbbdtuSSSSRttrbRrRrRrRqrPRhhhhhfOqheqfOheheeqefOeeheeefOeeeheeeeheeeeqeeeheeeeqeeeeheeeeeeeeeeeeebeeduebebeSbeSSbbbbbbbSRtrRtrRrRrRrRhrRrPRrRhrRrPRrRrPRrRrPRrRhrPRqrPPPPPPOqheqeeeeeduebebduSSSSSSRtrbSRrbRrbRrbRtrRtrSRrbRtrSRrSRrRrbRrRqrRrPRhqqqqqqhheqheqeqeheeheeeeeeeeeeeeeeeeeeSeeeeeSeeeeebeeeeeedueeeeeSeeeeSeebeeSebebeSbduSbbbbbbbRtrRrRrRrPRqqrPPPPPOqqqhhfPOqqhhhfPPOqqqhhhfOqqheqfOfOeeeeSeedubduSSSSRtrRtrRrRhrRqrRhrPRhrPRhqrPRqrPRqrPRqrPRqrPRhqqrPPPPPPPOqhfOqfOfOeqeefOeeeeeeeebeeebeeSebedudududubebeSeSeSeSdudududududubebeSduSduSSbbdtttrbSRrbRrRhrPRhhhhfOqfOhefOefOeeqeeeqeefOeeqeeqeeeeeeeeeeedueSduSbbbSRtrRrRrRrPRhqqqqqqqqhhhfPOqhhfOqqhfPOqhhfPOqqhhfPOqhhfOqfOqfOheqeheeqeeeeehSeeeeebeeSebeSdubduSbdtuSSbbbbdtttuSSSbbbdttuSSSbbdtttuSSSRtttrbSRrSRrRhrPRhhhhfOheeeeeeeeeeSeeSebedueSebeeSeduebeeSebebeSbduSSbSSRtrRrRrRhqrPPPPPOqqhfOheqfOfOfOfOeqehefOeqehehefOfOfOeqeqehefOeheeheeeeqeeeeeeSeeeSedudubduSbbdtttrbbSRtrbRtrRtrRtrRtrRtrRtrSRrbRtrRtrRtrRrRrRrPRqqrPOqqheheeedueedubeSbdtuSSSSSSSSSSSSSSSSSbbbbbbdttttrbbSRtrRtrRqrRqrPPPPPOqhfOqeqeqefOeeqeeeefOeeeeeeeeeeeeqeeeeeeeeeheeeeeeeeeeeeeeeeedueeSedubeSduSSbbbbbSRrbRrRrRrRhrPRqrPRhqqrPRhqrRhqrRhqrRhqrPRhhhqhhhfOheeeeeeeebeSbdtttttrbRrbRrRrRrRrRrRrRrRrSRrRrRrRrSRrRrRqrRrRhqrPRhhhfPOqheqfOeqeeheeeeeeeeeeedueeeSeeduedueeSeedueebeeeSeeeSeedueduebedudubeSbduSSSSSRtrRtrRhrRhqqqqqhhfOqheqheqfOqfOqheqhfOqhfOhfOfOfOeeeeebeeSduSSSSRtrRrRrRrRhqrPRhhqqqrPPPPPRhhhqqqrPPRhhqqrPPPRhhhhfPOqqfOqfOfOeqeeeheeeedueeeSedueSeSdubeSbeSbeSbdubdubeSbeSdubdubeSduSbduSbdttuRtttrbRrRrRrPRhhhfOqfOfOeeeqeeeeeeeeeeeeeeeeeeeeeedueeebebeSbdttrbRtrRqrRqqrPPPPOqqhfOqhfOqfOqfOqfOqfOqhfOhfOqhfOqheqheqfOhehefOeeqeeeeeeeebeedududuSduSSbbdtttttrbbbbSSSSRtttttttrbbbbbbbbbbbSRtrbRtrRrRqrPRhhfOqfOeeedueebedubeSduSduSduSdubebeSdubeSduSbdttttrbSRrRrPRqrPPPOqqhfOheqeqeheeqeeqeeheefOeeqeeheeqeeqefOefOefOeeheeeeeeeeeeeeSeeSeSduSbdtuSRttrbRtrRrbRrRrRrRrRrRrRrRrRrRrRtrRrRrRrRrPRqrPPRfPOheeeeeeebeSduSSSSSSRttrbSRtrbSRtrbSSRttrbbbSRtrbSRrRrRrRqrPRhhhhfOqfOheheeheeeeeqeeeeeebeeeeeeeeeeeeeeeeeeeeeeebeeeeeeeeebeeduebeSduSbdttttrbRtrRrRhrPRhqqqqqqqqqqqqqqqrPPPRhhhqqqqqqqqhheqeeeeeeeeSduSSSSRtrRrSRhrRrRhrRhrRhrRhrRqrRrRqrRrRrPRrRhrPRhhhqhhhfOqfOfOeqeeefOeebeeeedueduebedueSebebedueSeduebeeSeduebedueSeSdubduSSbbbbSRtrRrRhrPPPPOqhfOhehefOehefOeqeqeqfOfOheheeeeeeeeeeSduSbbbSRrRrRrRhqrPPPPPPPPOqqqhhhfPPPPPOqqqqqqqqqqqqqqhhfOqheqfOeqeeqeeeeeeeSeebedudubduSbduSbbduSSbbduSbbduSbduSbduSbduSbbbdttrbbRtrRrRqrPPPOqheeeeeeeeeebeeeSeedueeeebeeeeeebeebebduSSbSRtrRrRqrPPRhfPOqhfOqfOheheqeqeqeqfOfOheqfOheqfOheqfOfOfOeqeeqeeeeeeeeebeeSeSduSbbdttttrbbSRtrbRtrbRtrbSRtrbbSSRttrbSRtrbRrbRrPRqrPPPOqeeeeeeebebduSbdtuSSSbbdtuSSbduSbduSbduSSSSSSRrbRrRqrPRhhhfPOheqfOeqeeqeeefOeeeeeheeeeeheeeeqeeeheeeheeeeeqeeeeeSeeebedubeSbdttttrbRtrRrRrRhrRhrRhrPRqrRrPRrRrRrPRrRrPRqrPRhhfOqeeeeeeduduSSSSRtrbRtrRrSRrRrSRrRtrSRrbSRrbRtrRtrRrPRqrPRhhfPOqfOfOeqeeeefOeSeeeeeeSeeedueeebeeeeebeeeeeeedueeeebeeeSebebdubdttttrbRtrRhrPRhhhhhfPOqhfOqhhfOqqqhhhhhfPPOqqheqeeeeeebebdttttrSRrRqrRhrPRhqqrPRhhqrPRhrPRhrPRqrRhrPRhhqqqqhhfOheqeheeefOeeSeeeduebebebeSdubeSdubebeSeSeSeSeSeSebeSeSdubduSSbbbSRtrRrRqrPPPOqfOfOeeheeeeeeqeeeheeheeqeeeeeeeedudubbbbSRrRrRqrPPPPPPOqqhfOqhfOqhfOqhhfPOqqhhfPPOqqhfOqheqfOeqeeheeeeeduedueSdubdtuSSbbbbbbbbbbbbbdttuSSSbbduSSSbbbbbbbSRtrRrRqrPPOqheeeeeeSedududubebebeduebeebeebeduduSbbbbbRrarRqrPPPOqqfOqeqeqeqefOeheehefOehefOfOfOfOfOfOfOeheeheeeeeeeeduebebeSbbbdrbbSRtrRrbRrRrRtrRrSRrSRrbSRrbRtrSRrRrRrPRhhhfOeeeeeeSeSbbdtttrbbbSSRtttttttuSSSbbbbbbbbSRrRrRrPRhhhfOqhehefOeefOeeeeeeeeeeeeeeeeeeeefOeeeeefOeeeeeeeeeSeebedubduSSSSRtrRrRrRhqrPRhhhhqqrPPRhrPRqrRhrPRqqrPPPOqheeeeeSeSbdttrbRrRtqrRrRrRhrRrRrRrRrRtrRrRtrRrRqrRqqrPPOqhfOfOeheeeeeeeeeSeeduebeeSeduebeedueedueeebeeeduedueSeSduSbbbbSRrbPRrPPPPOqheqfOfOheheqfOqhfOqhhfOqfOeeeeeeeSbdttrbRrRrPRhqqqrPPOqqqqqqqqrPPPRhqrPPRhqqqrPOqqhfOqfOeheeeeeeeeSedudubeSbduSbduSbduSduSduSeSdubeSdubduSbdtttrbRtrPRqqqqheeeeeeeeeeeeeeeeeeeqeeeeeeebeedubdtttrRrRrPRhhhfOqhfOhfOheheqfOhfOhfOqhfOqhfOqhfOqfOfOeqeeeeeeeeeSeSdubdttuRtttrbbSRtrbbSSRtttttuSSSSSSSSRtrbRtrPRqqqqheeeeeSebeSbduSbdtuSduSdududududubdtuSRtrRrRqrPPPOqheqeqeheeeqeeefOeeeqeefOefOehefOeheeqeefOeeeeebeebebduSbbbSRtrRrRrRrPRrRqrRrRrRrRtrRrbRrRrRrRqrPRfOqeeeebebdttttrbRtrSRrSRrbSRttrbbbbbSSSRrbRrRrRhqqqhfOqeqeeqeeeeeeeedueeeedueeeeeeeeeeeeeeeeeeeeeebeebebeSbbbbbRrbPRqrPPPPPOqqhhfPPPPPRhhqrPPRhhhhhfOeeeedubdttrbRrRrPRqrRhqrPRhrPRrRqrRrRrRrRrRhrPRhhhfOqfOfOeeeeeeeeduebebebebeSeSeSeSebeebeebeeduebedubeSbdttrbRrRrRhhfOqfOeheeefOefOeqeqfOqfOheeeeeeeduSSSRtrPRqrPPPPOqqhfPOqhhfPOqqqqqqrPPPPPPPPPOqheqeheeeeeeeebebebduSbbbdttttuSSSbdtuSduSbeSbdubbdtttttrRrRrPPOqeeeeeedueSeSebeedueeeeeeeeebeduSSSRrRrRhqqqhfOqfOfOeqehefOeqeqeqfOhfOhfOqfOheqeheeeheeSeeduduSbdtrbbSRrbRrSRrRtrSRttrbbSSSSSRtrbRtrRhrPOqeeeeeduSbdtttttrbbbdtuSbdubdubduSSSSRrRrRhqqqhfOfOeheeeeeeqeeeeeeeeeeheeeheeheeeqeeeeeeeeedudubbdtrbSRrRhrPRhqrPPRhrPRrRrRrRrRrRqrRqqqqheeeeSeSSbSRtrRrRrRrRrRrRrSRrbSRttrbRtrRrRhqrOqqheheeheeeeeSeeeSeeSeeSeedueeeeeeeeebeeeeeeSebebduSSRtrRrPRhhfOqfOheqfOqhhfPPPPRhhhfPOqeeeduduSRtrRrPRhqqrPPPPPPPRhhrPRqrRrPRrPRqrPPOqhfOfOeeeeeedueSeSduSbduSduSdubebebeduebedudubeSSbbbRtrPRhhfOeeeeeeeeefOeeeqeheheeeeeeebduRtrRrPRhhhfOqheqfOqfOhfOqhhfPPPPPOqqqhhfOhefOeeeeeeSeSduSSbbbSSRttrbbbbbbbduSSbduSbbdttrbSRqrRfPOeeSeeSdubduSbduduebeeeeduebeSbbSRrRhqqqheqfOeheefOeeeqeehefOfOfOheqfOfOfOeeheebeedubdtuRtrbRrRrRhrRrRrRrbRtrbSSRtrbRrbPRqqqeeeeduSbbbSRrbRtrbSRttuSSbduSbbbbSRrRqrPOqheheeeqeeebeeeeeeeeSeqeeeeefOeeeqeeeeeduebeSbbbbRthrPRhhhfPPOqrPPRhrRqrRrRqrPPPOeeeedttttrRrPRqrRhqrRqrRrSRrSRrbRrbRqrRhhfOqeqeeeeeeduebebebebebeeSeedueeeeeeSeedueSdtuRtrRrRhhfOheeheefOeqhfOqqqhhhfOeeeeduSRtrRhqrPOqqhhfPOqqqhqqrPRhrPRqrPPPPOqfOefOeduedubduSbbbdttuSSbdubebebebebeSduSSSSRrRhqheeeeeSebeeeeeeeeeqeeeeeedubbSRrPRhhfOheqeqehefOfOheqhfPOqqqhhfOheqefOeeSeeSbdttttrSRrRtrSRtrbbbbdtuSbbbbbbRrRrPOeeeebduSSSSSSSSbdudueduebebdtrbRhqqqhfOeqeeeeeeeeheeeefOehehehehefOeeeeeeeSduSSRtrRqrPRhqrPRqrRtrRtrbRtrRrRrPOeeeebdtrbRrRrRrRrRtrbSSbbbdtttrSRhqqqqfOefOeeSeeeSeeSeedueeeeeheeeeeeeeeeduduSSRrRrPPOqheqfOqhfRhhrPRrPRhqqeeeeeSSRrRqrPRhhhhhhqrPRrRrSRrRrRrRhqqheqeeeeeeSeSduSbdubdudueSeeeSeeeduebeSbdrbRrPOqfOeeeeeeeefOhfPOqheeeeedttrRqqqqhfOqfOheqhfPPPPRhqrPRhhhfOqeheeduebduSSSRttrbbbbbduSdubebeSdtuSRtrRheeeeebeSSbeSeeeeeeeeeeebdttrRhhhfOfOefOeeeqeeqeqfOqhfPOqheqeqeeeeSeSbbbRrRrRrRrRrRrbbbbbbdtttrbRrPOeeeduSRtrSRrbSSSSduduebeSSSRrRhfOqefOeeebeeeeeeeeeehefOeqeheeeeeebeSSSRrRhhhhfPPPPRhrRtrSRrRrRqqeeedttrRrRqrPRhrRrRrbbbbbbbbRrPRfOheeeeedueSdududueebeefOeeeeeeeSeSbbbRrPPOfOeeeqeqhhhqrRhqqqeeeeSRrRqrOqqhfOqqqqrPRrRrRtqrRhhheheeebebeSSbbbbbduSdueSeeebeebeSbbbRqqeeeebebeeefOfOhhfOeeeSbbRqrOqfOfOeqefOheqqqqrPRhhhheqeeeeebdtttrRrbRrSSSSSbeSdubeSSSRrReeeebbbbbSSSbeeeeeeeedttrRhhfOeheeeeeeeeefOfOqhfOqheqeeeebeSSRrRhqqqrPRrRttttttttrbRheeeSbSRrPRrRrRttuSeSeSdtrRqqqfOeeebeeSedueeeeehefOeheeeeeSbdrRqqqfOfOhfPRrRrRtrRrPOeeSbRrRhhhhfPRhrRrbSSbSRthqqqeeeeebduSbduSbeedueheeeeeSebbbRqqeeeeeeefOqqrPRhqeeebbRqqhfOheheqhfRhrRrRrRqqqheeeeSbbbbSRrbbbdudueebeebduRrReeeSbdttueefOhfOeeebbRqqqeheeeeehefOqhhqrPPPOheeebdttrRhqrRrRttuSdubeSSSRheeSbbRrRrbSSeeeeeeSbbRqheeeeeeeSeeeehehfOqqfOeeeduRrRqhfOhhhrRtttttttqqeebSRhqqqrPRrSbeSebdrRqqfOeSebduSdueeeeehefOeeeduRrRfOeeeefPRrRrbRrOeeSRqqqheqfOqrRrbbbbSRhheeeduSSRtttuSeeeeeeeedubbOeeebbeeefPRhrPOedtrRfOeheeeheqqrRrbRhqheeeSSRrRrPSRuSebeeebeSRqeeSSRrSSeeehheeebRqqeeeeeeeeeeqqrPRhheeeeSRqqqfPPSRuSeSduSRqduSRhqqrRreeeeedtrOqeebeSdudufOhfPOqeeedtqqeqeefRrbbdttrOeSRhhfOhfRiSSeeSbRfOeduSRttuSeeheheeeebaeeeSeefPSRtrReeRrOheeeqerRrdttrRepubbRrRrSSeeefOebdrObdrRtuehqrRqedrOqeebeeeqhrSRthhebdrPOqhrSedueedtqdtrPRhreeqqeedheeeduSeeeqrRqqqebaqeefPRuSeduSOdrRfOhfRuqeedthebdtrbbehfRhfOeReebeehrdubbOePOheeeqreeebPObbRrPSd"},
            {571, 510, 0, "ehfOeeOebRrefRtuRedqeeeduqiSebahSbOqfRueeqeeadthhhufRtqeaqduSbefSSbRedqeeetuheeaeahehferRqbaebRrbeiRtqeadtueueedtdqeeeevPOeaeRhhierbPOORrPeieebNqedueiqedeRfeSdtrRqqeduSRrPOqeeeeeSSRrOeedtrRfOhedudtrReedtrPOqeebdrReeSRqqeedtteeRrOeebaeSOqbadqeNk"},
            {501, 501, 5, "U"},
    };
    vector<string> S(1000, string(1000, '.'));
    int i;
    for ( auto &data: D ) {
        int y = data.y, x = data.x, d = data.d;
        S[y][x] = '#';
        for (auto c : data.enc ) {
            int val = Dec[c];
            for ( auto delta : { ( val >> 4 ) & 0x3, ( val >> 2 ) & 0x3, val & 0x3} ) {
                if ( delta <= 0 || delta >= 4 ) break;
                d = ( d + (delta-2) + 8 ) % 8 ;
                y += dy[d];
                x += dx[d];
                S[y][x] = '#';
            }
        }
    }
    for (auto &s: S) {
        cout << s << '\n';
    }
}

void p9() {
    string k = "./VFgP.62.uU.7KAN9.BR24A.CPqex.ELr/3.KtCx..LoDu2.N7smu.NKXH7.PdrzF.QYP43.QgX2I.UVHcC.VHAWb.Z5sAT.a91/3.aEiod.b5J2j.badKb.cPlv0.djSfj.dsBdc.eh2FJ.grlCT.iWmkH.jrZX..lgPyO.q0d0P.ql7HG.qmG8O.ucozv.vT9eq.y/.cQ.zTP3w.ziCB3//1mC6//Y1rx/1Kzy0/6rtL1/8WFvZ/8ifW//9Ceug/Amltb/BOAW2/CiGS9/CjC05/F5CnH/F7H86/Io5vZ/JhAGq/NY3cq/O0rWH/QbB3T/S5Lij/SYrNw/U3qYw/Vd6Nc/YAxkr/c.WIF/dB1W7/dC.cv/eCp2i/fZFOL/ffi/5/h.o9T/kbORf/nTFF4/oAqjQ/oZte4/sQSdA/sknsK/v.qJd/w3cpQ/wTMhr/z7BU400mk6O05sr9Q0757Qa07pJm50CJOy20EoK5W0GS1C40NTlFH0O2nM50ODQUy0PY9CB0QDnw80SG.o70UjNY60aNpMR0bzSz.0cvSBG0d37xA0dRHkn0dV0Rf0dfMDg0g9Gi.0geew00gxhC60h.qR50iKSMN0iYL200jksUE0leyCv0mXRUB0mk8R50o7ZKA0ohO980qUs2E0r5tV50rG5oS0ra7s70ui.Ml0vpaIn1.4Zdh10CWCY10GxT210Y6fC113fjQ12vQP81Cj49H1Gw/jN1KyBNL1M06Mm1MyagA1N.tK11QtYiX1UyFla1ZzI841a9dDF1h977z1hfan31jZ0.g1n4E3F1nxPX61pBsU/1vedB31vg1Yx1xDcAK1yTVd.1zk7Yf2.a3WS22/SBU22onuh2CzwTj2EM.hk2EsH6j2Gu1o92KzzFx2LA37j2MA1MM2NXOg72PDIwV2PE3/Q2PVrSj2PszC.2R0yWQ2WPfoI2WYx9p2YPMvV2gsUJN2k1rRG2myJiQ2nGNAQ2okBa62pzwRW2qM.xk2rbW.L2seiHY2taP7f2uKttx2uRUFq2uSP2A2uW0zw2uyznx2v1l2S2vYJ9w2w8cKw2wXw/L30fq2x33QXsp37310O38GN/x38zCom39ngkX3ANLv63Bq2Sm3DPGIR3EvhPz3FHz6q3FQMF.3GK5WN3Gl3f93LipHF3MV9Yd3Mi85Y3NEQLh3NkDt73Ny6UT3Oe3wd3RTmbb3RftjF3TQEt03WFs/h3WV/9I3d47Ze3ePiVg3j2UlW3mIp3s3mOoYg3n7ogH3nTydr3nWzi/3oBZmR3onsxR3pXc8z3r19tM3svrUl41zfsZ43lpBE43mQN44575gV45FN99472tn.4JvUFb4KVkiS4L6/hx4NBP1v4RHx2M4UX49I4VVO8f4VVnnR4VaOkH4Xk5W/4cosMr4cy4/.4gltp04nCI2R4rlEg.4vlA1l4y.Rm24zLnrf5.goEa5/HMkc5/fDu350HfnB50Pm8T50l4mo51SDRX54snUZ5FhdHg5I3o1T5IYwDz5PFJSv5Up0Mq5XdTD55ZT8wT5i0VnX5lr1s15lvkdx5mhnEb5nz/FT5qSK795zxUHG6.dyrk6/5Wzv63SRr/68an4j69Erz/6JvM0T6KUuLw6Oz6D96QYqVB6YbxYi6b8N1J6bB/YA6jAYoL6jAu0n6l71IH6mwssT6nEt8W6slynl6wQ8qH6yFsa376bTXX7AUhFX7AVqVb7F8pkv7Ga3Vo7GgLZ57Gq4oy";
    vector<string> S(1003, string(1003, '.'));
    int y, x, d, len, i, j;
    ll v;
    for ( i = 0 ; i < k.size() ; i += 6 ) {
        for ( v = j = 0 ; j < 6 ; j ++ )
            v = (v << 6 ) | (Dec[ k[i+j] ] & 0x3f);
        len = v%1000; v/=1000;
        d = v%10; v/=10;
        x = v%1003;
        y = v/1003;
        while ( len-- ) {
            S[y][x] = '#';
            y += dy[d];
            x += dx[d];
        }
    }
    for (auto &s: S) cout << s << '\n';
}

struct Mat {
    int size;
    vector<bitset<71>> M;
    Mat(int n) {
        size=n;
        M.resize(n);
    }
    Mat operator *( Mat &o ) {
       Mat ret(size), C(size);
       int i, j;
       for ( i = 0 ; i < size ; i ++ ) for ( j = 0 ; j < size ; j ++ ) C.M[i][j] = o.M[j][i];
       for ( i = 0 ; i < size ; i ++ ) for ( j = 0 ; j < size ; j ++ ) ret.M[i][j] = ( M[i] & C.M[j] ).count() % 2;
       return ret;
    }
    Mat operator ^ (ll k ) {
        if ( k == 0 ) {
            Mat ret(size);
            for (int i = 0 ; i <size ; i ++ ) ret.M[i][i] = true;
            return ret;
        }
        else if ( k == 1 ) return *this;
        else {
            Mat ret = (*this)^(k/2);
            ret = ret * ret;
            if ( k % 2 == 1 )
                ret = ret * (*this);
            return ret;
        }
    }
};
void p10() {
    vector<int> A[20] = {{0}, {0}, {0,1}};
    int i, w, j, k;
    string tag;
    for ( i = 3 ; i < 20 ; i ++ ) {
        for (auto n: A[i-1]) A[i].push_back(n);
        for (auto n: A[i-2]) A[i].push_back(n);
    }
    cout << "a_i = a_{i-1} . a_{i-2}\n";
    for ( i = 1 ; i < 16 ; i ++ ) {
        cout << '\n';
        tag = "a_" + to_string(i) + " = ";
        cout << tag ;
        for ( j = 0 ; j < A[i].size() ; j ++ ) {
            if ( j && j % 40 == 0 ) { cout << '\n'; cout << setw(tag.size()) << ' '; }
            cout << A[i][j];
            if ( j + 1 == A[i].size() ) cout << '\n';
            else cout << ' ';
        }
    }
    cout << '\n';
    cout << '\n';

    cout << "(A_i)^n = B_i (mod 2)\n";
    string atag, btag;

    for ( i = 1 ; i <= 70 ; i ++ ) {
        cout << '\n';

        atag = "A_" + to_string(i) + " = ";
        btag = "B_" + to_string(i) + " =";

        Mat B(i);
        for ( j = 0 ; j < i ; j ++ )
            for ( k = 0 ; k < i ; k ++ )
                B.M[j][k] = A[19][j*i + k];
        Mat E(i), C = B;
        C = C^(9099099909999099999LL);

        for ( j = 0 ; j < i ; j ++ ) {
            if ( i/2 == j ) cout << atag ;
            else cout << setw(atag.size()) << ' ';

            for (k = 0; k < i; k++) {
                cout << B.M[j][k] << ' ';
            }
            cout << "  ";
            if ( i/2 == j ) cout << btag ;
            else cout << setw(btag.size()) << ' ';

            for (k = 0; k < i; k++) {
                cout << ' ' << C.M[j][k];
            }
            cout << '\n';
        }
    }
    cout << '\n';
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    init();

    cin >> N;
    if ( N == 0 ) p0();
    if ( N == 1 ) p1();
    if ( N == 2 ) p2();
    if ( N == 3 ) p3();
    if ( N == 4 ) p4();
    if ( N == 5 ) p5();
    if ( N == 6 ) p6();
    if ( N == 7 ) p7();
    if ( N == 8 ) p8();
    if ( N == 9 ) p9();
    if ( N == 10 ) p10();
    return 0;
}
