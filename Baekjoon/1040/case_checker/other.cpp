#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#pragma warning(disable:4996)
#define nINF -1000000000
#define INF 1000000000

using namespace std;

void loop(int num[10], int dif,long long w,int pos) {
	if (pos == -1 && dif == 0) {
		cout << w;
		exit(0);
	}
	else if (pos == -1)return;
	else {
		if (dif != 0) {
			for (int i = 0; i <= 9; i++) {
				if (num[i] == 0) {
					num[i]++;
					long long tmul = 1;
					for (int j = 0; j < pos; j++) {
						tmul *= 10;
					}
					loop(num, dif-1, w + i * tmul, pos - 1);
					num[i]--;
				}
			}
		}
		else {
			for (int i = 0; i <= 9; i++) {
				if (num[i] != 0) {
					num[i]++;
					long long tmul = 1;
					for (int j = 0; j < pos; j++) {
						tmul *= 10;
					}
					loop(num, dif, w + i * tmul, pos - 1);
					num[i]--;
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long w, k, w2, size = 0, dif = 0;
	int wnum[20] = {};
	int num[10] = {};
	cin >> w >> k;
	w2 = w;
	while (w2) {
		if (num[w2 % 10] == 0)dif++;
		num[w2 % 10]++;
		wnum[size++] = w2 % 10;
		w2 /= 10;
	}
	w2 = w;
	if (dif == k) {
		cout << w2;
		return 0;
	}
	for (int i = 0; i < size; i++) {
		long long tmul = 1;
		for (int j = 0; j < i; j++) {
			tmul *= 10;
		}
		if (i < size) {
			w2 -= wnum[i] * tmul;
			num[wnum[i]]--;
			if (num[wnum[i]] == 0)dif--;
		}
		for (int j = wnum[i] + 1; j <= 9; j++) {
			w2 += j * tmul;
			if (num[j] == 0)dif++;
			num[j]++;
			if (dif <= k && dif + i >= k)loop(num, k - dif, w2, i - 1);
			num[j]--;
			if (num[j] == 0)dif--;
			w2 -= j * tmul;
		}
	}
	cout << 10;
	for (long long i = 0; i <= size - k; i++)cout << 0;
	for (long long i = 2; i < k; i++)cout << i;
}
