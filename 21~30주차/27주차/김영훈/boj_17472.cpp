#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = (1 << 30);
int N, M,map[10][10],dist[6][6],landnum;
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
void InitNode();
void InitGraph();
int MST();
vector<pii> landpos[6];
struct CompDist {
	bool operator()(pii e1, pii e2) {
		return e1.second > e2.second;
	}
};
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			map[i][j] *= -1;
		}
	}
	InitNode();
	InitGraph();
	printf("%d\n", MST());
	return 0;
}
void InitNode() {
	queue<pii> q;
	landnum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == -1) {
				map[i][j] = ++landnum;
				q.push(pii(i, j));			
				while (!q.empty()) {
					pii t = q.front();
					landpos[landnum - 1].push_back(t);
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nr = t.first + dir[i].first;
						int nc = t.second + dir[i].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] != -1) continue;
						map[nr][nc] = landnum;
						q.push(pii(nr, nc));
					}
				}

			}
		}
	}
}

void InitGraph() {
	for (int i = 0; i < landnum; i++) {
		for (int j = 0; j < landnum; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 0; i < landnum; i++) {
		for (int j = 0; j < landpos[i].size(); j++) {
			
			for (int k = 0; k < 4; k++) {
				int ndist = 1;
				int nr = landpos[i][j].first + dir[k].first;
				int nc = landpos[i][j].second + dir[k].second;
				while (1) {
					if (nr < 0 || nr >= N || nc < 0 || nc >= M) break;
					if (map[nr][nc] > 0) {
						if (ndist >= 3) {
							int dest = map[nr][nc] - 1;
							dist[i][dest] = min(dist[i][dest], ndist);
							dist[dest][i] = min(dist[dest][i], ndist);
						}
						break;
					}
					nr += dir[k].first;
					nc += dir[k].second;
					ndist++;

				}
			}
		}
	}
}
int MST() {
	priority_queue<pii, vector<pii>, CompDist> pq;
	bool visit[6] = { false, };
	int ret = 0;
	pq.push(pii(0, 1));
	while (!pq.empty()) {
		pii t = pq.top();
		pq.pop();
		if (visit[t.first]) continue;
		visit[t.first] = true;
		ret += t.second-1;
		for (int i = 0; i < landnum; i++) {
			if (!visit[i] && dist[t.first][i]!=INF) {
				pq.push(pii(i, dist[t.first][i]));
			}
		}
	}
	for (int i = 0; i < landnum; i++) {
		if (!visit[i]) {
			return -1;
		}
	}

	return ret;
}

