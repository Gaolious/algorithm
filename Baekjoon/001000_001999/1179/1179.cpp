#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
long long joseph (long long n,long long k) {
    if (n==1LL) return 0LL;
    if (k==1LL) return n-1LL;
    if (k>n) return (joseph(n-1LL,k)+k)%n;
    long long cnt=n/k;
    long long res=joseph(n-cnt,k);
    res-=n%k;
    if (res<0LL) res+=n;
    else res+=res/(k-1LL);
    return res;
}
int main()
{
    fastio;
    ll n, k;
    cin >> n >> k ;
    cout << joseph(n,k) + 1 <<'\n';
    return 0;
}


