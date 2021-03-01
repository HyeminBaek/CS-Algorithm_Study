#include <iostream>
#include <algorithm>
using namespace std;

/*
sol 1) 별 생각 없이 2초나 주길래 2중for 문 돌리면서 하나씩 제거하면서 DP 배열에 저장 -> TLE
sol 2) 
시간복잡도 뒤늦게 계산 후 for문 한 번만에 끝나야 함을 깨달음, 2차원 dp 생각
2차원 dp 식은 넣는다/뺀다 둘 중 하나로 구성
까진 생각했으나 식 구성이 도저히 생각 안나서 식 구성은 해설을 봄

dp[n][2] => 0이면 안 뺀 것, 1이면 i번째를 빼고 생각한 것
dp[n][0]의 경우 연속합 그대로 식 유지
dp[n][1]의 경우 뺄 것인가 말 것인가를 생각해야 함
=> dp[i-1][0] 뺀 경우가 큰 경우 / dp[i-1][1]+arr[i] 이미 앞에서 빠진 것에다가 연산
*/

void init(int&,int []);
int sol(const int,int []);

int main()
{
	int N;
	int arr[100001];

	init(N,arr);
	cout << sol(N, arr);

	return 0;
}
int sol(const int N, int arr[])
{
	int answer = arr[0];
	
	int dp[100001][2];
	dp[0][0] = arr[0], dp[0][1] = 0;

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = arr[i], dp[i][1] = dp[i - 1][0];

		if (dp[i - 1][0] + arr[i] > dp[i][0]) dp[i][0] = arr[i] + dp[i - 1][0];
		if (dp[i - 1][1] + arr[i] > dp[i][1]) dp[i][1] = arr[i] + dp[i - 1][1];

		answer = (answer < dp[i][0]) ? dp[i][0] : answer;
		answer = (answer < dp[i][1]) ? dp[i][1] : answer;
	}

	return answer;
}
void init(int &N,int arr[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
}
