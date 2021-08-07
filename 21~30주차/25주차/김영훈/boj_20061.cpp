#include<iostream>
#include<algorithm>
using namespace std;
int N, t, x, y,block[2][7][4],score,blocknum[2][6];
void Init();
void AddBlock(int t,int c,int color);
void DownBlock(int color,int r, int num);
void CheckScore(int color);

int main() {
	Init();
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d%d", &t, &x, &y);
		AddBlock(t, y, 0);
		AddBlock(t+(t==2)-(t==3), x, 1);
	}
	int n = 0;
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			n += block[0][i][j]+block[1][i][j];
			
		}
	}
	printf("%d\n%d\n", score, n);
	return 0;
}

void Init() {
	for (int i = 0; i < 6; i++) {
		blocknum[0][i] = 0;
		blocknum[1][i] = 0;
		for (int j = 0; j < 4; j++) {
			block[0][i][j] = 0;
			block[1][i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		block[0][6][i] = 1;
		block[1][6][i] = 1;
	}
	score = 0;
}
void AddBlock(int t, int c,int color) {
	switch (t) {
	case 1:
		for (int i = 2; i<=6; i++) {
			if (block[color][i][c] == 1) {
				block[color][i-1][c] = 1;
				blocknum[color][i - 1]+=1;
				break;
			}
		}
		break;
	case 2:
		for (int i = 2; i <=6; i++) {
			if (block[color][i][c] == 1 || block[color][i][c + 1] == 1) {
				block[color][i-1][c + 1] = 1;
				block[color][i-1][c] = 1;
				blocknum[color][i - 1] += 2;
				break;
			}
		}
		break;
	case 3:
		for (int i = 2; i <= 6; i++) {
			if (block[color][i][c] == 1) {
				block[color][i - 1][c] = 1;
				block[color][i - 2][c] = 1;
				blocknum[color][i - 1]+=1;
				blocknum[color][i - 2] += 1;
				break;
			}
		}
		break;
	}
	CheckScore(color);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[color][i][j] == 1) {
				DownBlock(color,5, 2 - i);
				break;
			}
		}
	}
	
}
void DownBlock(int color,int r,int num) {
	for (int i = r; i >= num; i--) {
		for (int j = 0; j < 4; j++) {
			block[color][i][j] = block[color][i - num][j];
			block[color][i - num][j] = 0;
			
		}
		blocknum[color][i] = blocknum[color][i - num];
		blocknum[color][i - num] = 0;
	}

}
void CheckScore(int color) {
	for (int i = 2; i<=5; i++) {
		if (blocknum[color][i] == 4) {
			DownBlock(color, i, 1);
			score++;
		}
	}
}