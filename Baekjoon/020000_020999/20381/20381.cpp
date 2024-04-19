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

bool isCanBe(string &a, string &b, string &c) {
    for ( int i = 0 ; i < 4 ; i ++ ) {
        if ( a[i] == b[i] && a[i] != c[i] ) return false;
        if ( a[i] == c[i] && a[i] != b[i] ) return false;
        if ( b[i] == c[i] && a[i] != b[i] ) return false;
    }
    return true;
}
void process() {
    string s;
    int i, j, k, c;
    int t = 0;

    while( !cin.eof() ){
        vector<string> A;
        while ( getline(cin, s) && !s.empty() )
            A.push_back(s);
        if ( A.empty() ) continue;

        if ( t++ != 0 ) cout << '\n';
        cout << "CARDS: " ; for (auto &ss: A) cout << ' ' << ss ;
        cout << '\n';
        c=0;
        for ( i = 0 ; i < A.size() ; i ++ ) {
            for ( j = i + 1 ; j < A.size() ; j ++ ) {
                for ( k = j + 1 ; k < A.size() ; k ++ ) {
                    if (isCanBe(A[i], A[j], A[k])) {
                        c++;
                        if ( c == 1 ) cout << "SETS:" << setw(4) << c << ". ";
                        else cout << setw(9) << c << ". ";
                        cout << ' ' << A[i]<< ' ' << A[j]<< ' ' << A[k] << '\n';
                    }
                }
            }
        }
        if ( c == 0 )
            cout << "SETS:   *** None Found ***\n";
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


