#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
int v[500010], tmp[500010];

void merge(int p, int q, int r){
	int idx = p;
	int i = p, j = q+1;
	int cnt = 0;
	while(i<=q | j<=r){
		if(i > q){
			tmp[idx++] = v[j++]; cnt++;
		}else if(j > r){
			tmp[idx++] = v[i++]; ans += (long long)cnt;
		}else if(v[i] <= v[j]){
			tmp[idx++] = v[i++]; ans += (long long)cnt;
		}else{
			tmp[idx++] = v[j++]; cnt++;
		}
	}
	for(i=p; i<=r; i++) v[i] = tmp[i];
}

void mergeSort(int p, int r){
	int q;
	if(p < r){
		q = (p+r)/2;
		mergeSort(p, q);
		mergeSort(q+1, r);
		merge(p, q, r);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	mergeSort(0, n-1);
	cout << ans;
}
