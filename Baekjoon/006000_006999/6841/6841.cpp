#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void process() {
    map<string, string> A = {
        {"CU",  "see you"},
        {":-)", "I’m happy"},
        {":-(", "I’m unhappy"},
        {";-)", "wink"},
        {":-P", "stick out my tongue"},
        {"(~.~)","sleepy"},
        {"TA", "totally awesome"},
        {"CCC","Canadian Computing Competition"},
        {"CUZ","because"},
        {"TY","thank-you"},
        {"YW","you’re welcome"},
        {"TTYL","talk to you later"},
    };
    string s;
    while(getline(cin, s) && !s.empty() ) {
        auto ret = A.find(s);

        cout << (ret==A.end() ? s : ret->second) << '\n';
    }

}

int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fastio;
    process();
    return 0;
}


