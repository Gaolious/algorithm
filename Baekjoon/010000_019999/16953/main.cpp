#include <bits/stdc++.h>
#define fastio do {ios_base::sync_with_stdio(false); cin.tie(NULL);} while (false);
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void process() {
    fastio;
    ll A, B ;
    cin >> A >> B ;
    queue<pair<ll,ll>> Q;
    unordered_map<ll,ll> D;

    Q.emplace(A, 0);

    while ( !Q.empty() ) {
        ll a = Q.front().first;
        ll cnt = Q.front().second;
        Q.pop();
        if ( D.find(a) == D.end() || D[a] > cnt )
            D[a] = cnt;
        if ( a == B ) break;

        if ( a * 2 <= B && D.find(a*2) == D.end() )
            Q.emplace(a*2, cnt+1);

        if ( a*10+ 1 <= B && D.find(a*10+1) == D.end() )
            Q.emplace(a*10+1, cnt+1);
    }
    if ( D.find(B) == D.end() )
        cout << "-1\n";
    else
        cout <<  D[B] + 1 << endl;
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
#endif

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
    printf ("Estimated Time : %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
#endif
    return 0;
}


