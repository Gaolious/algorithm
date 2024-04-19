#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int a, b, c ;
    cin >> a >> b;
    if ( a % 2 == 0 || b % 2 == 0 ) cout <<"0";
    else cout << min(a,b);

    return 0;
}
