#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
struct Shark {
	pii pos;
	int d;
};
pii pos[16],map[4][4],dir[8] = { pii(-1,0),pii(-1,-1),pii(0,-1),pii(1,-1),pii(1,0),pii(1,1),pii(0,1),pii(-1,1) };
int a, b,answer;
Shark shark;
void Init();
void Move();
void Search(int n);
int main() {
	for (int i = 0; i < 16; i++) {
		scanf("%d%d", &a, &b);
		map[i / 4][i % 4] =pii(a-1, b-1);
		pos[a-1] = pii(i / 4, i % 4);
	}
	Init();
	Search(answer);
	printf("%d\n", answer);
	return 0;
}
void Init() {
	int target = map[0][0].first;
	answer = target+1;
	map[0][0].first = -2;
	shark.pos = pii(0, 0);
	shark.d = map[0][0].second;
	pos[target].first = -1;
	
}
void Move() {
	for (int i = 0; i < 16; i++) {
		if (pos[i].first == -1) continue;
		int d = map[pos[i].first][pos[i].second].second;

		for (int j = 0; j < 8; j++) {
			int nd = (d + j) % 8;
			int nr = pos[i].first + dir[nd].first;
			int nc = pos[i].second + dir[nd].second;
			if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4 || map[nr][nc].first == -2) continue;
			if (map[nr][nc].first == -1) {
				map[nr][nc] = pii(i, nd);
				map[pos[i].first][pos[i].second].first = -1;
				pos[i] = pii(nr, nc);
			}
			else {
				pii ppos = pos[i];
				pii temp = map[ppos.first][ppos.second];
				temp.second = nd;
				int target = map[nr][nc].first;
				map[ppos.first][ppos.second] = map[nr][nc];
				pos[target] = ppos;
				map[nr][nc] = temp;
				pos[i] = pii(nr, nc);
				
			}
			
			break;
		}

	}
}
void Search(int n) {
	pii prepos[16];
	pii premap[4][4];
	for (int i = 0; i < 16; i++) {
		prepos[i] = pos[i];
		premap[i / 4][i % 4] = map[i / 4][i % 4];
	}
	
	Move();
	int nr = shark.pos.first;
	int nc = shark.pos.second;
	bool f = false;
	Shark preshark = shark;
	while (1) {
		nr += dir[shark.d].first;
		nc += dir[shark.d].second;
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) break;
		if (map[nr][nc].first >=0) {
			f = true;
			int target = map[nr][nc].first;		
			
			pos[target].first = -1;
			map[nr][nc].first = -2;
			map[preshark.pos.first][preshark.pos.second].first = -1;
			shark.pos = pii(nr, nc);
			shark.d = map[nr][nc].second;			
			Search(n + target+1);
			pos[target] = pii(nr, nc);
			map[nr][nc].first = target;
			shark = preshark;

		}

		
	}
	if (!f) {
		answer = answer < n ? n : answer;
	}
	for (int i = 0; i < 16; i++) {
		pos[i] = prepos[i];
		map[i / 4][i % 4] = premap[i / 4][i % 4];
	}
}