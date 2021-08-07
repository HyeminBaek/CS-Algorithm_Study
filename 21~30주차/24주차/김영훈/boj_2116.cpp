#include<iostream>

using namespace std;
int N,dice[10000][6],side[6][4],top[6];
void Init();
int GetMaxSideVal(int idx, int botidx);
int GetIdx(int idx, int val);
int main() {
	Init();
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%d", &dice[i][j]);
		}
	}
	int answer = 0;
	for (int i = 0; i < 6; i++) {
		int score = GetMaxSideVal(0,i);
		int topnum = dice[0][top[i]];
		for (int j = 1; j < N; j++) {
			int botidx = GetIdx(j, topnum);
			score += GetMaxSideVal(j, botidx);
			topnum = dice[j][top[botidx]];
		}
		answer = answer < score ? score : answer;
	}
	printf("%d\n", answer);
	return 0;
}
void Init() {
	for (int i = 0; i < 4; i++) {
		side[0][i] = i + 1;
		side[5][i] = i + 1;
	}
	top[0] = 5;
	top[5] = 0;
	for (int i = 1; i <= 4; i++) {
		side[i][0] = 0;
		side[i][1] = 5;
		side[i][2] = i % 4 + 1;
		side[i][3] = ((i + 2) % 4) + 1;
		top[i] = ((i + 1) % 4) + 1;
	}
}
int GetMaxSideVal(int idx, int botidx){
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int sideidx = side[botidx][i];
		ret = ret < dice[idx][sideidx] ? dice[idx][sideidx] : ret;
	}
	return ret;
}
int GetIdx(int idx, int val) {
	for (int i = 0; i < 5; i++) {
		if (dice[idx][i] == val) {
			return i;
		}
	}
	return 5;
}