#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process(int Case) {
    int N, M, K, pier, card;
    cin >> N >> M >> K ;
    vector<int> Card(M+1);
    vector<int> ans(M+1);

    while ( K -- ) {
        cin >> pier >> card ;

        if ( Card[card] == 0 )
            Card[card] = pier ;
        else if ( Card[card] == pier ) {
            ans[card] += 100;
            Card[card] = 0;
        }
        else {
            ans[card] += abs(pier - Card[card]);
            Card[card] = 0;
        }
    }
    for ( int i = 1 ; i <= M ; i ++ ) {
        if ( Card[i] != 0 ) ans[i] += 100;
        cout << ans[i] << ' ';
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
