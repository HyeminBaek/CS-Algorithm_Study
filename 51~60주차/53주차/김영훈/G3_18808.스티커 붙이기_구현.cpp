#include<iostream>
using namespace std;
struct Sticker {
	int r, c, arr[10][10];
	Sticker(int r, int c) {
		this->r = r;
		this->c = c;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				arr[i][j] = 0;
			}
		}
	}
};
int N, M, K, R, C, notebook[40][40];

bool isValidPos(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

bool isStick(int r, int c, const Sticker& sticker) {

	for (int i = 0; i < sticker.r; i++) {
		for (int j = 0; j < sticker.c; j++) {
			int nr = r + i;
			int nc = c + j;
			if (!isValidPos(nr, nc) || notebook[nr][nc]*sticker.arr[i][j]!=0) return false;
		}
	}
	for (int i = 0; i < sticker.r; i++) {
		for (int j = 0; j < sticker.c; j++) {
			int nr = r + i;
			int nc = c + j;
			notebook[nr][nc] += sticker.arr[i][j];
		}
	}
	return true;
}

Sticker Rotate(const Sticker& sticker) {
	int pr = sticker.r;
	int pc = sticker.c;
	Sticker nSticker = Sticker(pc, pr);
	for (int r = 0; r <pr; r++) {
		for (int c = 0; c < pc; c++) {
			nSticker.arr[c][pr-1-r] = sticker.arr[r][c];
		}
	}
	
	
	return nSticker;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			notebook[r][c] = 0;
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> R >> C;
		Sticker sticker = Sticker(R, C);
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> sticker.arr[r][c];
			}
		}
		for (int j = 0; j < 4; j++) {
			bool flag = false;
			for (int p = 0; p < N * M; p++) {
				if (isStick(p / M, p % M,sticker)) {
					flag = true;
					break;
				}
			}
			if (flag) break;
			sticker=Rotate(sticker);
		}

	}
	int ans = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			ans += notebook[r][c];
		}
	}
	cout << ans << "\n";
	return 0;
}