#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
string board[500];
int dp[500][500];

int go(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) return 1;
    if (dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 0;

    if (board[r][c] == 'U')
        return dp[r][c] = go(r - 1, c);
    else if (board[r][c] == 'D')
        return dp[r][c] = go(r + 1, c);
    else if (board[r][c] == 'L')
        return dp[r][c] = go(r, c - 1);
    else
        return dp[r][c] = go(r, c + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += go(i, j);
        }
    }

    cout << ans;
    return 0;
}
