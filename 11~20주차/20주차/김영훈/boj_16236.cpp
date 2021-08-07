#include<iostream>
#include<utility>
#include<queue>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;
int N,map[20][20],sz,need,visit[20][20];
pii d[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) },pos;
struct Info {
	pii pos;
	int dist;
	Info(pii pos, int dist) {
		this->pos = pos;
		this->dist = dist;
	}
};
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = -1;
			if (map[i][j] == 9) {
				pos.first = i;
				pos.second = j;
				map[i][j] = 0;
			}
		}
	}
	sz = 2;
	need = 2;
	int answer = 0;
	bool f = true;
	while (f) {
		f = false;
		queue<Info> q;
		visit[pos.first][pos.second] = answer;
		q.push(Info(pii(pos.first, pos.second),0));
		while (!q.empty()) {
			Info t = q.front();
			q.pop();
			int target = map[t.pos.first][t.pos.second];
			if (target!=0 && target<sz) {
				pii npos = t.pos;
				while (!q.empty()) {
					Info t2 = q.front();
					q.pop();
					if (t2.dist > t.dist) {
						break;
					}
					int ntarget = map[t2.pos.first][t2.pos.second];
					if (ntarget != 0 && ntarget<sz) {
						if (t2.pos.first < npos.first) {
							npos = t2.pos;
						}
						else if (t2.pos.first == npos.first && t2.pos.second < npos.second) {
							npos = t2.pos;
						}
					}
				}

				need--;
				if (need == 0) {
					sz++;
					need = sz;
				}
				map[npos.first][npos.second] = 0;
				answer += t.dist;
				pos = npos;
				f = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nr = t.pos.first + d[i].first;
				int nc = t.pos.second + d[i].second;
				if (nr < 0 || nr >= N || nc<0 || nc >= N || visit[nr][nc] == answer || map[nr][nc]>sz) continue;
				visit[nr][nc] = answer;
				q.push(Info(pii(nr, nc), t.dist + 1));
			}
		}
	
	}
	printf("%d\n", answer);
	return 0;
}