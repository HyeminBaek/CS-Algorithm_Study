#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int arr[101][101];
int N, M;
int movement[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };
int answer[101][101];

void init() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j + 1] = s[j] - 48;
		}
	}
	memset(answer, 1000000, sizeof(answer));
}

void solve() {
	queue<pair<pair<int, int>, int>> q;
	q.push({{ 1,1 }, 0});
	answer[1][1] = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int> current = q.front();
		int cost = -current.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first.first + movement[i][0];
			int ny = current.first.second + movement[i][1];
			if (nx > 0 && nx <= M && ny > 0 && ny <= N) {
				if (answer[nx][ny] > cost + arr[nx][ny]) {
					answer[nx][ny] = cost + arr[nx][ny];
					q.push({ {nx,ny}, -(cost + arr[nx][ny]) });
				}
			}
		}
	}
}

int main(void) {
	init();
	solve();
	cout << answer[M][N];
	return 0;
}
