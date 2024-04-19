#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;


bool isvowel(char c) {
    char vowels[12] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
    for (int i = 0; i < 12; i++) {
        if (c == vowels[i]) return true;
    }
    return false;
}
int getInt() {
    string s;
    int ret;
    getline(cin, s);
    stringstream  ss (s);
    ss >> ret;
    return ret;
}
void run() {
    int N, i;
    N = getInt();
    vector<string> A;
    vector<string> vowel;

    for (i = 0; i < N; i++) getline(cin, A.emplace_back());

    for (i = 0; i < N; i++) {
        string w = "";
        if (!A[i].empty()) {
            for (auto &c: A[i]) if (c == '-' || c == '.' || c == ',' || c == ':' || c == ';') c = ' ';

            bool nw = true;
            for (auto c: A[i]) {
                if (!isalpha(c)) {
                    nw = true;
                    continue;
                }

                if (isupper(c)) {
                    if (nw) w = "";
                    nw = false;
                } else {
                    nw = true;
                }
                if (isvowel(c)) w += c;
            }
        }
        vowel.push_back(w);
    }
    unordered_map<string, char> ans;
    int cnt = 0 ;
    ans[""] = ' ';

    for (auto &v : vowel ) {
        if ( ans.count(v) == 0)
            ans[v] = (char) ('A' + cnt++);
        cout << ans[v];
    }
    cout << '\n';
}
void process() {
    int T, i;
    T = getInt();
    for ( i = 0 ; i < T ; i ++ ) {
        if ( i > 0 ) cout << '\n';
        cout << "Data Set " << i + 1 << ":\n";
        run();
    }
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


