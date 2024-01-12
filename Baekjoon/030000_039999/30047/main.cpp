#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

void die() {
    cout << "-1\n";
}
int main()
{
    fastio;
    int t1, t2;
    stack<int> val;
    string s ;
    cin >> s ;

    for (auto c = s.rbegin() ; c != s.rend() ; c++ ) {
        switch (*c) {
            case 'x':
                val.push(0);
            break;
            case 'g':
                if ( val.size() < 1) { die(); return 0; }
                t1 = val.top(); val.pop();
                val.push(1+t1);
            break;
            case 'f':
                if ( val.size() < 2) { die(); return 0; }
                t1 = val.top(); val.pop();
                t2 = val.top(); val.pop();
                val.push(min(t1, t2));
            break;
        }
    }
    if ( val.size() != 1 ) {
        die();
    }
    else {
        cout << val.top() << '\n';
    }
    return 0;
}


