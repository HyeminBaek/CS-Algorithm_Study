#include <iostream>
using namespace std;

struct rice
{
	int a; int b;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int D, K; cin >> D >> K;

	rice r = { 0,0 };
	rice dp[31];	dp[1] = { 1,0 }; dp[2] = { 0,1 };

	for (int i = 3; i <= D; i++)
	{
		dp[i].a = dp[i - 1].a + dp[i - 2].a;
		dp[i].b = dp[i - 1].b + dp[i - 2].b;
	}

	for (int A = 1; A <= 100001; A++)
	{
		if ((K - (dp[D].a*A)) % dp[D].b != 0) continue;
		int B = (K - (dp[D].a*A)) / dp[D].b;
		if (dp[D].a * A + dp[D].b * B == K)
		{
			cout << A << "\n" << B;
			break;
		}
	}

	return 0;
}
