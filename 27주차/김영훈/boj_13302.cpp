#include<iostream>
#include<algorithm>
using namespace std;
const int INF = (1 << 30);
int N, M,a,dp[101][41];
bool visit[101];
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		visit[i] = true;
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 41; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		visit[a] = false;
	}
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		if (!visit[i+1]) {
			for (int j = 0; j < 41; j++) {
				if (dp[i][j] == INF) continue;
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
		}
		else {
			for (int j = 0; j < 41; j++) {
				if (dp[i][j] == INF) continue;
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 10000);
				if (j >= 3) {
					dp[i + 1][j - 3] = min(dp[i + 1][j - 3], dp[i][j]);
				}
				int day = min(N, i + 3);
				dp[day][j + 1] = min(dp[day][j + 1], dp[i][j] + 25000);
				day = min(N, i + 5);
				dp[day][j + 2] = min(dp[day][j + 2], dp[i][j] + 37000);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < 41; i++) {
		ans = min(ans, dp[N][i]);
	}
	printf("%d\n", ans);
	return 0;
}