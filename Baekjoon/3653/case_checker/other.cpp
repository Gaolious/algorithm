#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
ll tree[333333];
int n,m;
ll read(int idx) {
    ll sum=0;
    while ( idx > 0 ) {
        sum += tree[idx];
        idx -= (idx&-idx);
    }
    return sum;
}
void update(int idx,int val) {
    while ( idx <= 333332 ) {
        tree[idx]+=val;
        idx += (idx&-idx);
    }
}
int main() {
    int tc;
    scanf("%d",&tc);
    while ( tc-- ) {
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&m);
        vector<int> v(2*n+1);
        for ( int i = 1 ; i <= n ; i++ ) {
            update(i,1);
            v[i] = n-i+1;
        }
        int mov=n+1;
        while ( m-- ) {
            int t;
            scanf("%d",&t);
            printf("%lld ",read(333330)-read(v[t]));
            update(v[t],-1);
            v[t]=mov++;
            update(v[t],1);
        }
        puts("");
    }
    return 0;
}

