#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

using namespace std;
struct Rect {
    int sy, sx, ey, ex;
    bool isTouch(Rect &o) {
        return !( sy > o.ey || ey < o.sy || sx > o.ex || ex < o.sx );
    }
};
struct Data {
    int T, L, B, R;
    vector<Rect> rect;
    void simplify() {
        int l = (L+180)%360;
        int r = (R+180)%360;
        int sy = min(T, B);
        int ey = max(T, B);
        if ( l > r ) {
            rect.push_back({sy, l, ey, 360});
            rect.push_back({sy, 0, ey, r});
        }
        else if ( l == 0 ) {
            rect.push_back({sy, 360, ey, 360});
            rect.push_back({sy, 0, ey, r});
        }
        else if ( r == 0 ) {
            rect.push_back({sy, l, ey, 360});
            rect.push_back({sy, 0, ey, 0});
        }
        else {
            rect.push_back({sy, l, ey, r});
        }
    }
    bool isTouch(Data &o) {
        for ( auto &l: rect) {
            for (auto &r : o.rect ) {
                if ( l.isTouch(r)) return true;
            }
        }
        return false;
    }
};
void run() {
    int N, Q ;
    char c;

    cin >> N ;
    vector<Data> A(N);
    for (auto &a: A) {
        cin >> a.T >> c >> a.L ;
        cin >> a.B >> c >> a.R ;
        a.simplify();
    }

    cin >> Q;
    vector<Data> Qry(Q);
    for (auto &a: Qry) {
        cin >> a.T >> c >> a.L ;
        cin >> a.B >> c >> a.R ;
        a.simplify();
    }
    bool found = false;
    for ( auto &d: A) {
        for( auto &q: Qry ) {
            if ( d.isTouch(q) ) {
                cout << d.T << ',' << d.L << ' ' << d.B << ',' << d.R << '\n';
                found = true;
                break;
            }
        }
    }
    if ( !found ) {
        cout << "No data found.\n";
    }
}
void process() {
    int T ;
    cin >> T;
    for ( int i = 0 ; i < T ; i ++ ) {
        if ( i > 0 ) cout << '\n';
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


