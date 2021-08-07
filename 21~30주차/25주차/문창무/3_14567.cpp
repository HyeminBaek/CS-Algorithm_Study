#include <iostream>
#include <vector>
using namespace std;

int n, m;  // 과목수1000, 선수조건500000 1000*1000
vector<int> parent[1001];
int dp[1001];

int calc(int i) {
    if (dp[i]) return dp[i];
    for (int n : parent[i]) {
        dp[i] = max(dp[i], calc(n));
    }

    return ++dp[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        parent[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        cout << calc(i) << ' ';
    }

    return 0;
}
