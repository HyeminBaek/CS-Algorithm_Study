#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
struct Shark {
	pii pos;
	int d;
	int moveinfo[4][4];
};
int N, M, k,t,sharknum,answer;
pii map[20][20], dir[4] = { pii(-1,0),pii(1,0),pii(0,-1),pii(0,1) };
Shark shark[401];
void Move();
void Check();
int FindDir(int sn);
int main() {
	scanf("%d%d%d", &N, &M, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &t);
			if (t != 0) {
				shark[t].pos = pii(i, j);
			}
			map[i][j] = pii(0, 0);
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &shark[i].d);
		shark[i].d--;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d", &shark[i].moveinfo[j][k]);
				shark[i].moveinfo[j][k]--;
			}
		}
	}
	answer = -1;
	t = 1;
	sharknum = M;

	while (t <= 1000) {
		Move();
		
		
		Check();
		if (sharknum == 1) {
			answer = t;
			break;
		}
		t++;
	}
	printf("%d\n", answer);
	return 0;
}
void Move() {
	for (int i = 1; i <= M; i++) {
		if (shark[i].pos.first == -1) continue;
		pii npos = shark[i].pos;
		
		map[npos.first][npos.second] = pii(i, t + k);
	}
	for (int i = 1; i <= M; i++) {
		if (shark[i].pos.first == -1) continue;
		int nd = FindDir(i);
		shark[i].d = nd;
		shark[i].pos.first += dir[nd].first;
		shark[i].pos.second += dir[nd].second;
	}
}
int FindDir(int sn) {
	pii pos = shark[sn].pos;
	int d = shark[sn].d;
	for (int i = 0; i < 4; i++) {
		int nd = shark[sn].moveinfo[d][i];
		int nr = pos.first + dir[nd].first;
		int nc = pos.second + dir[nd].second;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (map[nr][nc].first == 0 || map[nr][nc].second <= t) {
			return nd;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nd = shark[sn].moveinfo[d][i];
		int nr = pos.first + dir[nd].first;
		int nc = pos.second + dir[nd].second;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (map[nr][nc].first == sn ) {
			return nd;
		}
	}	
	return -1;
}
void Check() {
	int tmap[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmap[i][j] = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (shark[i].pos.first == -1) continue;
		pii pos = shark[i].pos;
		if (tmap[pos.first][pos.second] == 0) {
			tmap[pos.first][pos.second] = i;
		}
		else {
			sharknum--;
			shark[i].pos.first = -1;
		}
	}
}