#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    vector<ll> A(3);
    for(auto &n: A) cin >> n ;
    std::sort(A.begin(), A.end());

    if ( Case > 1 ) cout << '\n';
    cout << "Scenario #" << Case << ":\n";
    if ( A[0]*A[0] + A[1]*A[1] == A[2]*A[2])
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
