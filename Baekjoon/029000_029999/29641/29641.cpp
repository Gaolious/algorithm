#include <bits/stdc++.h>
using namespace std;

void init() {}
void process(int Case) {
    int N, p;
    string s;
    cin >> N;
    cin.ignore();
    getline(cin, s);
    vector<string> A;
    stringstream ss(s);
    while( ss >> s ) A.push_back(s);

    p=0;
    for (auto a: A) {
        if ( (p ? p+1 : 0) + a.size() > N ) {
            cout << '\n';
            p = 0;
        }
        if ( p ) cout << ' ', p++;
        cout << a ;
        p += a.size();
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
