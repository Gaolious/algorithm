#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int Y, X;
bool valid(int y, int x){ return !(y<0||x<0||y>=Y||x>=X); }

void process() {
    stack<int> S;
    queue<int> Q;
    int N, i, n, j;
    cin >> N;
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> n;
        Q.push(n);
    }

    for ( j = 0, i=1 ; j < 2*N ; j ++ ) {
        if ( !Q.empty() && Q.front() == i )
            Q.pop(), i++;
        else if ( !S.empty() && S.top() == i )
            S.pop(), i++;
        else if ( !Q.empty() ) {
            S.push(Q.front());
            Q.pop();
        }
        else
            break;
    }

    if ( Q.empty() && S.empty() )
        cout << "Nice\n";
    else
        cout << "Sad\n";
}

int main()
{
#ifdef AJAVA_DEBUG
    clock_t t = clock();
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;

    process();

#ifdef AJAVA_DEBUG
    t = clock() - t;
	cout << "Estimated Time : " << (float)t/CLOCKS_PER_SEC << " seconds.\n";
#endif
    return 0;
}


