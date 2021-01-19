#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<pair<int,int>> tree[10001];
int n, start, result;
bool visited[10001];
void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		tree[a].push_back({ b,len });
		tree[b].push_back({ a,len });
	}
}
void dfs(int x, int len) {
	if (len > result) {
		start = x;
		result = len;
	}
	for (int i = 0; i < tree[x].size(); i++) {
		if (!visited[tree[x][i].first]) {
			visited[tree[x][i].first] = true;
			dfs(tree[x][i].first, len + tree[x][i].second);
			visited[tree[x][i].first] = false;
		}
	}
}
int main(void) {
	init();
	visited[1] = true;
	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	visited[start] = true;
	dfs(start, 0);
	cout << result;
	return 0;
}
