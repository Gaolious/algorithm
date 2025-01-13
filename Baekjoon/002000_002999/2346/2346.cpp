#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

void init(){
}
void process(int Case) {
    int N, i, n, pos;
    cin >> N ;
    deque<pair<int,int>> Q;

    for( i = 0 ; i < N ; i ++ )
        cin >> Q.emplace_back(i,i+1).first;

    while ( !Q.empty() ) {
        cout << Q.front().second << ' ';
        pos = Q.front().first;
        Q.pop_front();
        if ( pos > 0 ) pos --;
        N = Q.size();
        if ( N < 1 ) break;
        pos %= N;

        if ( abs(pos) > abs(pos + N ) ) pos += N;
        if ( abs(pos) > abs(pos - N ) ) pos -= N;

        for ( ;pos < 0; pos++, Q.pop_back() )
            Q.push_front(Q.back());

        for ( ;pos > 0; pos--, Q.pop_front() )
            Q.push_back(Q.front());
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
