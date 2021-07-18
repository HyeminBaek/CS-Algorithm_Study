#include<iostream>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
int N, M, A[50][50],d,s;
pii dir[8] = { pii(0,-1),pii(-1,-1),pii(-1,0),pii(-1,1),pii(0,1),pii(1,1),pii(1,0),pii(1,-1) };
vector<pii> cloudlist;
void Move(int d, int s);
void Raining();
void Casting();
void InitCloud();
int main() {
	cloudlist.clear();
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	cloudlist.push_back(pii(N - 1, 0));
	cloudlist.push_back(pii(N - 1, 1));
	cloudlist.push_back(pii(N - 2, 0));
	cloudlist.push_back(pii(N - 2, 1));
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &d, &s);
		
		Move(d - 1, s%N);
		Raining();
		Casting();
		InitCloud();
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += A[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
void Move(int d, int s) {
	for (int i = 0; i < cloudlist.size(); i++) {
		cloudlist[i].first += (N + s * dir[d].first);
		cloudlist[i].first %= N;
		cloudlist[i].second += (N + s * dir[d].second);
		cloudlist[i].second %= N;
	}
}
void Raining() {
	for (int i = 0; i < cloudlist.size(); i++) {
		A[cloudlist[i].first][cloudlist[i].second]++;
	}
}
void Casting() {
	for (int i = 0; i < cloudlist.size(); i++) {
		int n = 0;
		pii t = cloudlist[i];
		for (int j = 1; j < 8; j += 2) {
			int nr = t.first + dir[j].first;
			int nc = t.second + dir[j].second;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			n += (A[nr][nc] > 0);
		}
		A[t.first][t.second] += n;
	}
}
void InitCloud() {
	bool check[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < cloudlist.size(); i++) {
		check[cloudlist[i].first][cloudlist[i].second] = true;
	}
	cloudlist.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j] && A[i][j] >= 2) {
				cloudlist.push_back(pii(i, j));
				A[i][j] -= 2;
			}
		}
	}
}