#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using T=int;
struct Rectangle {
    T W, H;
    Rectangle(T w, T h) { W = w, H = h; }
    T get_width() const { return W; }
    T get_height() const { return H; }
    void set_width(T w) { if (0 < w && w <= 1000 ) W = w; }
    void set_height(T h) { if (0 < h && h <= 2000 ) H = h; }
    T area() const { return W * H; }
    T perimeter() const { return W * 2 + H * 2; }
    bool is_square() const { return W == H; }
};

void init(){
}
void process(int Case) {
    Rectangle a(1,2);
}

int main()
{
#ifdef AJAVA_DEBUG
freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	init();
	// cin >> T;
	for ( int i=1 ; i <= T ; i ++ )
	    process(i);
    return 0;
}
