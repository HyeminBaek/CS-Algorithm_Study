#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp[101][100001] = { 0, }; //dp[물건이 i개 들어감][앞으로 더 넣을 수 있는 용량]
	int w[101];	int vl[101];

	int N, K, result = 0;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> w[i] >> vl[i];

	for (int i = 1; i <= N; i++) //i번째 물건이 가방에 들어가는지 여부를 위한 전체 for문
	{
		for (int j = K; j >= 0; j--)
		{
			if (w[i] <= j) //더 넣을 수 있는 무게보다 가벼우므로 가방에 넣을 수 있음
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + vl[i]);
				result = max(result,dp[i][j]);
			}
			else //메모이제이션용
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << result;

	return 0;
}
