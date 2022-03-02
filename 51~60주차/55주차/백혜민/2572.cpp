#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M;
vector<char> cards;
vector<pair<int,char>> v[501];
int dp[1001][501]; //dp[i][j] = i번 카드이면서 j에 있을 때의 최대 점수

int solution(int c, int n)
{
	if (c >= cards.size()) return 0;

	int& ret = dp[c][n];
	if (ret != -1) return ret;
    ret =0;
    
	for (int k = 0;k < v[n].size();k++)
	{
		int nx = v[n][k].first;
		ret = max(ret,solution(c+1,nx)+((cards[c]==v[n][k].second)?10:0));
	}

	return ret;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	for (int i = 0;i < N;i++)
	{
		char c; cin >> c;
		cards.push_back(c);
	}

	int K; cin >> M >> K;
	for (int i = 0;i < K;i++)
	{
		int s, e; char c; cin >> s >> e >> c;
		s -= 1; e -= 1;

		v[s].push_back({ e,c });
		v[e].push_back({ s,c });
	}

	for (int i = 0;i < N;i++) for (int j = 0;j < M;j++) dp[i][j] = -1;
}
int main()
{
	init();
	cout << solution(0,0);

	return 0;
}