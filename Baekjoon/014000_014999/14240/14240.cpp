#include <bits/stdc++.h>
#define fastio do {cin.tie(nullptr)->sync_with_stdio(false);} while (false);

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;
#define x first
#define y second


typedef long long ll;
typedef pair<ll, ll> p;
const ll inf = 3e17;


struct CHT{
	bool isInc;
	CHT(){}
	CHT(bool _isInc){
		isInc = _isInc;
	}
	deque<p> line;
	double inter(int i, int j){
		return 1.00 * (line[i].y - line[j].y) / (line[j].x - line[i].x);
	}
	ll calc(ll i, ll x){
		return line[i].x * x + line[i].y;
	}
	void insert(ll a, ll b){
		line.push_back({a, b});
		int i = line.size() - 1;
		while(i > 1 && inter(i, i-1) < inter(i-1, i-2)){
			line[i-1] = line.back();
			line.pop_back();
			i--;
		}
	}
	int bin(ll k){
		int l = 0;
		int r = line.size() - 1;
		while(l < r){
			int m = l + r >> 1;
			if (k < inter(m, m+1)) r = m;
			else l = m + 1;
		}
		return r;
	}
	ll get(ll k){
		if(isInc){
			if(line.empty()) return inf; //assert
			while(line.size() > 1 && calc(0, k) > calc(1, k)){
				line.pop_front();
			}
			return calc(0, k);
		}
		if(line.empty()) return inf; //assert
		if(line.size() == 1) return calc(0, k);
		return calc(bin(k), k);
	}
} cht;

ll s[202020];
ll a[202020];
ll b[202020];
int n;

int main()
{
    fastio;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s[i]; s[i] = -s[i];
		a[i] = a[i-1] + s[i];
		b[i] = b[i-1] + a[i];
	}

	ll ans = min(0ll, s[1]);

	cht = CHT(false);
	cht.insert(-1, 0);

	for(int i=2; i<=n; i++){
		ll now = cht.get(a[i]) + a[i] * (i+1) - b[i-1];
		if (ans > s[i]) ans = s[i];
		if (ans > now) ans = now;
		cht.insert(-i, b[i-2]);
	}
	cout << -ans;
	  
	return 0;
}


