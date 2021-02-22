#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int answer[101][101];
vector<pair<int, int>> v[101];
void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer[i][j] = 10000000;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		answer[a][b] = min(c, answer[a][b]);
	}
	for (int i = 1; i <= N; i++) {
		answer[i][i] = 0;
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (answer[j][i] + answer[i][k] < answer[j][k]) {
					answer[j][k] = answer[j][i] + answer[i][k];
				}
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	solve();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (answer[i][j] == 10000000) {
				answer[i][j] = 0;
			}
			cout << answer[i][j] <<' ';
		}
		cout << '\n';
	}
	return 0;
}
