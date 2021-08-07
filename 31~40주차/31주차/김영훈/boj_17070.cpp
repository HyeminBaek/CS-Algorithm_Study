#include<iostream>
using namespace std;
int N,map[16][16], dp[16][16][3];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
			dp[i][j][2] = 0;
		}
	}
	dp[0][1][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N && map[i][j+1]==0) {
				dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][1];
			}
			if (i + 1 < N && map[i+1][j]==0) {
				dp[i + 1][j][2] += dp[i][j][2] + dp[i][j][1];
			}
			if (j + 1 < N && i + 1 < N && (map[i+1][j+1]| map[i+1][j]|map[i][j+1])==0 ) {
				dp[i + 1][j + 1][1] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
			}
		}
	}
	printf("%d", dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2]);
	return 0;
}