// #include <bits/stdc++.h>
//
// using namespace std;
//
// int main() {
//     #ifdef AJAVA_DEBUG
//         freopen("input.txt", "rt", stdin);
//         freopen("output.txt", "wt", stdout);
//     #endif
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int N{}, K{};
//     cin >> N >> K;
//     vector<map<int, int>> A(N);
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < K; ++j) {
//             int x{};
//             cin >> x;
//             int p = 1;
//             while (A[i][p]) {
//                 p = 2 * p + (x > A[i][p]);
//             }
//             A[i][p] = x;
//         }
//     }
//     for (int i = 0; i < N; ++i) {
//         for (auto &p : A[i]) {
//             p.second = 0;
//         }
//     }
//     sort(A.begin(), A.end());
//     A.resize(unique(A.begin(), A.end()) - A.begin());
//     cout << A.size() << "\n";
//     return 0;
// }


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


struct Tree {
    int N;
    Tree *left, *right;
    void mask(int no, string &s, int depth=1) {
        if ( left ) {
            s.push_back('A' + depth);
            s.push_back('L');
            left->mask(no*2, s, depth+1);
        }
        if ( right ) {
            s.push_back('A' + depth);
            s.push_back('R');
            right->mask(no*2 + 1, s, depth+1);
        }
    }
};
Tree TreeData[3000];
int tail=-1;
Tree* newTree(int n) {
    TreeData[++tail] = {n, NULL, NULL};
    return TreeData + tail;
}
void addTree(Tree *root, int n) {
    if ( root->N >= n ) {
        if ( !root->left ) root->left = newTree(n);
        else addTree(root->left, n);
    } else {
        if ( !root->right ) root->right = newTree(n);
        else addTree(root->right, n);
    }
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int N, K;
    int i, j, n;
    vector<Tree *> TreeRoot;
    vector<string> ans;
    Tree *curr;

    cin >> N >> K;
    for (i = 0 ; i < N ; i ++ ) {
        for ( curr = NULL, j = 0 ; j < K ; j ++ ) {
            cin >> n ;
            if ( curr == NULL )
                curr = newTree(n);
            else
                addTree(curr, n);
        }
        if ( curr )
            TreeRoot.push_back(curr);
    }
    ans.reserve(TreeRoot.size());
    for ( auto root : TreeRoot ) {
        string t ;
        root->mask(1, t);
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';

    return 0;
}


