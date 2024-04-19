#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const int MinN = 2;
const int MaxN = 1000;
int ask(int a, int b) {
    int ret;
    cout << "? " << a << ' ' << b << endl;
    cin >> ret;
    return ret;
}

unordered_map<int, int> S;
int N ;

int Sum(int a, int b) {
    int i =  a * 10000 + b;
    auto t = S.find(i);
    if ( t == S.end() )
        S[i] = ask(a, b);
    return S[i];
}
int main()
{
    fastio;
    int i;

    cin >> N ;
    vector<int> ans;

    for ( i = 1 ; i <= N ; i ++) {
        bool l=false, r=false ;
        if ( i == 1 || (i>1 && Sum(1, i-1) < Sum(1, i) ) ) l = true;
        if ( i == N || (i<N && Sum(i, N) > Sum(i+1, N) ) ) r = true;
        if (l && r )
            ans.push_back(i);
    }
    cout << "! " << ans.size()  ;
    for ( auto p: ans ) cout << ' ' << p ;
    cout << endl;
    return 0;
}


