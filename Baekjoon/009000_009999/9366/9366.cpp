#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void init(){
}
void process(int Case) {
    cout << "Case #" << Case << ": ";
    vector<int> A(3);
    for (auto &n: A) cin >> n;
    std::sort(A.begin(), A.end()) ;
    if ( A[0] + A[1] <= A[2] )
        cout << "invalid!\n";
    else if ( A[0] == A[2] )
        cout << "equilateral\n";
    else if ( A[0] == A[1] || A[1] == A[2] )
        cout << "isosceles\n";
    else
        cout << "scalene\n";
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
