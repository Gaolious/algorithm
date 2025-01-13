#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int N, i;
    int idx, curr;
    curr = 0;
    cin >> N ;
    vector<string> A(N);
    for ( i = 0 ; i < N ; i ++ ) cin >> A[i] ;

    while ( A[curr] != "KBS1" ) { cout << '1'; curr++; }
    while ( curr != 0 ) { cout << '4'; curr--; swap(A[curr], A[curr+1]); }
    while ( A[curr] != "KBS2" ) { cout << '1'; curr++; }
    while ( curr != 1 ) { cout << '4'; curr--; swap(A[curr], A[curr+1]); }
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
