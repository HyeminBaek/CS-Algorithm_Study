#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, W;
vector<int> v;
int dp[1001][31][3];

int solution(int t, int w, int loc)
{
	if (t >= T) return 0;

	int& ret = dp[t][w][loc];
	if (ret != -1) return ret;

	// 안 움직이고 그대로 정지
	ret = max(ret, solution(t + 1, w, loc) + ((v[t] == loc) ? 1 : 0));

	if (w < W) { // 더 움직일 수 있다
		int next = (loc == 1) ? 2 : 1;
		ret = max(ret, solution(t + 1, w + 1, next) + ((v[t] == next) ? 1 : 0));
	}

	return ret;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T >> W;
	for (int i = 0;i < T;i++)
	{
		int x; cin >> x;
		v.push_back(x);
	}

	for (int i = 0;i <= T;i++) for (int j = 0;j <= W;j++) for (int k = 0;k < 3;k++) dp[i][j][k] = -1;
}
int main()
{
	init();
	cout<<solution(0, 0, 1);

	return 0;
}