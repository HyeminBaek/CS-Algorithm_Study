#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, M, map[300][300], adj[300][300],visit[300][300];
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
int isSplit(int time) {
	int ret = 0;
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] != time && map[i][j]>0) {
				visit[i][j] = time;
				ret++;
				q.push(pii(i, j));
				while (!q.empty()) {
					pii t = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nr = t.first + dir[k].first;
						int nc = t.second + dir[k].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
						if (visit[nr][nc] == time || map[nr][nc] == 0) continue;
						visit[nr][nc] = time;
						q.push(pii(nr, nc));

					}
				}
			}
		}
	}
	return ret;
}
void Unfreeze() {
	int temp[300][300];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(map[i][j]>0){
				map[i][j] = map[i][j] - adj[i][j];
				if (map[i][j] <= 0) {
					map[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int nr = i + dir[k].first;
						int nc = j + dir[k].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
						
						temp[nr][nc]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			adj[i][j] += temp[i][j];
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			adj[i][j] = 0;
			visit[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int nr = i + dir[k].first;
					int nc = j + dir[k].second;
					if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
					if (map[nr][nc] == 0) {
						adj[i][j]++;
					}
				}
			}
		}
	}

	for (int i = 1; ; i++) {
		
		Unfreeze();
		int r = isSplit(i);
		if (r == 0) {
			printf("0\n");
			break;
		}
		else if (r > 1) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}