#include <cstring>
#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

// 1. root - leaf
// 2. leaf - leaf

// 모든 노드를 돌면서 제일 긴 depth를 찾고,
// 그 루트 노드로부터 다음 긴 depth의 leaf 노드를 찾는다
int n, ans;
vector<pii> tree[10001];  // to, weight;
int dist[10001];
bool check[10001];

void dfs(int u) {  // u -> v;
    int fi = -1, se = -1;
    for (pii node : tree[u]) {
        int to = node.first, w = node.second;
        if (!check[to]) dfs(to);

        int tmp = dist[to] + w;
        dist[u] = max(dist[u], tmp);

        if (fi < tmp) {
            se = fi;
            fi = tmp;
        } else if (se < tmp) {
            se = tmp;
        }
    }

    if (se != -1) {
        ans = max(ans, fi + se);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
    }

    dfs(1);                         // 1~n 탐색
    for (int i = 1; i <= n; ++i) {  // root-leaf가 지름인 경우
        ans = max(ans, dist[i]);
    }
    cout << ans;

    return 0;
}
