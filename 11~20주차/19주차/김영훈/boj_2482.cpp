#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000003;
int N, K;
ll dp[1000][1001],answer;
int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = 0;
		}
	}

	dp[0][1] = 1;
	dp[1][1] = 1;
	
	for (int i = 2; i < N - 1; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
			dp[i][j] %= MOD;
		}
	}
	answer = dp[N-2][K];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < N; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
			dp[i][j] %= MOD;
		}
	}
	answer += dp[N - 1][K];
	
	printf("%lld\n", answer%MOD);
	return 0;
}