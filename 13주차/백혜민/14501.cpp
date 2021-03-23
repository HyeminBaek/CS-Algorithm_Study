#include <iostream>
#include <cstring>
using namespace std;

struct schedule
{
	int time, pay;
};
int N;
schedule arr[16];
int dp[16];

int sol(int d)
{
	if (d == N) return 0;
	else if (d > N) return -987654321;

	int ret = dp[d];
	if (ret != -1) return ret;

	return (sol(d + 1) > sol(d + arr[d].time) + arr[d].pay) ? sol(d + 1) : sol(d + arr[d].time) + arr[d].pay;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].time >> arr[i].pay;

	memset(dp, -1, sizeof(dp));
}
int main()
{
	init();
	cout << sol(0);

	return 0;
}
