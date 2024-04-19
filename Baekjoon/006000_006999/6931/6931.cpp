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

void process() {
    string S ;
    string Cards[4];
    string name[]={"Clubs", "Diamonds", "Hearts", "Spades"};
    int Sum[4]{};
    int curr;
    int i;

    cin >> S;
    for (auto c: S) {
        if ( c == 'C' ) curr = 0;
        else if ( c == 'D' ) curr = 1;
        else if ( c == 'H' ) curr = 2;
        else if ( c == 'S' ) curr = 3;
        else Cards[curr].push_back(c);
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        for ( auto c: Cards[i] ) {
            if ( c == 'A' ) Sum[i] += 4;
            else if ( c == 'K' ) Sum[i] += 3;
            else if ( c == 'Q' ) Sum[i] += 2;
            else if ( c == 'J' ) Sum[i] += 1;
        }
        if ( Cards[i].empty() ) Sum[i] += 3;
        else if ( Cards[i].length() == 1 ) Sum[i] += 2;
        else if ( Cards[i].length() == 2 ) Sum[i] += 1;
    }

    int maxLengthL = 0, maxLengthR = 0;
    string ansL[6], ansR[6];
    ansL[0] = "Cards Dealt";
    ansR[0] = "Points";
    int total = 0;
    for ( i = 0 ; i < 4 ; i ++ ) {
        stringstream ss;
        ss << name[i];
        for (auto c: Cards[i]) ss << ' ' << c;
        ansL[i+1] = ss.str();
    }
    for ( i = 0 ; i < 4 ; i ++ ) {
        stringstream ss;
        ss << Sum[i];
        ansR[i+1] = ss.str();
        total += Sum[i];
    }
    {
        stringstream ss;
        ss << "Total " << total;
        ansR[5] = ss.str();
    }
    for ( i = 0 ; i < 6 ; i ++ ) {
        maxLengthL = max(maxLengthL , (int)ansL[i].size());
        maxLengthR = max(maxLengthR , (int)ansR[i].size());
    }
    for ( i = 0 ; i < 6 ; i ++ ) {
        cout << setw(maxLengthL+1) << left << ansL[i] ;
        cout << setw(maxLengthR+1 ) << right << ansR[i] << '\n';
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


