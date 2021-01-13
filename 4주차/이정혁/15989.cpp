#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc, maximum;
int dp[10001][4];
vector<int> v;

void init() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		v.emplace_back(n);
		maximum = max(maximum, n);
	}
}

void plus_123(int val){
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

	for (int i = 4; i <= val; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i - j][k];
			}
		}
	}
	return;
}
/* // 초기화 해주며 재귀 돌면서 dp 한다고 했는데, 잘 되지 않음,,
int plus_123(int idx, int value, int x) {
	if (value == v[x]) {
		return 1;
	}
	if (idx >= 3) {
		return 0;
	}
	if (dp[value][idx] != -1) {
		return dp[value][idx];
	}

	dp[value][idx] = 0;

	for (int i = 0; i <= ((v[x] - value) / num[idx]); i++) {
		if (value + (i * num[idx]) <= v[x]) {
			dp[value][idx] += plus_123(idx + 1, value + (i * num[idx]), x);
		}
	}
	return dp[value][idx];
}
*/
int main(void) {
	init();
	/*
	for (int i = 0; i < tc; i++) {
		result.emplace_back(plus_123(0, 0, i));
	}
	for (int i = 0; i < tc; i++) {
		cout << result[i] << '\n';
	}
	*/
	plus_123(maximum);
	for (int i = 0; i < tc; i++) {
		int result = dp[v[i]][1] + dp[v[i]][2] + dp[v[i]][3];
		cout << result << '\n';
	}
	return 0;
}
