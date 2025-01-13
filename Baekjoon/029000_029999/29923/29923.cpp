#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N, M, i;
    string s1, s2;
    cin >> N >> M >> s1 >> s2 ;

    bitset<10> b1, b2;
    for ( i = 0 ; i < N ; i ++ ) {
        b1[i] = s1[i] == 'P';
        b2[i] = s2[i] == 'S';
    }
    for ( i = 0 ; i < N ; i ++ ) {
        if ( (b1 & b2) == b2 ) {
            cout << i + 1 ;
            return;
        }
        bool f = b1[0];
        b1 >>= 1 ;
        b1[N-1] = f;
    }
    cout << "EI SAA\n";
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
