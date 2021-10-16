#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* 문제 요구사항: 그래프가 이분 그래프인지 아닌지 판별
* 제한 사항:
* 1. 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는
	 서로 인접하지 않도록 분할할 수 있다.
*/

bool bfs(int i, int visited[], vector<int> g[]) {
	queue<int> q; q.push(i);
	visited[i] = 0;

	while (!q.empty()) {
		int x = q.front(); q.pop();

		for (int k = 0; k < g[x].size(); k++) {
			int nx = g[x][k];

			//not visited
			if (visited[nx] == -1) {
				visited[nx] = (visited[x] == 0) ? 1 : 0;
				q.push(nx);
			}
			else if (visited[x] == visited[nx]) {
				return false;
			}
		}
	}
	return true;
}
void init(int& V, vector<int> g[20001]) {
	int E; cin >> V >> E;

	while (E-- > 0) {
		int u, v; cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
}
void solution() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K; cin >> K;

	while (K-- > 0) {
		int V; vector<int> g[20001];
		init(V, g);

		//@visited status: -1 not visited	0 group A	1 group B 
		int* visited = new int[V + 1]; //memset(visited, -1, sizeof(visited));

		for (int i = 1; i <= V; i++) visited[i] = -1;

		bool ans = true;
		for (int i = 1; i <= V; i++) {
			if (visited[i] == -1) {
				bool result = bfs(i, visited, g);

				if (!result) {
					ans = false; break;
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}
int main() {
	solution();

	return 0;
}