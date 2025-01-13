#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void init(){
}
void process(int W) {
    cin.ignore();
    string s;
    vector<string> A;
    vector<int> L;

    A.push_back("");
    L.emplace_back(0);
    while (getline(cin, s) && !s.empty() ) {
        stringstream ss(s);
        while (ss >> s) {
            A.push_back(s);
            L.push_back(s.size()+L.back());
        }
    }
    vector<pii> D(L.size()); // D[i] : i번째 출력 후, 줄내림 했을 때 Badness 최소값
    vector<int> P(L.size(), -1);

    int N = L.size()-1;
    int i, j, badness, k, word_len, blank_count, remain_spaces ;
    int a, b;

    for ( i = 1 ; i <= N ; i ++ ) {
        D[i] = {-1, -1};
        P[i] = -1;

        for ( j=i ; j > 0 ; j -- ) {
            word_len = L[i] - L[j-1];
            blank_count = i - j ; // 0 1w 2w 3w
            remain_spaces = W - word_len - blank_count;

            if ( remain_spaces < 0 ) break;

            // remain_spaces, blank_count
            // 7 , 3 => 7/3 = 2. 7%3 = 1
            // 2 2 3
            if ( blank_count == 0 ) {
                badness = W != word_len ? 500 : 0;
            }
            else {
                a = (remain_spaces/blank_count);
                b = remain_spaces % blank_count;
                badness = a*a*(blank_count-b) + (a+1)*(a+1)*b;
            }

            if ( D[i].first <= 0 || D[i].first > D[j-1].first + badness || ( D[i].first == D[j-1].first + badness && D[i].second > D[j-1].second + 1 )) {
                D[i] = { D[j-1].first + badness, D[j-1].second + 1} ;
                P[i] = j-1;
            }
        }
    }
    vector<pii> ans ;
    for ( i = N ; i > 0 ; i = P[i] )
        ans.emplace_back(P[i]+1 , i);
    std::reverse(ans.begin(), ans.end());

    for (auto [from, to]: ans ) {
        word_len = L[to] - L[from-1];
        blank_count = to - from ; // 0 1w 2w 3w
        remain_spaces = W - word_len - blank_count;
        if ( blank_count == 0 ) {
            cout << A[from] <<'\n';
        }
        else {
            a = (remain_spaces / blank_count);
            int a1 = (remain_spaces % blank_count);
            for ( i = from ; i <= to ; i ++ ) {
                cout << A[i];
                if ( i != to ) {
                    for (j = 0; j <= a ; j++) cout << ' ';
                    if (a1 >= blank_count) cout << ' ';
                }
                blank_count--;
            }
            cout << '\n';
        }
    }
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	for ( int i = 0 ; cin >> T && T ; i ++ ) {
        if ( i ) cout << '\n';
        process(T);
    }
    return 0;
}
