#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int R, C, T, A[50][50];
vector<int*> flow[2];
pii d[4] = { pii(0,1),pii(-1,0),pii(0,-1),pii(1,0) };
int main() {
	scanf("%d%d%d", &R, &C, &T);
	int t = 0;
	int t2 = 1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == -1) {
				int r = i;
				int c = j;
				int nr, nc;
				for (int k = 0; k < 4; k++) {
					while (1) {
						nr = r + d[(4 + t2 * k) % 4].first;
						nc = c + d[(4 + t2 * k) % 4].second;
						if (nr < 0 || nr >= R || nc < 0 || nc >= C || A[nr][nc] == -1) break;
						flow[t].push_back(&A[nr][nc]);
						r = nr;
						c = nc;
					}

				}
				t2 *= -1;
				t++;
			}
		}
	}
	while (T--) {
		int temp[50][50];
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				temp[i][j] = 0;
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				if (A[i][j] > 0) {
					int ct = 0;
					for (int k = 0; k < 4; k++) {
						int nr = i + d[k].first;
						int nc = j + d[k].second;
						if (nr < 0 || nr >= R || nc < 0 || nc >= C || A[nr][nc] == -1) continue;
						temp[nr][nc] += A[i][j] / 5;
						ct++;
					}
					temp[i][j] -= (A[i][j] / 5) * ct;
				}

			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				A[i][j] += temp[i][j];
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = flow[i].size() - 1; j > 0; j--) {
				*flow[i][j] = *flow[i][j - 1];
			}
			*flow[i][0] = 0;
		}
	}
	int answer = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (A[i][j] > 0) {
				answer += A[i][j];
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}
