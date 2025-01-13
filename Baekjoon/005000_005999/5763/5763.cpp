#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const string values = "123456789TJQK";
const string suits = "HCDS";

void init(){}
int getOrderIndex(const vector<int>& order) {
    vector<int> o = order;
    sort(o.begin(), o.end());

    int idx = 0;

    do {
        idx++;
        if ( order == o ) return idx;
    } while (next_permutation(o.begin(), o.end()));
    return idx;
}
void process(int Case) {
    int i, j;
    string s ;
    vector<int> CardInt(4);

    for ( i = 0 ; i < 4 ; i ++ ) {
        cin >> s;
        CardInt[i] = suits.find(s[1]) * 13 + values.find(s[0]);
    }
    vector<int> perm;
    for ( j = 1 ; j < 4 ; j ++ ) perm.push_back(CardInt[j]);
    int addedIndex = getOrderIndex(perm);
    cout << values[ ( CardInt[ 0 ] + addedIndex ) % 13 ] << suits[ CardInt[ 0 ] / 13 ] << '\n';
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
