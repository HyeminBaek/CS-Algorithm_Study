#include<iostream>
#include<utility>
using namespace std;
typedef pair<int, int> pii;
int N,sum;
pii coin[100];
bool dp[50001];
int main() {
	int T = 3;
	while (T--) {
		scanf("%d", &N);
		sum = 0;
		bool ans;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &coin[i].first, &coin[i].second);
			sum += coin[i].first * coin[i].second;
		}
		if (sum % 2 == 1) {
			ans = false;
		}
		else {
			sum /= 2;
			for (int i = 0; i <= sum; i++) {
				dp[i] = false;
			}
			int maxval = 0;
			dp[0] = true;
			for (int i = 0; i < N; i++) {
				for (int j = maxval; j >=0; j--) {
					if (!dp[j]) continue;
					for (int k = 1; k <=coin[i].second; k++) {
						if (j + k * coin[i].first > sum) continue;
						dp[j + k * coin[i].first] = true;
						
					}
				}
				maxval += coin[i].first * coin[i].second;
				maxval = maxval > sum ? sum : maxval;
			}
			
			ans = dp[sum];
		}
		printf("%d\n", ans);
		
	}
	return 0;
}
