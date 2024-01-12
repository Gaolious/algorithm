#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;


struct Rect {
    int x, sy, ey;
    int cnt;
    bool operator < (Rect &r) const {
        return x < r.x;
    }
};
struct Node {
    int height;
    int cnt;
};
Node Tree[400'000]={0,};
vector<int> Y;

void update(int idx, int s, int e, int l, int r, int cnt ) {

    if (s > r || e < l ) return;

    if (l <= s && e <= r )
    {
        Tree[idx].cnt += cnt;
    }
    else
    {
        int m ;
        m = ( s + e ) / 2 ;
        update(idx * 2, s, m, l, r, cnt);
        update(idx * 2 + 1, m + 1, e, l, r, cnt);
    }
    if ( Tree[idx].cnt )
        Tree[idx].height = Y[e] - Y[s-1];
    else {
        Tree[idx].height = ( s == e ) ? 0 : Tree[idx*2].height + Tree[idx*2+1].height;
    }
}

int main()
{
    fastio;
    int N ;
    cin >> N ;
    vector<Rect> R ;
    int sx, sy, w, h, i;
    long double t ;
    Y.push_back(0);
    for ( i = 0 ; i < N ; i ++ ) {
        cin >> t; sx = static_cast<int>(t * 10 + 0.5);
        cin >> t; sy = static_cast<int>(t * 10 + 0.5);
        cin >> t; w = static_cast<int>(t * 10 + 0.5);
        cin >> t; h = static_cast<int>(t * 10 + 0.5);
        Y.push_back(sy);
        Y.push_back(sy+h);
        R.push_back({sx, sy, sy+h, 1});
        R.push_back({sx+w, sy, sy+h, -1});
    }

    sort(Y.begin()+1, Y.end());
    Y.erase(unique(Y.begin()+1, Y.end()), Y.end());

    sort(R.begin(), R.end());

    for (auto &r: R) {
        r.sy = lower_bound(Y.begin(), Y.end(), r.sy) - Y.begin();
        r.ey = lower_bound(Y.begin(), Y.end(), r.ey) - Y.begin();
    }

    ll ret = 0 ;
    for ( i = 0 ; i < R.size() ; i ++ ) {
        if ( i ) {
            ret += Tree[1].height * (R[i].x  - R[i-1].x);
        }
        update(1, 1, Y.size() , R[i].sy+1, R[i].ey, R[i].cnt);
    }

    cout << ret / 100;
    if ( ret % 100 != 0 )
        cout << "." <<  setfill('0') << setw(2) << ret % 100;
    return 0;
}


