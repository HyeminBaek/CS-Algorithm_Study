#include<iostream>
using namespace std;
struct Info {
	int score;
	int reddir;
	int bluedir;
	int next[5];
	bool f=false;
};
void Init();
void Search(int idx);
Info map[40];
int input[10],score,npos[4],answer;

int main() {
	Init();
	for (int i = 0; i < 10; i++) {
		scanf("%d", &input[i]);
	}
	Search(0);
	printf("%d\n", answer);
	return 0;
}

void Init() {
	
	for (int i = 0; i <= 19; i++) {
		map[i].score = i * 2;
		map[i].reddir = i + 1;
	}
	map[5].bluedir = 21;
	map[10].bluedir = 24;
	map[15].bluedir = 26;
	for (int i = 21; i <= 23; i++) {
		map[i].score = (i - 21) * 3 + 13;
		map[i].reddir = i + 1;
	}
	map[23].reddir = 29;
	for (int i = 24; i <= 25; i++) {
		map[i].score = (i - 24) * 2 + 22;
		map[i].reddir = i + 1;
	}
	map[25].reddir = 29;
	for (int i = 26; i <= 29; i++) {
		map[i].score = 28 - (i - 26);
		map[i].reddir = i + 1;
	}
	map[29].reddir = 30;
	map[30].score = 30;
	map[30].reddir = 31;
	map[31].score = 35;
	map[31].reddir = 20;
	map[20].score = 40;
	map[20].reddir = 32;
	map[32].score = 0;
	for (int i = 0; i <= 31; i++) {
		if (i == 5 || i == 10 || i == 15) {
			map[i].next[0] = map[i].bluedir;
		}
		else {
			map[i].next[0] = map[i].reddir;
		}
		int pos = map[i].next[0];
		for (int j = 0; j < 5; j++) {
			map[i].next[j] = pos;
			if (pos == 32) {
				continue;
			}
			pos = map[pos].reddir;
		}

	}

	for (int i = 0; i < 4; i++) {
		npos[i] = 0;
	}
	score = 0;
	answer = 0;
}
void Search(int idx) {
	if (idx == 10) {
		answer = answer < score ? score : answer;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (npos[i] == 32) continue;
		int prepos = npos[i];
		int nextpos = map[npos[i]].next[input[idx]-1];
		
		if (nextpos==32 || !map[nextpos].f) {
			map[prepos].f = false;
			map[nextpos].f = true;
			npos[i] = nextpos;
			score += map[nextpos].score;
			Search(idx + 1);
			score -= map[nextpos].score;
			npos[i] = prepos;
			map[nextpos].f = false;
			map[prepos].f = true;
		}
	}


	
}