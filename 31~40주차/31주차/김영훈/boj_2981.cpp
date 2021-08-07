#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, arr[100];
int GCD(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int k = arr[1] - arr[0];
	k = k < 0 ? -k : k;
	for (int i = 2; i < N; i++) {
		int d = arr[i] - arr[i - 1];
		d = d < 0 ? -d : d;
		k = GCD(k, d);
	}
	int t = 2;
	vector<int> ans;
	ans.push_back(k);
	while (t * t <= k) {
		if (k % t == 0) {
			ans.push_back(t);
			if (t * t != k) {
				ans.push_back(k / t);
			}
		}
		t++;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}