#include<iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[100001],f[100001];
int N;
int main() {
	scanf("%d", &N);
	f[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = (f[i - 1] * i) % MOD;
	}
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = (((ll)i - 1) * ((dp[i - 2] + dp[i - 1])%MOD))%MOD;
	}
	printf("%lld\n", (f[N]*dp[N])%MOD);

	return 0;
}



