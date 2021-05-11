#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int t, n, m, ans = 1;  // 정점10, 간선20
int g[11][11];
bool visited[11];

void dfs(int curr, int len) {
    visited[curr] = true;
    if (ans < len) ans = len;
    for (int i = 1; i <= n; ++i) {
        if (g[curr][i] && !visited[i]) dfs(i, len + 1);
    }
    visited[curr] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; ++i) {
        ans = 1;
        memset(g, 0, sizeof(g));
        cin >> n >> m;

        for (int j = 0; j < m; ++j) {
            int u, v;
            cin >> u >> v;
            g[u][v] = 1;
            g[v][u] = 1;
        }

        for (int j = 1; j <= n; ++i) {
            // dfs(j, 1);  // 모든 노드에서 최장경로 찾기, 최소 1개
        }

        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}
