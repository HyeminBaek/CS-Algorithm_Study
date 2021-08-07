#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, M, map[50][50],comb[10],time[50][50],visit[50][50],ct,emptyNum;
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,-1),pii(0,1) };
vector<pii> virus;

int BFS() {
	queue<pii> q;
	int _emptyNum = emptyNum;
	for (int i = 0; i < M; i++) {
		pii t = virus[comb[i]];
		visit[t.first][t.second] = ct;
		time[t.first][t.second] = 0;
		q.push(t);
	}
	int ret = 0;
	while (!q.empty()) {
		pii t = q.front();
		q.pop();
		
		if (map[t.first][t.second] == 0) {
			_emptyNum--;
			
		}
		if (_emptyNum == 0) {
			return time[t.first][t.second];
		}
		for (int i = 0; i < 4; i++) {
			int nr = t.first + dir[i].first;
			int nc = t.second + dir[i].second;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visit[nr][nc] == ct || map[nr][nc] == 1) continue;
			visit[nr][nc] = ct;
			time[nr][nc] = time[t.first][t.second] + 1;
			q.push(pii(nr, nc));
		}
	}
	
	return -1;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			visit[i][j] = -1;
			
			if (map[i][j] == 2) {
				virus.push_back(pii(i, j));
				
			}
			if (map[i][j] == 0) {
				emptyNum++;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		comb[i] = i;
	}
	int answer = N*N+1;
	ct = 0;
	while (1) {

		int r = BFS();
		if (r >= 0) {
			answer = answer > r ? r : answer;
		}
		
		ct++;
		int idx = M - 1;
		while (idx >= 0 && comb[idx]==virus.size()+idx-M) {
			idx--;
		}


		if (idx == -1) {
			break;
		}

		comb[idx]++;
		for (int i = idx + 1; i < M; i++) {
			comb[i] = comb[i - 1] + 1;
		}
	}
	if (answer == N * N + 1) {
		answer = -1;
	}
	printf("%d\n", answer);
	return 0;
}