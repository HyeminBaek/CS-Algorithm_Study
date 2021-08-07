#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;

map<int,int> m;
vector<int> v[10001];
int N;
int indegree[10001];
int dp[10001];

void toplogical()
{
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			dp[i] = m[i];	pq.push(i);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int cur = pq.top();
		pq.pop();

		for (int next : v[cur])
		{
			if (--indegree[next] == 0) pq.push(next);
			dp[next] = (dp[next] > dp[cur] + m[next]) ? dp[next] : dp[cur] + m[next];
		}
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int tme, pre; cin >> tme >> pre;
		for (int j = 0; j < pre; j++)
		{
			int pwork; cin >> pwork;
			v[i].push_back(pwork);
			indegree[pwork]++;
		}
		m.insert({ i,tme });
	}
}
int main()
{
	init();
	toplogical();
	sort(dp, dp + N + 1);
	cout << dp[N];

	return 0;
}
