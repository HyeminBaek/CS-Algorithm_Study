#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
struct rotateOp {
	int r, c, s;

};
rotateOp op[6];
pii dir[4] = { pii(0,1),pii(1,0),pii(0,-1),pii(-1,0) };
int N, M, K,A[50][50],r,c,s,ans;
void rotate(int r, int c, int s, int d);
void search(int bit);

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	ans = (1 << 30);

	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &op[i].r, &op[i].c, &op[i].s);
		op[i].r--;
		op[i].c--;
	}
	search(0);
	printf("%d\n", ans);

	return 0;
}

void search(int bit) {
	if (bit == (1 << K) - 1) {
		int minsum = (1 << 30);
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += A[i][j];
			}
			minsum = min(sum, minsum);
		}
		ans = min(ans, minsum);

	}
	else {

		for (int i = 0; i < K; i++) {
			int nbit = bit | (1 << i);
			if (nbit != bit) {
				//회전
				rotate(op[i].r, op[i].c, op[i].s, 1);
				search(nbit);
				//역회전
				rotate(op[i].r, op[i].c, op[i].s, -1);

			}
		}


	}
}
void rotate(int r, int c, int s, int d) {
	int temp[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = A[i][j];
		}
	}


	for (int i = 0; i <=s; i++) {
		int nr = r - i;
		int nc = c - i;
		int nd = 0 + (d == -1);
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < i * 2; k++) {
				int nnr = nr + dir[nd].first;
				int nnc = nc + dir[nd].second;
				temp[nnr][nnc] = A[nr][nc];
				nr = nnr;
				nc = nnc;
			}

			nd = (4 + nd + d) % 4;
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			A[i][j] = temp[i][j];
		}
	}

}