#include<iostream>
using namespace std;
int T, N, K, input, dp[21][1001];
int main() {
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < N; i++) {
            scanf("%d", &input);
            for (int j = 0; j <= K; j++) {
                dp[i + 1][j] += dp[i][j];
                if (j + input <= K) {
                    dp[i + 1][j + input] += dp[i][j];

                }



            }
        }

        printf("#%d %d\n", tc, dp[N][K]);
    }
    return 0;
}