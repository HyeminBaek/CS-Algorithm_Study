// https://www.youtube.com/watch?v=cdPBs_EsHbc
// 외판원 문제
#include <cstring>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int n;
int a[16][16];       // i -> j cost
int d[1 << 16][16];  // i노드들을 거쳐서 j일때, 방문경로 비용의 최소값

int go(int visited, int u) {                                      // u에서 visited 빼고 다 방문해서 0으로 돌아가는 데 드는 최소비용
    if (visited == (1 << n) - 1) return a[u][0] ? a[u][0] : INF;  // 노드 모두 방문했으면 u에서 0으로 가는 비용 리턴
    if (d[visited][u]) return d[visited][u];                      //

    d[visited][u] = INF;
    for (int i = 0; i < n; ++i) {
        if (!a[u][i] || visited & (1 << i)) continue;  // i까지 길이 없거나 i에 방문했으면 스킵
        d[visited][u] = min(
            d[visited][u],
            a[u][i] + go(visited | (1 << i), i));  // 다음마을(i) 가는 비용 + i 제외하고 그전까지의 부분문제
    }
    // visited 1110 (i<<i) 1000. 1110|1000 = 0001
    return d[visited][u];  // visited를 거쳐 u에 도달한 최소비용을 리턴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // 그래프에 사이클이 존재하므로 0에서 출발하는거로 가정(tsp minimum path는 항상 같다)
    cout << go(1, 0);  // 방문한 노드: {0}: 1 << 0, 출발 1
    return 0;
}
