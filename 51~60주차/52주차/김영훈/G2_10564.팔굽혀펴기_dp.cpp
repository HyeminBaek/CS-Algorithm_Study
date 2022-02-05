#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int T, N, M,S[11];
int visit[5005][505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i <= 5000; i++) {
		for (int j = 0; j <= 500; j++) {
			visit[i][j] = T;
		}
	}

	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> S[i];
		}
		int ans = -1;

		queue<pii> q;
		q.push({ 0,0 });
		visit[0][0] = T;
		while (!q.empty()) {
			pii t = q.front();
			
			q.pop();
			if (t.first == N) ans = t.second > ans ? t.second : ans;

			for (int i = 0; i < M; i++) {
				int nNum = t.first +t.second+S[i];
				int nScore = t.second + S[i];
				if (nNum > N || visit[nNum][nScore]==T) continue;
				visit[nNum][nScore] = T;
				q.push({ nNum, nScore });
			}
		}
		cout << ans << "\n";
	}
	return 0;
}