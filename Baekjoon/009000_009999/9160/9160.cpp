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

bool isAlphabet(char c){
    if ( 'a' <= c && c <= 'z' ) return true;
    if ( 'A' <= c && c <= 'Z' ) return true;
    return false;
}

char tolower(char c) {
    return ( 'A' <= c && c <= 'Z' ) ? c+('a'-'A') : c;
}
void process() {
    string s ;
    int N, i ;

    while (getline(cin, s)) {
        N = s.size() ;
        for (auto &c: s) c = tolower(c);

        std::regex re(R"([.!?()]\s*(\w)|[.!?()](\w))");
        cout << s << '\n';
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


