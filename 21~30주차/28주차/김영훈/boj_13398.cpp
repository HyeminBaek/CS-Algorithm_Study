#include<iostream>
#include<algorithm>
using namespace std;
const int INF = (1 << 30);
int dp[2][2],n,k;
int main() {
	scanf("%d", &n);
	dp[1][0] = -INF;
	dp[1][1] = -INF;
	int ans = -INF;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		dp[(i % 2)][0] = max(k, dp[1 - (i % 2)][0] + k);
		dp[(i % 2)][1] = max(dp[1 - (i % 2)][0], dp[1 - (i % 2)][1] + k);
		ans = max(ans, dp[i % 2][0]);
		ans = max(ans, dp[i % 2][1]);
	}
	printf("%d\n", ans);
	return 0;
}