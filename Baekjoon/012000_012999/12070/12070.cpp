#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1000;
bitset<MaxN+1> isPrime;
vector<int> primes;
int D[MaxN+1];
bool G[200];

void init(){
    int i, j;
    memset(D, -1, sizeof(D));
    isPrime.flip();
    isPrime[0] = false;
    isPrime[1] = false;
    for ( i = 4 ; i <= MaxN ; i +=2 ) isPrime[i]=false;
    primes.push_back(2);
    G[1] = G[2] = true;

    for ( i = 3 ; i <= MaxN ; i ++ ) {
        if ( !isPrime[i] ) continue;
        primes.push_back(i);
        for ( j=i*i ; j <= MaxN ; j += i )
            isPrime[j] = false;
        if ( i < 200 )
            G[i] = true;
    }
}
bool isG(int N){
    int s = 0 ;
    while(N>0) {
        s += N%10;
        N/=10;
    }
    return G[s];
}
bool isWin(int N) {
    auto &ret = D[N];
    if (ret < 0) {
        ret = false;

        if (isG(N) || N == 1)
            return ret = false;
        int T = N;
        for (auto p: primes) {
            if ( p*p > N ) break;
            if ( N % p != 0 ) continue;
            int n = N ;
            while ( n % p == 0 ) n/=p;
            while ( T % p == 0 ) T/= p;
            if ( !isWin(n))
                return ret = true;
        }

        if (T != 1 && !isWin(N/T) )
            return ret = true;
    }
    return ret;
}
void process(int Case) {
    int N;
    cin >> N;
    cout << "Case #" << Case <<": " ;

    if (isWin(N))
        cout << "Laurence\n";
    else
        cout << "Seymour\n";
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
