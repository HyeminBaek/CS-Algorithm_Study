#include<iostream>
#include<queue>
#include<utility>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;
int N, L, R,A[50][50],visit[50][50];
pii d[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
queue<pii> q[2];
int main() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
			visit[i][j] = -1;
		}
	}
	
	int ct = 0;
	while (1) {
		bool f = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] != ct) {
					int sum = 0;
					visit[i][j] = ct;
					q[0].push(pii(i, j));
					while (!q[0].empty()) {
						pii t = q[0].front();				
						q[0].pop();
						sum += A[t.first][t.second];
						q[1].push(t);
						for (int k = 0; k < 4; k++) {
							int nr = t.first + d[k].first;
							int nc = t.second + d[k].second;
							if (nr >= 0 && nr < N && nc >= 0 && nc < N ) {
								int dif = abs(A[t.first][t.second] - A[nr][nc]);
								if (visit[nr][nc] != ct && dif >= L && dif <= R) {
									visit[nr][nc] = ct;
									q[0].push(pii(nr, nc));
								}
							}
						}

					}
					int d = q[1].size();
					f |= (d >= 2);
					while (!q[1].empty()) {
						pii t = q[1].front();
						q[1].pop();
						A[t.first][t.second] = sum / d;
					}


				}
			}
		}


		

		if (!f) {
			break;
		}
		ct++;
	}
	printf("%d\n", ct);
	return 0;
}