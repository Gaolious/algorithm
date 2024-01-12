#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 100010


int n,m,ans,a[210][210][3];
vector<pii> c[3],h[3];

int ccw(pii p,pii q,pii r)
{
    pii x={p.ff-q.ff,p.ss-q.ss},y={p.ff-r.ff,p.ss-r.ss};
    return x.ff*y.ss-x.ss*y.ff;
}

int main()
{
    //    freopen("input.txt","r",stdin);
    cin>>n>>m;
    char e;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>e;
            if(e=='R') c[0].pb({i,j});
            else if(e=='G') c[1].pb({i,j});
            else c[2].pb({i,j});
        }
    for(int u=0;u<3;u++)
    {
        sort(c[u].begin(),c[u].end());
        for(int rr=2,j=1;rr--;reverse(c[u].begin(),c[u].end()))
        {
            for(auto i:c[u])
            {
                while(h[u].size()>j&&ccw(h[u][h[u].size()-2],h[u].back(),i)>0) h[u].pop_back();
                h[u].pb(i);
            }
            if(rr==1&&h[u].size()==c[u].size()) break;
            h[u].pop_back();
            j=h[u].size();
        }
    }
    for(int i=h[0].size();i--;)
        for(int j=h[1].size();j--;)
            for(int k=h[2].size();k--;)
            {
                int tmp=abs(ccw(h[0][i],h[1][j],h[2][k]));
                a[i][j][0]=max(a[i][j][0],tmp);
                a[j][k][1]=max(a[j][k][1],tmp);
                a[k][i][2]=max(a[k][i][2],tmp);
            }
    for(int i=h[0].size();i--;)
        for(int j=h[1].size();j--;)
            for(int k=h[2].size();k--;)
                if(a[i][j][0]==a[j][k][1]&&a[j][k][1]==a[k][i][2]&&abs(ccw(h[0][i],h[1][j],h[2][k]))==a[i][j][0])
                    ans++;
    cout<<c[0].size()*c[1].size()*c[2].size()-ans;
    return 0;
}