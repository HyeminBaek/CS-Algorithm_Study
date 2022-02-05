#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int N, K, s, e;
ll H[200000], minHeight[200000];
bool visit[200000];
vector<int> adjList[200000];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
		visit[i] = false;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> s >> e;
		adjList[s - 1].push_back(e - 1);
		adjList[e - 1].push_back(s - 1);
	}
	minHeight[K - 1] = H[K - 1];
	q.push(K - 1);
	visit[K - 1] = true;
	bool isPossible = false;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (minHeight[now] > 1000000) continue;
		for (int i = 0; i < adjList[now].size(); i++) {
			int next = adjList[now][i];
			if (visit[next]) continue;

			isPossible |= minHeight[now] <= H[next];

			minHeight[next] = max(H[next], 2 * minHeight[now] - H[next]);

			visit[next] = true;
			q.push(next);
		}
	}
	cout << (isPossible ? 1 : 0) << "\n";
	return 0;
}