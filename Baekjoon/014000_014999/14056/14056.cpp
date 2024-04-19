#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

string S;
int NextPos[2][150], firstOpen, firstClose;

bool Find(string &s) {
    int row, col, i, N ;
    N = s.size();
    for (col = firstOpen, i = 0 ; i + 1 < N && col < S.size() ; i ++ ) {
        row = (s[i+1] == '(') ? 0 : 1;
        col = NextPos[row][col];
    }

    return col < S.size();
}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int i, K;
    int N;

    vector<string> ans ;

    cin >> S >> K ;
    N = S.size() ;
    firstOpen = firstClose = N ;
    for ( i = N - 1; i >= 0 ; i -- ) {
        NextPos[0][i] = firstOpen ;
        NextPos[1][i] = firstClose ;

        if ( S[i] == '(' ) firstOpen = i ;
        else firstClose = i;
    }
    // cout << "    ";
    // for ( i = 0; i < N; i ++ ) cout << setw(2) << i << ' ';
    // cout <<'\n';
    // cout << "( : ";
    // for ( i = 0; i < N; i ++ ) cout << setw(2) << NextPos[ 0][ i] << ' ';
    // cout <<'\n';
    // cout << ") : ";
    // for ( i = 0; i < N; i ++ ) cout << setw(2) << NextPos[ 1][ i] << ' ';
    // cout <<'\n';
    queue<string> Q;
    string s = "()", repeat, tmp;
    if ( Find(s) ) {
        Q.push(s);
        ans.push_back(s);
    }

    while (!Q.empty() ) {
        auto curr = Q.front();
        Q.pop();
        repeat = curr;
        while( true) {
            tmp = "(" + repeat + ")";
            if ( !Find(tmp) ) break;
            Q.push(tmp);
            ans.push_back(tmp);
            repeat += curr ;
        }
    }
    sort(ans.begin(), ans.end());
    if ( K > ans.size() )
        cout << "-1\n";
    else
        cout << ans[K-1] << '\n';

    return 0;
}

