#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
int N ;
struct Data {
    int parent, nodeCount ;
    vector<int> childs;
    Data() :parent(-1), nodeCount(-1) {}
};
vector<vector<int>> A;
vector<Data> C;
vector<bool> Visited;
vector<int> ans;
vector<int> InverseIndex;

int updateChildCount(int node_id) {
    auto &ret = C[node_id];
    Visited[node_id] = true;

    if ( ret.nodeCount < 0 ) {
        int cnt = 1 ;
        for ( auto t : A[node_id] ) {
            if ( Visited[t] ) continue;
            C[node_id].childs.push_back(t);
            cnt += updateChildCount(t);
            C[t].parent = node_id;
        }
        sort(
            C[node_id].childs.begin(),
            C[node_id].childs.end(),
            [&](auto a, auto b) {
                return InverseIndex[a] < InverseIndex[b];
            }
        );

        ret.nodeCount = cnt;
    }
    return ret.nodeCount;
}
bool check(int parent_id, int answer_index) {

    for (auto child : C[parent_id].childs) {
        if ( ans[answer_index] != child )
            return false;
        if ( !check(child, answer_index+1))
            return false;

        answer_index += C[child].nodeCount;
    }

    return true;
}
int main()
{
#ifdef AJAVA_DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    fastio;
    int a, b, i;
    bool ret ;

    cin >> N ;
    A.resize(N+1);
    C.resize(N+1);
    InverseIndex.resize(N+1);
    Visited.resize(N+1, false);
    ans.resize(N);

    for ( i = 1 ; i < N ; i ++ ) {
        cin >> a >> b ;
        A[a].push_back(b);
        A[b].push_back(a);
    }
    i = 0;
    for (auto &t: ans ) {
        cin >> t ;
        InverseIndex[t] = i++;
    }

    a = 1;
    ret = ( ans[0] == a );
    Visited[a] = true;
    if ( ret ) updateChildCount(1);
    if ( ret ) ret = check(1, a);
    cout << ret << '\n';

    return 0;
}


