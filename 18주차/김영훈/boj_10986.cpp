#include<iostream>
using namespace std;
int N, M, A, dp[1000], idx;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		dp[i] = 0;
	}
	idx = 0;
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		A %= M;
		dp[idx]++;
		idx = (M + idx - A) % M;
		answer += (long long)dp[idx];

	}
	printf("%lld\n", answer);
	return 0;
}