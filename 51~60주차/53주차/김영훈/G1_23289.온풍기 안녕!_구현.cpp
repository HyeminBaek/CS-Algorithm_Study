#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
struct Heater {
	int r, c, d;
	Heater(int r, int c, int d) {
		this->r = r;
		this->c = c;
		this->d = d;
	}
};
int R, C, K, t[20][20], w[20][20], k, W,temp[20][20];
pii dir[4] = { {0,1},{1,0},{0,-1},{-1,0} }; //동 남 서 북
vector<Heater> heaters;
vector<pii> targets;
bool isValidPos(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}
bool isWall(int r, int c, int d) {
	return (w[r][c] & (1 << d)) != 0;
}
void heat() {
	queue<pii> q;
	for (int i = 0; i < heaters.size(); i++) {
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				temp[r][c] = -1;
			}
		}
		int nd = heaters[i].d;
		int nr = heaters[i].r + dir[nd].first;
		int nc = heaters[i].c + dir[nd].second;

		if (isValidPos(nr, nc)) {
			q.push(pii(nr, nc));
			temp[nr][nc] = 5;
			t[nr][nc] += 5;
		}

		while (!q.empty()) {
			pii now = q.front();
			q.pop();
			if (temp[now.first][now.second] == 1) continue;
			//직진
			nr = now.first + dir[nd].first;
			nc = now.second + dir[nd].second;
			if (!isWall(now.first,now.second,nd) && isValidPos(nr,nc) && temp[nr][nc]==-1) {
				temp[nr][nc] = temp[now.first][now.second] - 1;
				t[nr][nc] += temp[nr][nc];
				q.push(pii(nr, nc));		
			}

			//오른쪽 대각선
			nr = now.first + dir[nd].first + dir[(nd + 1) % 4].first;
			nc = now.second + dir[nd].second + dir[(nd + 1) % 4].second;
			if (isValidPos(nr, nc) && temp[nr][nc] == -1 && !isWall(now.first, now.second, (nd + 1) % 4) && !isWall(nr, nc, (nd + 2) % 4)) {
				temp[nr][nc] = temp[now.first][now.second] - 1;
				t[nr][nc] += temp[nr][nc];
				q.push(pii(nr, nc));
			}

			//왼쪽 대각선
			nr = now.first + dir[nd].first + dir[(nd +3) % 4].first;
			nc = now.second + dir[nd].second + dir[(nd +3) % 4].second;
			if (isValidPos(nr, nc) && temp[nr][nc] == -1 && !isWall(now.first, now.second, (nd + 3) % 4) && !isWall(nr, nc, (nd + 2) % 4)) {
				temp[nr][nc] = temp[now.first][now.second] - 1;
				t[nr][nc] += temp[nr][nc];
				q.push(pii(nr, nc));
			}
		}
	}

	
}

void spread() {
	int temp[20][20];
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			temp[r][c] = 0;
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (t[r][c] == 0) continue;
			for (int d = 0; d < 4; d++) {
				int nr = r + dir[d].first;
				int nc = c + dir[d].second;
				if (!isValidPos(nr, nc) || t[nr][nc]>=t[r][c] || isWall(r,c,d)) continue;
				int dif = (t[r][c] - t[nr][nc]) / 4;
				temp[nr][nc] += dif;
				temp[r][c] -= dif;
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			t[r][c] += temp[r][c];
		}
	}
}

void dec() {
	for (int i = 0; i < R; i++) {
		t[i][0] -= (t[i][0] > 0);
		t[i][C - 1] -= (t[i][C-1] > 0);
	}
	for (int i = 1; i < C - 1; i++) {
		t[0][i] -= (t[0][i] > 0);
		t[R - 1][i] -= (t[R - 1][i] > 0);
	}
}

bool isComplete() {
	for (int i = 0; i < targets.size(); i++) {
		if (t[targets[i].first][targets[i].second] < K) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> K;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			t[r][c] = 0;
			w[r][c] = 0;
			cin >> k;
			switch (k) {
			case 1:
				heaters.push_back(Heater(r, c, 0));
				break;
			case 2:
				heaters.push_back(Heater(r, c, 2));
				break;
			case 3:
				heaters.push_back(Heater(r, c, 3));
				break;
			case 4:
				heaters.push_back(Heater(r, c, 1));
				break;
			case 5:
				targets.push_back(pii(r, c));
				break;
			}
		}
	}
	cin >> W;
	int r, c;
	for (int i = 0; i < W; i++) {
		cin >> r >> c >> k;
		r--, c--;
		if (k == 0) {
			w[r][c] |= (1 << 3);
			if (isValidPos(r - 1, c)) {
				w[r - 1][c] |= (1 << 1);
			}
		}
		else {
			w[r][c] |= (1 << 0);
			if (isValidPos(r, c + 1)) {
				w[r][c + 1] |= (1 << 2);
			}
		}
	}
	int ans = 0;
	while (ans < 101) {
		heat();
		spread();
		dec();
		ans++;
		if (isComplete()) break;
	}
	cout << ans << "\n";
	return 0;
}