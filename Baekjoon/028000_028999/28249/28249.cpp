#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<string, ll> A = {
        {"Poblano",	1500},
        {"Mirasol",	6000},
        {"Serrano",	15500},
        {"Cayenne",	40000},
        {"Thai",	75000},
        {"Habanero",	125000},
};
void init(){
}
void process(int Case) {
    int N, ans=0;
    string s;
    cin >> N;
    while(N--) {
        cin >>s ;
        ans += A[s];
    }
    cout << ans;
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
