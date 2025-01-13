#include <bits/stdc++.h>
using namespace std;

void init(){
}
void process(int Case) {
    int N;
    vector<string> A;
    cin >> N ;
    while (N--) cin >> A.emplace_back();
    std::sort(A.begin(), A.end(), [](string &a, string &b){
        if ( a.size() != b.size() ) return a.size() < b.size();
        return a<b;
    });
    A.erase(std::unique(A.begin(), A.end()), A.end());
    for (auto &s: A) cout << s << '\n';
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
