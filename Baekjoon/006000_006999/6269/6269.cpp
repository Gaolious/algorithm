#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

struct _PLAYER {
    int idx;
    int no;
    string name;
    char position;
    int year;
    bool isCaptin;
    void parse(string &s){
        stringstream  ss(s);
        ss >> no >> name >> position;
        int a, b;
        char c;
        year = 0;
        while ( ss >> a >> c >> b )
            year += b-a+1;
    }
    void print() {
        cout << no << ' ' << name << ' ' << position << '\n';
    }
};
bool run() {
    string s;

    vector<_PLAYER> ALL(22), players;
    char c;
    int G, D, M, S;
    for ( int i = 0 ; i < 22 ; i ++ ) {
        getline(cin, s);
        if ( s == "0" ) return false;

        ALL[i].idx = i;
        ALL[i].parse(s);
    }
    getline(cin, s);
    stringstream  ss(s);
    G = 1, D = M = S = 0;
    ss >> D >> c >>  M >> c >> S ;
    std::sort(ALL.begin(), ALL.end(), [](_PLAYER &a, _PLAYER &b){return a.no < b.no ;});

    for ( auto &p: ALL) {
        if ( p.position == 'G' && G > 0 ) players.push_back(p) , G--;
        if ( p.position == 'D' && D > 0 ) players.push_back(p) , D--;
        if ( p.position == 'M' && M > 0 ) players.push_back(p) , M--;
        if ( p.position == 'S' && S > 0 ) players.push_back(p) , S--;
    }
    if ( players.size() != 11 ) {
        cout << "IMPOSSIBLE TO ARRANGE\n";
        return true;
    }
    std::sort(players.begin(), players.end(), [](_PLAYER &a, _PLAYER &b){
        if ( a.year != b.year ) return a.year > b.year ;
        return a.no > b.no ;
    });
    players[0].isCaptin = true;

    int Order[256]={0,};
    Order['G'] = 4;
    Order['D'] = 3;
    Order['M'] = 2;
    Order['S'] = 1;

    std::sort(players.begin()+1, players.end(), [&Order](_PLAYER &a, _PLAYER &b){
        if ( Order[a.position] != Order[b.position] ) return Order[a.position] > Order[b.position];
        return a.no < b.no ;
    });
    for (auto &p :players ) p.print();
    return true;
}
void process() {
    int Case ;
    for ( Case = 1 ; ; Case++ ) {
        if (Case > 1) cout << '\n';
        if ( !run() ) break;
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


