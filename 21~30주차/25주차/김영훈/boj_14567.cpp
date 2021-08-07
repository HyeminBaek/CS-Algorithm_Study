#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M,pre[1000],A,B,visit[1000];
vector<int> adjlist[1000];
void Init();
void BFS();
int main() {
	scanf("%d%d", &N, &M);
	Init();
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A, &B);
		adjlist[A - 1].push_back(B - 1);
		pre[B - 1]++;
	}
	BFS();
	for (int i = 0; i < N; i++) {
		printf("%d ", visit[i]);
	}
	printf("\n");
	return 0;
}
void Init() {
	for (int i = 0; i < N; i++) {
		pre[i] = 0;
		visit[i] = -1;
		adjlist[i].clear();
	}

}
void BFS() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (pre[i] == 0) {
			q.push(i);
			visit[i] = 1;
		}		
	}
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < adjlist[t].size(); i++) {
			int next = adjlist[t][i];
			pre[next]--;
			if (pre[next] == 0) {
				q.push(next);
				visit[next] = visit[t] + 1;
			}
		}
	}
}