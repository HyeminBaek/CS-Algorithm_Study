#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
struct Info {
	pii s;
	pii d;
	int dist;
};
int N, M,energy,map[20][20],dist[20][20],visit[20][20];
pii taxi_pos, dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
Info pinfo[401];
int DestDist(int n);
void SearchPassenger(int n);
bool Comp(pii p1, pii p2);
int main() {
	scanf("%d%d%d", &N, &M, &energy);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			map[i][j] *= -1;
			visit[i][j] = -1;
		}
	}
	scanf("%d%d", &taxi_pos.first, &taxi_pos.second);
	taxi_pos.first--;
	taxi_pos.second--;
	for (int i = 1; i <= M; i++) {
		int sr, sc, dr, dc;
		scanf("%d%d%d%d", &sr, &sc, &dr, &dc);
		sr--;
		sc--;
		dr--;
		dc--;
		map[sr][sc] = i;
		pinfo[i].s = pii(sr, sc);
		pinfo[i].d = pii(dr, dc);
	}
	for (int i = 1; i <= M; i++) {
		pinfo[i].dist = DestDist(i);
		if (pinfo[i].dist == -1) {
			energy = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = -1;
		}
	}
	
	for (int i = 0; i < M; i++) {
		SearchPassenger(i);
		if (energy < 0) {
			energy = -1;
			break;
		}
	}
	
	printf("%d\n", energy);
	return 0;
}
int DestDist(int n) {
	queue<pii> q;
	pii pos = pinfo[n].s;
	visit[pos.first][pos.second] = n;
	dist[pos.first][pos.second] = 0;
	q.push(pos);
	while (!q.empty()) {
		pos = q.front();
		q.pop();
		if (pos == pinfo[n].d) {
			return dist[pos.first][pos.second];
		}
		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dir[i].first;
			int nc = pos.second + dir[i].second;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visit[nr][nc] == n || map[nr][nc] == -1) continue;
			visit[nr][nc] = n;
			dist[nr][nc] = dist[pos.first][pos.second] + 1;
			q.push(pii(nr, nc));
		}
	}

	return -1;
}
void SearchPassenger(int n) {
	queue<pii> q;
	visit[taxi_pos.first][taxi_pos.second] = n;
	dist[taxi_pos.first][taxi_pos.second] = 0;
	q.push(taxi_pos);
	int d = -1;
	pii target(21,21);
	while (!q.empty()) {
		pii pos = q.front();
		q.pop();
		if (d!=-1 && d < dist[pos.first][pos.second]) {
			break;
		}
		if (map[pos.first][pos.second] > 0) {
			d = dist[pos.first][pos.second];
			if (Comp(pos, target)) {
				target = pos;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dir[i].first;
			int nc = pos.second + dir[i].second;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visit[nr][nc] == n || map[nr][nc] == -1) continue;
			visit[nr][nc] = n;
			dist[nr][nc] = dist[pos.first][pos.second] + 1;
			q.push(pii(nr, nc));
		}
	}
	if (d == -1) {
		energy = -1;
		return;
	}
	
	int tn = map[target.first][target.second];
	map[target.first][target.second] = 0;
	energy -= (d + pinfo[tn].dist);
	if (energy >= 0) {
		energy += pinfo[tn].dist * 2;
	}
	taxi_pos = pinfo[tn].d;
	return;

}
bool Comp(pii p1, pii p2) {
	if (p1.first == p2.first) {
		return p1.second<p2.second;
	}
	return p1.first < p2.first;
}