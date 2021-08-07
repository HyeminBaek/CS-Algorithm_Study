#include<iostream>
#include<vector>
using namespace std;
struct pos {
	int r;
	int c;
	pos(int r, int c) {
		this->r = r;
		this->c = c;
	}
};
int N, M, a, clist[13];
vector<pos> h, c;
int Dist(pos p1, pos p2) {
	int xdist = p1.r - p2.r;
	xdist = xdist < 0 ? -xdist : xdist;
	int ydist = p1.c - p2.c;
	ydist = ydist < 0 ? -ydist : ydist;
	return xdist + ydist;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a == 1) {
				h.push_back(pos(i, j));
			}
			else if (a == 2) {
				c.push_back(pos(i, j));
			}
		}
	}
	for (int i = 0; i < M; i++) {
		clist[i] = i;
	}
	int answer = 100 * 100 + 1;
	while (1) {
		int sum = 0;
		for (int i = 0; i < h.size(); i++) {
			int mdist = 101;
			for (int j = 0; j < M; j++) {
				int t = Dist(h[i], c[clist[j]]);
				mdist = mdist > t ? t : mdist;
			}
			sum += mdist;
		}
		answer = answer > sum ? sum : answer;

		int pos = M - 1;
		while (pos >= 0 && clist[pos] == c.size() - M + pos) {
			pos--;
		}
		if (pos == -1) {
			break;
		}
		clist[pos]++;
		for (int i = pos + 1; i < M; i++) {
			clist[i] = clist[i - 1] + 1;
		}
	}
	cout << answer << "\n";
	return 0;
	
}
