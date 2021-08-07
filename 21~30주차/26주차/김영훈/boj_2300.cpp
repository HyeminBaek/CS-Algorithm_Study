#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = (1 << 30);
pii input[10000];
int N,dp[10001];
int Abs(int a) {
	return a < 0 ? -a : a;
}
int main() {
	scanf("%d", &N);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &input[i].first, &input[i].second);
		input[i].second = Abs(input[i].second);
		dp[i+1] = INF;
	}
	sort(input, input + N);
	for (int i = 0; i < N; i++) {
		int max_ypos=0;
		int xdist;
		for (int j = i; j < N; j++) {
			max_ypos = max(max_ypos, input[j].second);
			xdist = input[j].first - input[i].first;
			dp[j+1] = min(dp[j+1], dp[i] + max(xdist, 2 * max_ypos));
		}
	}
	
	printf("%d\n", dp[N]);
	return 0;
}