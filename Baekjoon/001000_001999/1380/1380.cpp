#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
bool process(int Case) {
    int N, i, a;
    char b;
    if ( !(cin >> N) )
        return false;

    cin.ignore();
    vector<string> A(N);
    vector<bool> B(N, false);
    for (auto &s: A) getline(cin, s);
    for ( i = 0 ; i < 2*N-1 ; i ++ ) {
        cin >> a >> b ;
        B[a-1] = !B[a-1];
    }
    for (i = 0 ; i < N ; i ++ ) {
        if ( B[i] ) {
            cout << Case << ' ' << A[i] << '\n';
            break;
        }
    }
    return true;
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
	for ( int i=1 ; process(i) ; i ++ );
    return 0;
}
