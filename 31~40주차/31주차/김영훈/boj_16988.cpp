#include<iostream>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M,map[20][20],visit[20][20],ct;
pii dir[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
int Search(pii p1, pii p2) {
	int ret = 0;
	if (map[p1 .first][p1.second] != 0 || map[p2.first][p2.second] != 0) return 0;
	ct++;
	map[p1.first][p1.second] = 1;
	map[p2.first][p2.second] = 1;
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int sz = 0;
			bool flag;
			if (visit[i][j] != ct && map[i][j]==2) {
				visit[i][j] = ct;
				sz = 0;
				q.push(pii(i, j));
				flag = true;
				while (!q.empty()) {
					pii t = q.front();
					sz++;
					q.pop();
					for (int d = 0; d < 4; d++) {
						int nr = t.first + dir[d].first;
						int nc = t.second + dir[d].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
						if (visit[nr][nc] == ct || map[nr][nc] == 1) continue;
						if (map[nr][nc] == 0) {
							flag = false;
							continue;
						}
						visit[nr][nc] = ct;
						q.push(pii(nr, nc));
					}
				}
				if (!flag) {
					sz = 0;
				}
				ret += sz;

			}
		}
	}

	map[p1.first][p1.second] = 0;
	map[p2.first][p2.second] = 0;
	return ret;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = -1;
		}
	}
	ct = 0;
	int ans = 0;
	for (int i = 0; i < N * M; i++) {
		for (int j = i + 1; j < N * M; j++) {
			ans = max(Search({ i / M,i % M }, { j / M,j % M }), ans);
		}
	}
	printf("%d", ans);
	return 0;
}
