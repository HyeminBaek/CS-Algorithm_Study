#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	int dp[10001][4]; //dp[i][j] = n이 i이고 제일 끝에 위치한 숫자가 j인 경우의 수
	for (int i = 0; i < 10001; i++) //배열 초기화
	{
		for (int j = 0; j < 4; j++)
			dp[i][j] = 0;
	}

	dp[1][1] = 1, dp[2][1] = 1, dp[2][2] = 1, dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;

	for (T; T > 0; T--)
	{
		int n; cin >> n;

		if (n < 4)
		{
			int sum = 0;
			for (int i = 1; i <= 3; i++)
			{
				if (n < i) break;
				sum += dp[n][i];
			}
			cout << sum << "\n";
		}
		else
		{
			if (dp[n][1] == 0) //한 번에 1,2,3 처리를 동시에 해주므로 1이 처리가 안되어있다는 건 방문 안했다는 것
			{
				for (int i = 4; i <= n; i++)
				{
					if (dp[i][1] != 0) continue; //이미 이전에 연산을 처리해주었으므로 또 하지 않는다
					else
					{
						dp[i][1] = dp[i - 1][1];
						dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
						dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
					}
				}
			}
			cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
		}
	}

	return 0;
}
