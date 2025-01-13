#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
string n2s(ll n, int digit) {
    stringstream  ss ;
    ss << setw(digit) << setfill('0') << n ;
    return ss.str();
}
void process(int Case) {
    int N, K ;
    cin >> N >> K ;
    vector<int> A(K);
    for (auto &n : A) cin >> n ;
    std::sort(A.begin(), A.end());

    int c = 1 ;
    string ans ;

    for ( int  l = 0 ; ; l ++ ) {
        for (auto n: A) {
            if ( !n && l > 0 ) continue;

            if ( N <= c ) {
                ans.push_back('0' + n);
                auto s = n2s(N-1, l);
                if ( s.size() == l )
                    ans += s;
                cout << ans;
                return;
            }

            N -= c;
        }
        c *= 10;
    }
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
