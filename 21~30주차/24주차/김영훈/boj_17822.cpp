#include<iostream>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N, M, T,x,d,k,input[50][50],r[50],visit[50][50],ct=0;
pii dir[4] = { pii(1,0),pii(0,1),pii(-1,0),pii(0,-1) };
int retIdx(int i, int j) {
	return (j + r[i]) % M;
}
bool BFS(int i, int j) {
	queue<pii> q1, q2;
	int idx = retIdx(i, j);
	int n = input[i][idx];
	if (n == 0) {
		return false;
	}
	ct++;
	visit[i][j] = ct;
	q1.push(pii(i, j));
	while (!q1.empty()) {
		pii t = q1.front();
		q1.pop();
		q2.push(t);
		for (int k = 0; k < 4; k++) {
			int nr = t.first + dir[k].first;
			int nc = t.second + dir[k].second;
			nc = (M + nc) % M;
			if (nr < 0 || nr >= N || visit[nr][nc]==ct) continue;

			idx= retIdx(nr, nc);
			if (input[nr][idx] == n) {
				q1.push(pii(nr, nc));
				visit[nr][nc] = ct;
			}
		}

	}
	if (q2.size() >= 2) {
		while (!q2.empty()) {
			pii t = q2.front();
			q2.pop();
			idx = retIdx(t.first, t.second);
			input[t.first][idx] = 0;
		}


		return true;
	}
	else {
		return false;
	}
	
}
void Cal() {
	bool f = false;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {		
			if (BFS(i, j)) {
				f = true;
			}				
		}
		
	}
	if (!f) {
		int sum = 0, num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum += input[i][j];
				num += (input[i][j] > 0);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (input[i][j] == 0) continue; 
				
				if (input[i][j] * num > sum) {
					input[i][j]--;
				}
				else if (input[i][j] * num < sum) {
					input[i][j]++;
				}
				
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &N, &M, &T);
	for (int i = 0; i < N; i++) {
		r[i] = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &input[i][j]);
			visit[i][j] = -1;
		}
	}
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d", &x, &d, &k);
		for (int j = x; j <= N; j += x) {
			if (d == 0) {
				r[j - 1] = (M + r[j - 1] - k) % M;
			}
			else {
				r[j - 1] = (r[j - 1] + k) % M;
			}
			
		}
		
		Cal();
		
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer += input[i][j];
		}
	}
	printf("%d\n", answer);
	return 0;
}