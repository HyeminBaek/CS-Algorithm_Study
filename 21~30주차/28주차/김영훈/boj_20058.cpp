#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, Q, A[1 << 6][1 << 6], L, temp[1 << 6][1 << 6];
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
void FireStorm(int sz);
void Rotate(int r, int c, int sz);
void Melt();
int SearchLargest();
int main() {
	scanf("%d%d", &N, &Q);
	N = (1 << N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &L);
		FireStorm((1<<L));
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += A[i][j];
	
		}
		
	}
	printf("%d\n%d\n", ans,SearchLargest());
	return 0;
}
void FireStorm(int sz) {
	for (int i = 0; i < N; i += sz) {
		for (int j = 0; j < N; j += sz) {
			Rotate(i, j, sz);
		}
	}
	
	Melt();

}
void Rotate(int r, int c, int sz) {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			temp[j][sz-i-1]=A[r+i][c+j];
		}
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			A[r + i][c + j] = temp[i][j];
		}
	}
}
void Melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) {
				temp[i][j] = A[i][j]; 
				continue;
			}
			int ct = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dir[k].first;
				int nc = j + dir[k].second;
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				ct += (A[nr][nc] > 0);
			}
			temp[i][j] = A[i][j] - (ct < 3);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = temp[i][j];
		}
	}
}
int SearchLargest() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
		}
	}
	queue<pii> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp[i][j] == 1 || A[i][j] == 0) continue;
			q.push(pii(i, j));
			temp[i][j] = 1;
			int ct = 0;
			while (!q.empty()) {
				pii t = q.front();
				q.pop();
				ct++;
				for (int k = 0; k < 4; k++) {
					int nr = t.first + dir[k].first;
					int nc = t.second + dir[k].second;
					if (nr < 0 || nr >= N || nc < 0 || nc >= N || A[nr][nc] == 0 || temp[nr][nc] == 1) continue;
					temp[nr][nc] = 1;
					q.push(pii(nr, nc));
				}
			}
			ret = ret < ct ? ct : ret;

		}
	}

	return ret;
}