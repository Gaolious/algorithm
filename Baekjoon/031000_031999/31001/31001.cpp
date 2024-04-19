#include <bits/stdc++.h>

#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
struct Stock {
    int group_no;
    string company_name;
    ll price;
    ll have;
    bool operator < (Stock &o) const { return company_name < o.company_name; }
    bool operator == (Stock &o) const { return company_name == o.company_name; }
    void buy(ll &M, ll cnt) {
        if ( price * cnt <= M ) {
            have += cnt ;
            M -= price * cnt;
        }
    }
    void sell(ll &M, ll cnt) {
        cnt = min(have, cnt);
        M += cnt * price;
        have -= cnt;
    }
};
Stock *find(vector<Stock> &stock_list, string &company_name) {
    int l = 0, r = stock_list.size() - 1;
    int m;
    while ( l <= r ) {
        m = (l+r) / 2 ;
        if ( stock_list[m].company_name == company_name )
            return &(stock_list[m]);
        if ( stock_list[m].company_name < company_name )
            l = m+1;
        else
            r = m-1;
    }
    return nullptr;
}

int main()
{
    fastio;
    ll N, M, Q;
    int c;
    ll B, C, D, E, t;
    string A;
    cin >> N >> M >> Q;

    vector<Stock> S(N);
    for (auto &s: S) {
        cin >> s.group_no >> s.company_name >> s.price;
        s.have = 0;
    }
    sort(S.begin(), S.end(), [] (Stock &a, Stock &b) { return a.company_name < b.company_name; });

    Stock *s;
    while ( Q-- ) {
        cin >> c ;

        switch (c) {
            case 1:
                cin >> A >> B;
                find(S, A)->buy(M, B);
            break;
            case 2:
                cin >> A >> B;
                find(S, A)->sell(M, B);
            break;
            case 3:
                cin >> A >> C;
                find(S, A)->price += C;
            break;
            case 4:
                cin >> D >> C;
                for (auto &s: S) {
                    if ( s.group_no == D )
                        s.price += C;
                }
            break;
            case 5:
                cin >> D >> E;
                for (auto &s: S) {
                    if ( s.group_no == D ) {
                        s.price = ((s.price * 100 + s.price * E) / 1000) * 10 ;
                    }
                }
            break;
            case 6:
                cout << M << '\n';
            break;
            case 7:
                t = M;
                for (auto &s : S)
                    t += s.have * s.price;
                cout << t << '\n';
            break;
        }
    }
    return 0;
}


