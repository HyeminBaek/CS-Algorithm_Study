#include<iostream>
#include<vector>
using namespace std;
int N,p[10000],s,e,dp[2][10000];
vector<int> adjlist[10000];
void DFS(int k) {
	dp[0][k] = 0;
	dp[1][k] = p[k];
	for (int i = 0; i < adjlist[k].size(); i++) {
		int next = adjlist[k][i];
		if (dp[0][next] == -1) {
			DFS(next);
			dp[0][k] += (dp[0][next] < dp[1][next] ? dp[1][next] : dp[0][next]);
			dp[1][k] += dp[0][next];
		}
		
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
		dp[0][i] = -1;
		dp[1][i] = -1;
	}
	for (int i = 0; i < N - 1; i++) {
		scanf("%d%d", &s, &e);
		adjlist[s - 1].push_back(e - 1);
		adjlist[e - 1].push_back(s - 1);
	}
	DFS(0);
	printf("%d\n", dp[0][0] < dp[1][0] ? dp[1][0] : dp[0][0]);
	return 0;
}