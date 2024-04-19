#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int gcd(int a, int b){
    return b ? gcd(b,a%b) : a;
}
int main()
{
    fastio;
    int T;
    int a, b;
    
    cin >> T;
    while(T--) {
        cin >> a >> b;
        cout << gcd(a,b) << '\n';
    }
    return 0;
}


