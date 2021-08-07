#include<iostream>
#include<algorithm>
using namespace std;
const int INF = (1<<31)-1;
int N,r[500], c[500], dp[500][500];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &r[i], &c[i]);
		dp[i][i] = 0;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) {
			dp[j][j + i - 1] = INF;
			for (int k = j; k < j + i - 1; k++) {
				dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + r[j] * c[k] * c[j+i-1]);
			}
		}
	}
	printf("%d\n", dp[0][N - 1]);
	return 0;
}