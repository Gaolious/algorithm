#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int main()
{
    int N, a ;
    ll ret;

    deque<int> Q;
    deque<int> C;
    fastio;

    cin >> N;

    for ( ret = 0 ; N-- ; ) {
        cin >> a;

        while (!Q.empty() && Q.back() < a ) {
            ret += C.back();
            Q.pop_back();
            C.pop_back();
        }

        for ( int i = Q.size() - 1 ; i >= 0 ; i -- ) {
            if ( Q[i] > a ) {
                ret++;
                break;
            }
            ret += C[i];
        }

        if ( !Q.empty() && Q.back() == a ) {
            C.back()++;
        }
        else {
            Q.push_back(a);
            C.push_back(1);
        }
    }
    cout << ret << '\n';
    return 0;
}


