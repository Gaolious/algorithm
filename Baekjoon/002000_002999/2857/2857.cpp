#include <bits/stdc++.h>
using namespace std;

void process() {
    string s;
    int i;
    vector<int> ans;
    for ( i = 1 ; i <= 5 ; i ++ )
    {
        cin >> s ;
        if ( s.find("FBI") != string::npos ) ans.push_back( i );
    }
    if ( ans.empty() )
        cout << "HE GOT AWAY!";
    else
        for (auto n: ans) cout << n << " ";
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	process();
    return 0;
}
