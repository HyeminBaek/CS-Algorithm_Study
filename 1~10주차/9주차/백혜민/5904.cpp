#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	if (N <= 3)
	{
		cout << "moo"[N-1]; return 0;
	}

	vector<pair<long long, long long>> dp; dp.push_back({ 0,3 });

	for (long long k = 1; ; k++)
	{
		dp.push_back({ k,2 * dp[k - 1].second + k + 3 });

		if (2 * dp[k - 1].second + k + 3 > N) break;
	}

	long long K = dp.size() - 1;
	int temp = N;

	while (1)
	{
		//cout << K <<" "<<temp<< endl;
		if (K == 0)
		{
			cout << "moo"[temp - 1]; return 0;
		}
		else
		{
			if (temp - dp[K - 1].second <= K + 3) //o가 k+2개인 부분에 걸린 경우
			{
				if (temp - dp[K - 1].second >= 0)
				{
					if (temp - dp[K - 1].second == 1) cout << "m";
					else cout << "o";

					return 0;
				}
				else
				{
					K--;
				}
			}
			else
			{
				temp = temp - dp[K - 1].second - (K + 3); K--; //S(k-1) 인 상태
			}
		}
	}

	return 0;
}
