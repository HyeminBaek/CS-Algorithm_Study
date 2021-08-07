#include<iostream>
#include<vector>

using namespace std;

vector<int> node[100001];
int result[100001];
int N, R, Q;
vector<int> Query;
bool visited[100001];
void init() {
	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].emplace_back(b);
		node[b].emplace_back(a);
	}
	for (int i = 0; i < Q; i++) {
		int n;
		cin >> n;
		Query.emplace_back(n);
	}
}

void dfs(int n) {
	result[n]++;
	for (int i = 0; i < node[n].size(); i++) {
		if (!visited[node[n][i]]) {
			visited[node[n][i]] = true;
			dfs(node[n][i]);
			result[n] += result[node[n][i]];
			visited[node[n][i]] = false;
		}
	}
}
int main(void) {
	init();
	visited[R] = true;
	dfs(R);
	for (int i = 0; i < Q; i++) {
		cout << result[Query[i]] << '\n';
	}
	return 0;
}
