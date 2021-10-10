#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll weight[1000], energy[1000], cost[1000], maxWeight[1000][1000], maxEnergy[1000][1000];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &weight[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &energy[i]);
	}

	for (int i = 0; i < N; i++) {
		maxWeight[i][i] = weight[i];
		maxEnergy[i][i] = energy[i];
		for (int j = i + 1; j < N; j++) {
			maxWeight[i][j] = max(maxWeight[i][j - 1], weight[j]);
			maxEnergy[i][j] = max(maxEnergy[i][j - 1], energy[j]);
		}
	}


	for (int i = 0; i < N; i++) {
		cost[i] = maxWeight[0][i] * maxEnergy[0][i];
		for (int j = 0; j < i; j++) {
			cost[i] = min(cost[i], cost[j] + maxWeight[j + 1][i] * maxEnergy[j + 1][i]);
		}
	}
	printf("%lld\n", cost[N - 1]);
	return 0;
}