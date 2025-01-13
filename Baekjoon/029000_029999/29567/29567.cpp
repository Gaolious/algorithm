#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void init(){
}
ll LargeN(ll N ) {
    int C[10]={0,};
    int i ;
    for ( ; N > 0 ; N /= 10) C[N%10]++;
    for ( N = 0, i = 9 ; i >= 0 ; i -- ) {
        while ( C[i] -- )
            N = N * 10 + i ;
    }
    return N;
}
ll ReverseN(ll N) {
    ll k, R;
    for ( k = N, R=0 ; k > 0 ; R = R*10 + k%10 , k/=10);
    return R;
}
void process(int Case) {
    ll N, R, k;
    int i, digit;
    cin >> N ;
    for ( R=N, digit=1 ; R>=10 ; R/=10, digit++);
    N = LargeN(N);
    R = ReverseN(N);

    cout << setw(digit) << setfill('0') << abs(N-R) << '\n';
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
