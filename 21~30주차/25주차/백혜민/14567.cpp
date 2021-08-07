#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int indegree[1001];
vector<int> v[1001];

void top()
{
	int result[1001] = { 0, };
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0) q.push(i);

		result[i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (q.empty()) break;

		int cur = q.front();
		q.pop();

		for (int j = 0; j < v[cur].size(); j++)
		{
			if (--indegree[v[cur][j]] == 0)
			{
				q.push(v[cur][j]);
				result[v[cur][j]] = (result[v[cur][j]] < result[cur] + 1) ? result[cur] + 1 :result[v[cur][j]];
			}
		}
	}

	for (int i = 1; i <= N; i++)
		cout << result[i] << " ";
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M;

	for (M; M > 0; M--)
	{
		int prev, cur; cin >> prev >> cur;

		indegree[cur]++;
		v[prev].push_back(cur);
	}
}
int main()
{
	init();
	top();

	return 0;
}
