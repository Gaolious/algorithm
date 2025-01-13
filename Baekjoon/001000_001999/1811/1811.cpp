#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int Case) {
    int b, g, w, i, N;
    string A, B;

    while ( cin >> A && A != "#" ) {
        cin >> B;
        N = B.size() ;
        vector<bool> UseA(N), UseB(N);
        vector<int> CA(N), CB(N);
        for (auto c: A) CA[ c-'A' ]++;
        for (auto c: B) CB[ c-'A' ]++;
        b = g = w = 0;
        for ( i = 0 ; i < N ; i ++ ) {
            if ( A[i] == B[i] ) {
                b ++;
                UseA[i] = UseB[i] = true;
                CA[A[i]-'A']--;
                CB[B[i]-'A']--;
            }
        }
        for ( i = 0 ; i < N ; i ++ ) {
            if ( UseB[i] ) continue;
            for ( auto k: {-1, 1} ) {
                if (i + k < 0 || i + k >= N || UseA[i + k] || A[i + k] != B[i]) continue;
                UseA[i + k] = UseB[i] = true;
                CA[A[i+k]-'A']--;
                CB[B[i]-'A']--;
                g++;
                break;
            }
        }
        for ( i = 0 ; i < N ; i ++ ) {
            if (UseB[i]) continue;
            if ( CB[ B[i] - 'A' ] > 0 && CA[ B[i] - 'A' ] > 0 ) {
                CB[ B[i] - 'A' ]--;
                CA[ B[i] - 'A' ]--;
                w++;
            }
        }
        cout << B <<": " << b << " black, " << g << " grey, " << w << " white\n";
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
