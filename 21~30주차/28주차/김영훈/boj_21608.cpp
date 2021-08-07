#include<iostream>
#include<utility>
#include<cmath>
using namespace std;
typedef pair<int, int> pii;
int N,seat[20][20],n,d[401][4];
pii dir[4] = { pii(1,0),pii(-1,0),pii(0,1),pii(0,-1) };
pii Search(int n);
pii Adj_Empty_Num(pii p,int n);
bool CompSeat(pii p1, pii p2,int n);
int FindAns();
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			seat[i][j] = 0;
		}
	}

	for (int i = 0; i < N * N; i++) {
		scanf("%d", &n);
		scanf("%d%d%d%d", &d[n][0], &d[n][1], &d[n][2], &d[n][3], &d[n][4]);
		pii npos = Search(n);
		seat[npos.first][npos.second] = n;
	}
	printf("%d\n", FindAns());
	
	return 0;
}
pii Search(int n) {
	pii ret = pii(-1, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (seat[i][j] == 0) {
				if (!CompSeat(ret, pii(i, j),n)) {
					ret = pii(i, j);
				}
			}
		}
	}
	return ret;
}
pii Adj_Empty_Num(pii p,int n) {
	pii ret = pii(0, 0);
	for (int i = 0; i < 4; i++) {
		int nr = p.first + dir[i].first;
		int nc = p.second + dir[i].second;
		if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
			if (seat[nr][nc] == 0) {
				ret.second++;
			}
			else {
				for (int j = 0; j < 4; j++) {
					ret.first += (d[n][j] == seat[nr][nc]);
				}
			}
		}
	}
	return ret;
}
bool CompSeat(pii p1, pii p2,int n) {
	if (p1.first == -1) {
		return false;
	}
	pii adj_empty_p1 = Adj_Empty_Num(p1, n);
	pii adj_empty_p2=Adj_Empty_Num(p2,n);

	

	if (adj_empty_p1.first != adj_empty_p2.first) {
		return adj_empty_p1.first > adj_empty_p2.first;
	}
	if (adj_empty_p1.second != adj_empty_p2.second) {
		return adj_empty_p1.second > adj_empty_p2.second;
	}

	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}
int FindAns() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k = Adj_Empty_Num(pii(i, j), seat[i][j]).first;
			if (k > 0) {
				ret += pow(10, k - 1);
			}
		}
	}
	return ret;
}