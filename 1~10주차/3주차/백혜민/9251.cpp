#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S, S1; cin >> S >> S1;
	int dp[1001][1001];

	for (int i = 0; i < 1001; i++) //배열 초기화
	{
		for (int j = 0; j < 1001; j++)
		{
			dp[i][j] = 0; //dp[i][j]는 s[i],s[j]까지의 LCS
		}
	}
	for (int i = 1; i <= S.length(); i++)
	{
		for (int j = 1; j <= S1.length(); j++)
		{
			if (S[i - 1] == S1[j - 1]) //두 문자열의 문자가 같을 경우
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else //이전에 저장된 값들 중 큰 것으로 갱신
			{
				if (dp[i - 1][j] > dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	cout << dp[S.length()][S1.length()];

	return 0;
}