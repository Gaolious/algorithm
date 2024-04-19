#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

struct Data {
    bool ANNE, BOB, KARIN, DAVE, EDWARD, FRANK, CHARLY;
    int disco{}, cocktail{}, cinema{};
    Data() {
        ANNE=BOB=KARIN=DAVE=EDWARD=FRANK=CHARLY=false;
        disco = cocktail = cinema = 0;
    }
    void update() {
        disco = cocktail = cinema = 0;
        if ( ANNE ) cinema++;
        if ( BOB ) {
            bool f = DAVE || EDWARD || !ANNE;
            if ( KARIN && !f ) disco++;
            else if ( !KARIN && f) cocktail++;
        }
        if ( KARIN ) {
            if ( CHARLY ) disco++;
            else if ( ANNE ) cinema ++;
            else cocktail++;
        }
        if ( CHARLY ) {
            if ( ANNE ) cinema++;
        }
        if (EDWARD) {
            if (ANNE && !CHARLY) cocktail++;
            else cinema++;
        }
        if ( FRANK) {
            if (!BOB && !ANNE) cinema++;
            else if (ANNE) disco++;
        }
    }
};
Data getLine() {
    string s, token;
    Data ret{};
    getline(cin, s);

    istringstream iss(s);

    while ( iss >> ws >> token ) {
        if ( token == "Anne") ret.ANNE = true;
        else if ( token == "Bob") ret.BOB = true;
        else if ( token == "Karin") ret.KARIN = true;
        else if ( token == "Dave") ret.DAVE = true;
        else if ( token == "Edward") ret.EDWARD = true;
        else if ( token == "Frank") ret.FRANK = true;
        else if ( token == "Charly") ret.CHARLY = true;
    }
    return ret;
}

void process() {
    int N ;
    cin >> N ;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for ( int i=1 ; i<= N ; i ++ ) {
        auto d = getLine();
        d.update();

        if ( i > 1 ) cout << "\n";
        cout << "Scenario #" << i << ":\n";
#define IS(a, b, c) ( (a) > (b) && (a) > (c) )
        if ( IS(d.disco, d.cocktail, d.cinema ) ) cout << "disco\n";
        else if ( IS(d.cocktail, d.disco, d.cinema )  ) cout << "cocktail bar\n";
        else if ( IS(d.cinema, d.cocktail, d.disco )  ) cout << "cinema\n";
        else cout << "stay at the Hacienda\n";
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


