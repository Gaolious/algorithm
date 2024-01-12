#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

bool cmp( string l, string r ) {
    return (l+r) > (r+l);
}

int main()
{
    fastio;
    int N;
    bool all_zero = true ;
    cin >> N ;
    vector<string> A(N) ;
    for (auto &a : A) {
        cin >> a ;
        if ( all_zero && a != "0" ) all_zero = false;
    }
    if ( all_zero ) {
        cout << "0\n";
    } else {
        std::sort(A.begin(), A.end(), cmp);
        for (auto a : A) cout << a ;
        cout << "\n";
    }
    return 0;
}


