#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, E, ans;
int indegree[101],arr[101],num[3];
vector<int> adj[101];

int topological()
{
	int result[101] = { 0, }; result[1] = arr[1];
	int ind[101]; memcpy(ind, indegree, sizeof(indegree));
	queue<int> q; q.push(1);

	for (int i = 1;i <= N;i++)
	{
		if (q.empty()) break;

		int cur = q.front(); q.pop();

		for (int next : adj[cur])
		{
			bool flag = false;
			for (int k = 0;k < K;k++)
			{
				if (next == num[k])
				{
					flag = true; break;
				}
			}
			if(!flag)
				result[next] = max(result[next], result[cur] + arr[next]);
			else
				result[next] = max(result[next], result[cur]);

			if (--ind[next] == 0) q.push(next);
		}
	}

	return result[E];
}
void combination(int idx,int cnt)
{
	if (cnt == K)
	{
		int res = topological();
		ans = (ans > res) ? res : ans;

		return;
	}
	if (idx > N) return;

	combination(idx + 1, cnt);
	if (idx != E)
	{
		num[cnt] = idx;
		combination(idx + 1, cnt + 1);
	}
}
void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M; cin >> N >> M >> K;
	for (int i = 1;i <= N;i++) cin >> arr[i];

	for (int i = 0;i < M;i++)
	{
		int prev, cur; cin >> prev >> cur;
		indegree[cur]++;
		adj[prev].push_back(cur);
	}
	for (int i = 1;i <= N;i++) if (adj[i].size() == 0) { E = i; break; }
	ans = 987654321;
}
void solution()
{
	init();
	combination(2, 0);
	
	cout << ans;
}
int main()
{
	solution();

	return 0;
}
