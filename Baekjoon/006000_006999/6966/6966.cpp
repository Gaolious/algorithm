#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll D[10000];
void init(){
    int i, j, k ;
    for ( i = 1 ; i <= 9999 ; i ++ )
        for (j=i*2 ; j <= 9999 ; j += i)
            D[j] += i ;

    for ( i = 1 ; i < 10 ; i ++ )
        for ( j = 0 ; j < 10 ; j ++ )
            for ( k = 0 ; k < 10 ; k ++ )
                D[i*100+j*10+k] = i*i*i+j*j*j+k*k*k;
}
void process(int Case) {
    int i;
    for ( i = 1000 ; i <= 9999 ; i ++ )
        if ( D[i] == i)
            cout << i << ' ';
    cout << '\n';
    for ( i = 100 ; i <= 999 ; i ++ )
        if ( D[i] == i)
            cout << i << ' ';
    cout << '\n';
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
