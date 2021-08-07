#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, answer;
vector<int> work[10001];
int d[10001];
int value[10001];
void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int time, x;
		cin >> time >> x;
		value[i] = time;
		if (x == 0) d[i] = time;
		for (int j = 0; j < x; j++) {
			int pre;
			cin >> pre;
			work[pre].push_back(i);
		}
	}
}

void bfs() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < work[i].size(); j++) {
			if (d[work[i][j]] < d[i] + value[work[i][j]]) {
				d[work[i][j]] = d[i] + value[work[i][j]];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
	}
	for (int i = 1; i <= N; i++) {
		//cout << d[i] << ' ';
		answer = max(answer, value[i]);
		answer = max(answer, d[i]);
	}
}
int main(void) {
	init();
	bfs();
	cout << answer;
	return 0;
}
