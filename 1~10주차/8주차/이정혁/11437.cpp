#include<iostream>
#include<vector>

using namespace std;
/*
해당 노드의 깊이와 부모를 저장하는 배열을 생성
*/
vector<int> load[100001];
int N, K;
vector<pair<int, int>> v;
int depth[100001];
int parent[100001];
bool visited[100001];

void init() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		load[a].emplace_back(b);
		load[b].emplace_back(a);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
}

void dfs(int x, int cdepth ) {
	depth[x] = cdepth; // x의 깊이는 현재 깊이인 cdepth이다.
	for (int i = 0; i < load[x].size(); i++) {
		if (!depth[load[x][i]]) {
			parent[load[x][i]] = x; //load[x][i]의 부모는 x 이다.
			dfs(load[x][i], cdepth + 1);
		}
	}
}

int main(void) {
	init();
	dfs(1, 1);

	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].first;
		int node2 = v[i].second;
		if (depth[node1] > depth[node2]) { // node1의 깊이가 node2 깊이가 더 크다면
			while (depth[node1] != depth[node2]) { //  node1의 부모와 node2가 깊이가 같아 질때 까지
				node1 = parent[node1]; // 거슬러 올라감
			}
			while (node1 != node2) { // node1과 node2에 같은 부모를 담을 때 까지
				node1 = parent[node1]; // node1과 node2를 같이 갱신해서 올라가줌
				node2 = parent[node2];
			}
		}
		else { // node2가 node1 보다 깊게 있다면
			while (depth[node1] != depth[node2]) { //node2를 올라가면서 node1의 높이에 맞춤
				node2 = parent[node2];
			}
			while (node1 != node2) {
				node1 = parent[node1];
				node2 = parent[node2];
			}
		}
		cout << node1 << '\n';
	}
	return 0;
}
