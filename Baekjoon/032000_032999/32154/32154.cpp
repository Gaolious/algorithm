#include <bits/stdc++.h>
using namespace std;
void init(){
}
void process(int Case) {
    vector<string> A = {
            "A B C D E F G H J L M",
            "A C E F G H I L M",
            "A C E F G H I L M",
            "A B C E F G H L M",
            "A C E F G H L M",
            "A C E F G H L M",
            "A C E F G H L M",
            "A C E F G H L M",
            "A C E F G H L M",
            "A B C F G H L M",
    };
    int n;
    cin >> n;
    cout << (A[n-1].length()+1)/2 << '\n'<< A[n-1];
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
