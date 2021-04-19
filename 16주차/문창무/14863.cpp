#include <algorithm>
#include <iostream>
using namespace std;

// 시간내 모금 가능한 최대 금액 찾기
int n, k;  // 거쳐 갈 도시의 갯수100, 시간100000
int dp[100][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int walkTime, walk, bikeTime, bike;  // 도보시간, 도보모금액, 자전거시간, 자전거모금액
        cin >> walkTime >> walk >> bikeTime >> bike;
        if (i == 0) {
            dp[i][walkTime] = walk;
            dp[i][bikeTime] = max(dp[i][bikeTime], bike);
        } else {
            for (int j = 0; j <= k; ++j) {
                if (dp[i - 1][j] == 0) continue;
                if (j + walkTime <= k) dp[i][j + walkTime] = max(dp[i][j + walkTime], dp[i - 1][j] + walk);
                if (j + bikeTime <= k) dp[i][j + bikeTime] = max(dp[i][j + bikeTime], dp[i - 1][j] + bike);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = max(dp[n - 1][i], ans);
    }

    cout << ans;
    return 0;
}
