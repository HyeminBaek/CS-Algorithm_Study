#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int n,m,map[50][50],sz[50][50],rn[50][50];
bool visit[50][50];
pii d[4] = { pii(0,-1),pii(-1,0),pii(0,1),pii(1,0) };
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = false;
			sz[i][j] = 0;
		}
	}
	int answer1 = 0;
	int answer2 = 0;
	int answer3 = 0;
	queue<pii> q,q2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				answer1++;
				q.push(pii(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					pii t = q.front();
					rn[t.first][t.second] = answer1;
					q2.push(t);
					q.pop();				
					for (int k = 0; k < 4; k++) {
						if ((map[t.first][t.second] & (1 << k)) == 0) {
							int nr = t.first + d[k].first;
							int nc = t.second + d[k].second;
							if (nr < 0 || nr >= m || nc < 0 || nc >= n || visit[nr][nc]) continue;
							visit[nr][nc] = true;
							q.push(pii(nr, nc));
						}
					}
				}
				int nsz = q2.size();
				answer2 = answer2 < nsz ? nsz : answer2;
				while (!q2.empty()) {
					pii t = q2.front();
					q2.pop();
					sz[t.first][t.second] = nsz;
				}

			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			for (int k = 0; k < 4; k++) {
				
				if ((map[i][j] & (1 << k)) != 0) {
					int nr = i + d[k].first;
					int nc = j + d[k].second;
					if (nr < 0 || nr >= m || nc < 0 || nc >= n || rn[i][j]==rn[nr][nc]) continue;
					int msz = sz[i][j] + sz[nr][nc];
					answer3 = answer3 < msz ? msz : answer3;
				}
			}
		}
		
	}
	printf("%d\n%d\n%d\n", answer1, answer2, answer3);
	return 0;
}