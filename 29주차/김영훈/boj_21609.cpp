#include<iostream>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, map[20][20],visit[20][20],ct,score;
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
bool CompPos(const pii& p1, const pii& p2);
int DelBlock(int ct);
void Gravity();
void Rotate();
int main() {
	scanf("%d%d", &N, &M);
	ct = 0;
	score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = -1;
			
		}
	}
	
	while (1) {
		int r = DelBlock(ct++);
		if (r<2) {
			break;
		}
		score += r*r;	
		Gravity();
		Rotate();		
		Gravity();		
	}
	printf("%d\n", score);
	return 0;
}
bool CompPos(const pii& p1, const pii& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}
int DelBlock(int ct) {
	queue<pii> q;
	deque<pii> poslist;
	int rn1 = 0;
	deque<pii> nposlist;
	int rn2 = 0;
	poslist.clear();
	nposlist.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != ct && map[i][j]>0) {
				int color = map[i][j];
				rn2 = 0;
				q.push(pii(i,j));
				
				visit[i][j] = ct;
				
				while (!q.empty()) {
					pii t = q.front();
					q.pop();
					if (map[t.first][t.second] == 0) {
						rn2++;
					}
					if (!nposlist.empty() &&map[t.first][t.second]==color &&  CompPos(t, nposlist.front())) {
						nposlist.push_front(t);
					}
					else {
						nposlist.push_back(t);
					}

					for (int k = 0; k < 4; k++) {
						int nr = t.first + dir[k].first;
						int nc = t.second + dir[k].second;
						if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
						if (map[nr][nc] < 0 || visit[nr][nc] == ct) continue;
						if (map[nr][nc] != 0 && map[nr][nc] != color) continue;
						q.push(pii(nr, nc));
						visit[nr][nc] = ct;
					}

				}
				if (nposlist.size() > poslist.size()) {
					poslist = nposlist;
					rn1 = rn2;
			
				}
				else if (nposlist.size() == poslist.size() && rn1 < rn2) {
					poslist = nposlist;
					rn1 = rn2;
				}
				else if (nposlist.size() == poslist.size() && rn1==rn2 && CompPos(poslist.front(),nposlist.front())) {
					poslist = nposlist;
					rn1 = rn2;
				}
				while (!nposlist.empty()) {
					pii t = nposlist.front();
					nposlist.pop_front();
					if (map[t.first][t.second] == 0) {
						visit[t.first][t.second] = -1;
					}
				}
			}



		}
	}
	
	int ret = poslist.size();
	if (ret >= 2) {

		while (!poslist.empty()) {
			pii t = poslist.front();
			poslist.pop_front();
			map[t.first][t.second] = -2;
		}
	}
	return ret;
}
void Gravity() {
	for (int c = 0; c < N; c++) {
		int nextpos = N - 1;
		for (int r = N-1; r>=0; r--) {
			if (map[r][c] == -1) {
				nextpos = r - 1;
			}
			else if (map[r][c] >= 0) {
				int temp = map[r][c];
				map[r][c] = -2;
				map[nextpos--][c] = temp;
			}
		}
	}
}
void Rotate() {
	int temp[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[N-1-j][i] = map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}
}