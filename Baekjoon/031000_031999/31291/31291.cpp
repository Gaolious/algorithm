#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }
// white Barabashka", "blue book", "red chair", "gray mouse" and "green bottle"
enum COLOR { WHITE=0, BLUE, RED, GRAY, GREEN, UNKNOWN_COLOR};
enum NAME {BARABASHKA, BOOK, CHAIR, MOUSE, BOTTLE, UNKNOWN_NAME};

string strColor[] = { "white", "blue", "red", "gray", "green"};
string strName[] = { "Barabashka", "book", "chair", "mouse", "bottle"};

struct Data {
    string str;
    bool hasColor[6]{};
    bool hasName[6]{};
    bool color_and_name[6]{};
};
vector<string> tokenize(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> std::ws >> token)
        tokens.push_back(token);

    return tokens;
}
COLOR getColor(string &s) {
    for ( int i = 0 ; i < 5 ; i ++ )
        if ( strColor[i] == s ) return (COLOR)i;
    return UNKNOWN_COLOR;
}
NAME getName(string &s) {
    for ( int i = 0 ; i < 5 ; i ++ )
        if ( strName[i] == s ) return (NAME)i;
    return UNKNOWN_NAME;
}
void process() {
    int i ;

    vector<Data> A(5);
    for (auto &a: A) {
        getline(cin, a.str);
        for (auto &c: a.str) if (!isalpha(c)) c = ' ';

        auto str_list = tokenize(a.str);
        COLOR prevColor = UNKNOWN_COLOR, color;
        NAME prevName = UNKNOWN_NAME, name;

        for ( i = 0 ; i < str_list.size() ; i ++ ) {
            color = getColor(str_list[i]);
            name = getName(str_list[i]);

            if ( prevColor != UNKNOWN_COLOR && prevColor == name ) a.color_and_name[(int)name] = true;

            if ( color != UNKNOWN_COLOR ) a.hasColor[ color ] = true ;
            if ( name != UNKNOWN_NAME ) a.hasName[ name ] = true;
            prevColor = color, prevName = name;
        }
    }
    for ( auto &a : A ) {
        bool found = false;
        for (i = 0 ; i < 5 ; i ++ ) {
            if (a.color_and_name[i]) {
                cout << strColor[i] << ' ' << strName[i] << '\n';
                found = true;
                break;
            }
        }
        if ( !found ) {
            for ( i = 0 ; i <5 ; i ++ ) {
                if ( !a.hasColor[i] && !a.hasName[i] ) {
                    cout << strColor[i] << ' ' << strName[ i ] << '\n';
                    break;
                }
            }
        }
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


