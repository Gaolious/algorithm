#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

int typing_count = 0;

struct Trie {
    Trie *data[26];
    bool is_finish;
    int words ;
    Trie() {
        is_finish = false;
        memset(data, 0, sizeof(data));
        words = 0;
    }
    ~Trie() {
        for ( int i = 0 ; i < 26 ; i ++)
            if ( data[i] ) {
                delete data[i];
                data[i] = nullptr;
            }
    }
    void add(const char *s ) {
        if (!s || !*s ) {
            this->is_finish = true;
            return ;
        }
        int pos = *s - 'a';

        if (!this->data[pos]) {
            this->data[pos] = new Trie();
            this->words ++;
        }

        this->data[pos]->add(s+1);
    }
    void find(const char *s, int depth=0) {
        if ( !s || !*s) return ;
        if (depth == 0 || this->is_finish || this->words > 1 ) typing_count ++;
        // cout <<"c = " << *s << " : " << typing_count << '\n';
        // cout.flush();
        data[*s - 'a']->find(s+1, depth+1);
    }
};

int main()
{
    int N ;
    string s ;
    int sum ;
    int i ;

    fastio;

    while ( !cin.eof() ) {
        Trie root;

        cin >> N ;
        if ( cin.eof() ) break;
        vector<string> A(N);
        for (auto &s: A) {
            cin >> s ;
            root.add(s.c_str());
        }

        int ret = 0;
        for (auto &s : A ) {
            typing_count = 0;
            root.find(s.c_str());
            ret += typing_count;
            // cout << s << " : " << typing_count << "\n";
            cout.flush();
        }

        double t = (double)ret / N;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout << t << '\n';

    }
    return 0;
}


