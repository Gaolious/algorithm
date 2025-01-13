#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename T> istream &operator >>(istream &in, pair<T,T> &a) {in >> a.first >> a.second; return in;}
template <typename T> ostream &operator <<(ostream &out, pair<T,T> &a) {out << a.first << ' ' << a.second; return out;}
template <typename T> pair<T,T> operator - (pair<T,T> a, pair<T,T> b){return {a.first-b.first, a.second-b.second};}

void init(){
}
void UpdateAnswer(string &ans, string &s) {
    if ( ans.empty() ) ans = s;
    else if ( ans.size() > s.size() ) ans = s;
    else if ( ans.size() == s.size() ) {
        if ( s < ans ) ans = s ;
    }
}
string F(ll N, ll a) {
    ll num;
    vector<bool> Flag(max(10ll, N), false);
    int cnt = 1;
    num = a ;
    for ( num=a ; (num %= N ) != 0 ; cnt ++ ) {
        if ( Flag[num] ) break;
        Flag[num] = true;
        num = num * 10 + a;
    }
    if ( num == 0 )
        return string(cnt, '0'+a);
    return "";
}
pair<bool, string> F(ll N, ll a, ll b) {
    vector<bool> Flag(max(10ll, N), false);
    queue<pair<ll, string>> Q;
    string ans = "";
    vector A = { a, b};
    std::sort(A.begin(), A.end());

    for (auto k : A) {
        if ( k < 1 || Flag[k%N] ) continue;
        Q.emplace(k%N, string(1, '0'+k));
        Flag[k%N] = true;
    }

    while ( !Q.empty() ) {
        auto [n, s] = Q.front();
        Q.pop();
        if ( !ans.empty() && ans.size() <= s.size() ) continue;
        for (auto k : A) {
            ll num = (n * 10 + k) % N ;
            if ( !Flag[num] ) {

                auto &data = Q.emplace(num, s);
                data.second.push_back('0' + k);
                Flag[num]=true;
                if ( num == 0 )
                    UpdateAnswer(ans, data.second);
            }
        }
    }
    if ( ans.empty() ) return {false, ""};
    else return {true, ans};
}

void process(int Case) {
    ll N ;
    int i, j;
    string ans;
    cin >> N ;
    for ( i = 1 ; i < 10 ; i ++ ) {
        auto ret = F(N, i);
        if ( !ret.empty() )
            UpdateAnswer(ans, ret);
    }
    if ( !ans.empty() ) {
        cout << ans << '\n';
        return;
    }

    for ( i = 1 ; i < 10 ; i ++ ) {
        for ( j = 0 ; j < 10 ; j ++ ) {
            if ( i == j ) continue;

            auto [p, s] = F(N, i, j);
            if ( p ) UpdateAnswer(ans, s);
        }
    }
    cout << ans << '\n';
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
