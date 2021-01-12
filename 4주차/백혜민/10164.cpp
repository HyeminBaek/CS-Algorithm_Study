#include <iostream>
using namespace std;

int dp[15][15];
void sol(int sx, int sy, int ex, int ey)
{
	for (int i = sx; i <= ex; i++)
	{
		for (int j = sy; j <= ey; j++)
		{
			if (i == sx && j == sy) continue;

			if (i == sx)
				dp[i][j] = dp[i][j - 1];
			else if (j == sy)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K; cin >> N >> M >> K;

	int x, y; x = K / M; y = K % M;

	if (y == 0) y = M - 1;
	else y--;
	if (K%M == 0) x--;

	dp[0][0] = 1;
	if (K != 0)
	{
		sol(0, 0, x, y);
		sol(x, y, N - 1, M - 1);

		cout << dp[N - 1][M - 1];
	}
	else
	{
		sol(0, 0, N - 1, M - 1);
		cout << dp[N - 1][M - 1];
	}
	return 0;
}
