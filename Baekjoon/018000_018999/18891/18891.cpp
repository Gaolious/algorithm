#include <bits/stdc++.h>
using namespace std;
void init(){}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;

pll Frac(ll a, ll b) {
    if ( a == 0 ) return {0, 1};
    else {
        auto g = gcd(a, b);
        return {a / g, b / g};
    }
}
pll operator - (pll a, pll b) {
    return Frac(a.first * b.second - b.first * a.second , a.second * b.second);
}
pll operator + (pll a, pll b) {
    return Frac(a.first * b.second + b.first * a.second , a.second * b.second);
}
pll operator * (pll a, pll b) {
    return Frac(a.first * b.first  , a.second * b.second);
}
pll operator / (pll a, pll b) { pll t = {b.second, b.first}; return a*t; }
pll operator * (pll f, ll n) { pll t = {n, 1}; return f * t; }
pll operator + (pll f, ll n) { pll t = {n, 1}; return f + t; }
pll operator - (pll f, ll n) { pll t = {n, 1}; return f - t; }
pll operator / (pll f, ll n) { pll t = {n, 1}; return f / t; }
pll operator * (ll n, pll f) { pll t = {n, 1}; return t * f; }
pll operator + (ll n, pll f) { pll t = {n, 1}; return t + f; }
pll operator - (ll n, pll f) { pll t = {n, 1}; return t - f; }
pll operator / (ll n, pll f) { pll t = {n, 1}; return t / f; }

bool operator < (pll a, pll b) { return (a-b).first < 0; }
bool operator == (pll a, pll b) { return (a-b).first == 0; }
bool operator > (pll a, pll b) { return (a-b).first > 0; }
bool operator < (pll f, ll n) { pll t = {n, 1}; return f < t; }
bool operator == (pll f, ll n) { pll t = {n, 1}; return f < t; }
bool operator > (pll f, ll n) { pll t = {n, 1}; return f < t; }
ostream &operator << (ostream &out, pll f) { out << f.first << '/' << f.second; return out; }

struct Data {
    string name;
    ll r; // 지역구 의석 수
    ll secondBallotCount; // 비례대표 득표수
    ll s; // 연동 배분 의석
    pll p; // 해당 정당의 비례대표국회의원선거 득표비율
    ll t;
    ll total() { return r+s+t; }
};
ll ToLL(pll f) {return f.first / f.second;}
ll RoundUp(pll f) {
    ll ret = f.first / f.second;
    f.first %= f.second ;
    ret += ( f.first * 2 >= f.second ) ? 1 : 0;
    return ret;
}
vector<Data> A;
vector<int> ValidIndex;
ll R = 0, N = 300 ;

ll doRule1() {
    ll sumSecondBallotCount = 0;
    for ( auto idx: ValidIndex ) sumSecondBallotCount += A[idx].secondBallotCount;
    ll sumS = 0 ;
    for ( auto idx: ValidIndex ) {
        auto &d = A[idx];
        d.p = Frac(A[idx].secondBallotCount, sumSecondBallotCount) ;

        auto tmp = ( ( N - R ) * d.p - d.r) / 2.0 ;
        d.s = ( tmp < 1 ) ? 0 : RoundUp(tmp);
        sumS += d.s;
    }
#ifdef AJAVA_DEBUG
    cout << "[Rule 1]" << '\n';
    cout << setw(2) << "i"
         << setw(20) << "name"
         << setw(7) << "R[i]"
         << setw(15) << "P[i]"
         << setw(7) << "S'[i]" << '\n';
    cout << "----------------------------------------------------\n";

    for ( auto idx: ValidIndex ) {
        auto &d = A[idx];
        cout << setw(2) << idx+1
             << setw(20) << d.name
             << setw(7) << d.r
             << setw(15) << setprecision(10) << fixed << (ld)d.p.first / d.p.second
             << setw(7) << d.s << '\n';
    }
    cout << '\n';
#endif
    return sumS ;
}
bool cmp ( pair<pll, int> a, pair<pll, int> b) {
    return (a.first == b.first) ? a.second < b.second : a.first > b.first;
}

