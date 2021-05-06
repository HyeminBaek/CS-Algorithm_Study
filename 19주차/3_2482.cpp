#include <iostream>
using namespace std;

const int mod = 1000000003;

int dp[1001][1001];
int n, k;  // 4~1000, 1~1000

int main() {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        dp[i][1] = i;
        dp[i][0] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % mod;
            // i번째 칸을 칠하는 경우 + 안 칠하는 경우
        }
    }

    cout << (dp[n - 1][k] + dp[n - 3][k - 1]) % mod;
    return 0;
}
