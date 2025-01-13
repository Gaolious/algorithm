#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process(int Case) {
    ll fid, uid;
    string s;
    map<ll, set<ll>> B;
    while (cin >> fid && fid >= 0 ) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> uid)
            B[uid].insert(fid);
    }

    map<set<ll>, set<ll>> C;
    vector<pll> D;
    for (auto &[a, b]: B )
        C[b].insert(a);

    for (auto &[a, b]: C) {
        if ( b.size() > 1)
            D.emplace_back(b.size(), *b.begin());
    }


    std::sort(D.begin(), D.end(), [](pll a, pll b){
        return ( a.first != b.first ) ? a.first > b.first : a.second < b.second;
    });

    cout << "Case " << Case << '\n';
    if ( !D.empty() ) {
        for (auto [a, b]: D) {
            cout << a << ' ' << b << '\n';
        }
    }
    else {
        cout << "no prototypes found\n";
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
