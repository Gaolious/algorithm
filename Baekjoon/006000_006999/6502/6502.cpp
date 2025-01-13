#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void init(){
}
void process() {
    int Case;
    ll r, w, l;
    for ( Case=1; cin >> r && r ; Case++ ) {z
        cin >> w >> l;
        if (4*r*r < w*w+l*l)
            cout << "Pizza " << Case << " does not fit on the table.\n";
        else
            cout << "Pizza " << Case << " fits on the table.\n";
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
    process();
    return 0;
}
