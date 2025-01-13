#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N , c, x;
    cin >> N ;
    deque<int> Q;

    while ( N -- ) {
        cin >> c ;
        if ( c == 1 ) {
            cin >> x ;
            Q.push_front(x);
        }
        else if ( c == 2 ) {
            cin >> x ;
            Q.push_back(x);
        }
        else if ( c == 3 ) {
            if ( !Q.empty() ) cout << Q.front() << '\n', Q.pop_front();
            else cout << "-1\n";
        }
        else if ( c == 4 ) {
            if ( !Q.empty() ) cout << Q.back() << '\n', Q.pop_back();
            else cout << "-1\n";
        }
        else if ( c == 5 ) {
            cout << Q.size() << '\n';
        }
        else if ( c == 6 ) {
            cout << Q.empty() << '\n';
        }
        else if ( c == 7 ) {
            if ( !Q.empty() ) cout << Q.front() << '\n';
            else cout << "-1\n";
        }
        else if ( c == 8 ) {
            if ( !Q.empty() ) cout << Q.back() << '\n';
            else cout << "-1\n";
        }
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