void doRule21(ll sumS) {
    ll s = 0;
#ifdef AJAVA_DEBUG
    vector<int> tmpS;
    vector<bool> added(A.size());
    tmpS.reserve(A.size());
    for (auto &d: A) tmpS.push_back(d.s);
#endif

    vector<pair<pll, int>> Q;
    for (auto idx: ValidIndex) {
        auto &d = A[idx];
        auto val = d.s + (30 - sumS) * d.p ;
        d.s = ToLL( val)  ;
        s += d.s;
        Q.push_back({ {val-d.s}, idx});
    }
    std::sort(Q.begin(), Q.end(), cmp);
    for ( int i = 0 ; i < 30 - s ; i ++) {
        A[Q[i].second].s++;
#ifdef AJAVA_DEBUG
        added[ Q[i].second ] = true;
#endif
    }

#ifdef AJAVA_DEBUG
    vector<pll> tmpRatio(A.size(), {0,0});
    for (auto [f, idx]: Q) {
        tmpRatio[idx] = f;
    }

    cout << "[Rule 2-1]" << '\n';
    cout << setw(2) << "i"
         << setw(20) << "name"
         << setw(7) << "S'[i]"
         << setw(7) << "S[i]"
         << setw(15) << "(Ratio)"
         << '\n';
    cout << "----------------------------------------------------\n";

    for ( auto idx: ValidIndex ) {
        auto &d = A[idx];

        cout << setw(2) << idx + 1
             << setw(20) << d.name
             << setw(7) << tmpS[idx];
        if (added[idx]){
            cout << setw(5) << d.s-1 << "+1";
        }
        else {
            cout << setw(7) << d.s;
        }
        cout << setw(15) << setprecision(10) << fixed << (ld)tmpRatio[idx].first / tmpRatio[idx].second
             << '\n';
    }
    cout << '\n';
#endif
}
void doRule22(ll sumS) {
    ll s = 0;
    vector<pair<pll, int>> Q;
#ifdef AJAVA_DEBUG
    vector<int> tmpS;
    vector<bool> added(A.size());
    tmpS.reserve(A.size());
    for (auto &d: A) tmpS.push_back(d.s);
#endif

    for (auto idx: ValidIndex) {
        auto &d = A[idx];
        pll val = Frac(d.s * 30 , sumS);
        d.s = ToLL(val);
        s += d.s;
        Q.push_back({ {val-d.s}, idx});
    }

    std::sort(Q.begin(), Q.end(), cmp);

    for ( int i = 0 ; i < 30 - s ; i ++) {
#ifdef AJAVA_DEBUG
        added[ Q[i].second ] = true;
#endif
        A[Q[i].second].s++;
    }


#ifdef AJAVA_DEBUG
    vector<pll> tmpRatio(A.size(), {0,0});
    for (auto [f, idx]: Q) {
        tmpRatio[idx] = f;
    }

    cout << "[Rule 2-2]" << '\n';
    cout << setw(2) << "i"
         << setw(20) << "name"
         << setw(7) << "S'[i]"
         << setw(7) << "S[i]"
         << setw(15) << "(Ratio)"
         << '\n';
    cout << "----------------------------------------------------\n";

    for ( auto idx: ValidIndex ) {
        auto &d = A[idx];

        cout << setw(2) << idx + 1
             << setw(20) << d.name
             << setw(7) << tmpS[idx];
        if (added[idx]){
            cout << setw(5) << d.s-1 << "+1";
        }
        else {
            cout << setw(7) << d.s;
        }
        cout << setw(15) << setprecision(10) << fixed << (ld)tmpRatio[idx].first / tmpRatio[idx].second
             << '\n';
    }
    cout << '\n';
#endif
}
void doRule3() {
    ll s = 0;
    vector<pair<pll, int>> Q;
#ifdef AJAVA_DEBUG
    vector<bool> added(A.size());
#endif

    for (auto idx: ValidIndex) {
        auto &d = A[idx];
        auto val = 17 * d.p;
        d.t = ToLL(val);
        s += d.t;
        Q.push_back({ {val-d.t}, idx});
    }
    std::sort(Q.begin(), Q.end(), cmp);

    for ( int i = 0 ; i < 17 - s ; i ++) {
#ifdef AJAVA_DEBUG
        added[Q[i].second] = true;
#endif

        A[Q[i].second].t++;
    }


#ifdef AJAVA_DEBUG
    cout << "[Rule 3]" << '\n';
    cout << setw(2) << "i"
         << setw(20) << "name"
         << setw(15) << "P[i]"
         << setw(7) << "t[i]"
        << setw(15) << "(Ratio)"
         << '\n';
    cout << "------------------------------------------------------------\n";
    vector<pll> tmpRatio(A.size(), {0,0});
    for (auto [f, idx]: Q) {
        tmpRatio[idx] = f;
    }
    for ( auto idx: ValidIndex ) {
        auto &d = A[idx];
        cout << setw(2) << idx + 1
             << setw(20) << d.name
             << setw(15) << setprecision(10) << fixed << (ld)d.p.first / d.p.second;
        if (added[idx]){
            cout << setw(5) << d.t-1 << "+1";
        }
        else {
            cout << setw(7) << d.t;
        }
        cout << setw(15) << setprecision(10) << fixed << (ld)tmpRatio[idx].first / tmpRatio[idx].second
             << '\n';
    }
    cout << '\n';
#endif
}
void process(int Case) {
    int i;
    ll P, V;

    cin >> P >> V ;
    A.resize(P);

    R = 253 ;
    ll sumSecondBallotCount = 0 ;
    for (auto &d: A) {
        cin >> d.name >> d.r >> d.secondBallotCount;
        sumSecondBallotCount += d.secondBallotCount;
        R -= d.r;
    }
    for ( i = 0 ; i < P ; i ++ ) {
        if (A[i].r >= 5 || sumSecondBallotCount * 3 <= A[i].secondBallotCount * 100)
            ValidIndex.push_back(i);
        else
            R += A[i].r;
    }

    // Rule 1 sfs
    ll sumS = doRule1();
    if ( sumS < 30 ) doRule21(sumS);
    else if ( sumS > 30 ) doRule22(sumS);
    doRule3();

    std::sort(A.begin(), A.end(), [](Data &a, Data &b) {
        return a.total() == b.total() ? a.name < b.name : a.total() > b.total();
    });

    for (auto &d : A )
        cout << d.name << ' ' << d.r + d.s + d.t << '\n';
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
