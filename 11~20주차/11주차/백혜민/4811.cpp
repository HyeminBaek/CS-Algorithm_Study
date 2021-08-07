#include <iostream>
#include <cstring>
using namespace std;

int N;

long long dp[31][31];
long long pill(int W, int H)
{
	if (W == 0) return 1;
	if (dp[W][H] != 0) return dp[W][H];
	
	dp[W][H] = pill(W - 1, H + 1);
	if (H > 0)
		dp[W][H] += pill(W, H - 1);

	return dp[W][H];
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> N)
	{
		if (N == 0) break;

		memset(dp, 0, sizeof(dp));
		cout << pill(N, 0) << "\n";
	}
}
int main()
{
	init();

	return 0;
}
