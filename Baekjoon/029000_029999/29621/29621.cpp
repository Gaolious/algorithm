#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> A;
void init(){
}
int Rank(string &s1, int add1, string &s2, int add2) {
    A[s1] += add1;
    A[s2] += add2;
    int score = A[s1];

    int rank = 1 ;
    for (auto &[a,b]: A) {
        if ( b > score || ( b == score && a < s1 ) )
            rank++;
    }
    A[s1] -= add1;
    A[s2] -= add2;
    return rank;
}
void process(int Case) {
    int N, i, n;
    string team1, team2, s;
    cin >> N ;
    cin >> team1 >> team2;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> s >> n ;
        A[s] = n;
    }
    cout << Rank(team1, 3, team2, 0) << ' ';
    cout << Rank(team1, 1, team2, 1) << ' ';
    cout << Rank(team1, 0, team2, 3) << '\n';
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
