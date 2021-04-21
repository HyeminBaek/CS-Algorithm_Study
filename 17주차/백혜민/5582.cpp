#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int answer;
string s1, s2;
int dp[4001][4001]; //dp[i][j]=s1[i]와 s2[j]에서의 최대 길이

void sol()
{
	for (int i = 0; i < s1.length(); i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j - 1] + 1;

				answer = max(answer, dp[i][j]);
			}
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s1 >> s2;
}
int main()
{
	init();
	sol();
	cout << answer;

	return 0;
}
