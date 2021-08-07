#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = (1 << 30);
struct Path {
	int bit;
	int dest;
	Path(int bit, int dest) {
		this->bit = bit;
		this->dest = dest;
	}
};
int N, cost[16][16],visit[(1<<15)][15]; //2^15 = 32768

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}
	for (int i = 0; i < (1 << (N-1)); i++) {
		for (int j = 0; j < N-1; j++) {
			visit[i][j] = INF;
		}
	}
	queue<Path> q;
	int ans = INF;
	//N-1번 정점에서 시작
	for (int i = 0; i < N-1; i++) {
		visit[(1<<i)][i] = cost[N-1][i];
		q.push(Path((1<<i), i));
	}
	while (!q.empty()) {
		Path t = q.front();
		q.pop();
		for (int i = 0; i < N-1; i++) {
			if (cost[t.dest][i] == 0 || (t.bit & (1 << i)) != 0) continue;
			int ncost = visit[t.bit][t.dest] + cost[t.dest][i];
			int nbit = (t.bit | (1 << i));
			if (visit[nbit][i] > ncost) {
				visit[nbit][i] = ncost;
				q.push(Path(nbit, i));
			}


		}
	}
	for (int d = 0; d < N-1; d++) {
		if (cost[d][N-1] == 0) continue;
		ans = min(ans, visit[(1 << (N-1)) - 1][d] + cost[d][N-1]);
	}

	printf("%d\n", ans);
	return 0;
}